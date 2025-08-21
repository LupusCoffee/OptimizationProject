#include "Scripts/Public/MeshFracturableComponent.h"

#include "GeometryCollectionProxyData.h"
#include "GeometryCollection/GeometryCollectionComponent.h"
#include "Scripts/Public/PerformanceCounterSubsystem.h"


UMeshFracturableComponent::UMeshFracturableComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMeshFracturableComponent::BeginPlay()
{
	Super::BeginPlay();
	
	PerformanceCounter = GetWorld()->GetSubsystem<UPerformanceCounterSubsystem>();

	Mesh = GetOwner()->FindComponentByClass<UStaticMeshComponent>();
	if (Mesh) PerformanceCounter->AddCupStaticMeshes(1);

	//Set Events
	if (Mesh || FractureOnFracturerTagHit)
	{
		Mesh->OnComponentHit.AddDynamic(this, &UMeshFracturableComponent::OnHitFracturer);
	}

	//FTransform3f Transform = FTransform3f();
	//GeometryComp->GetDynamicCollection()->SetTransform(0, GeometryComp->GetComponentTransform());
}

void UMeshFracturableComponent::OnUnregister()
{
	Super::OnUnregister();
	
	if (!GeometryComp) return;

	GeometryComp->OnChaosBreakEvent.RemoveDynamic(this, &UMeshFracturableComponent::OnFractured);
        
	if (CupState == ECupState::StaticMesh) PerformanceCounter->RemoveCupStaticMeshes(1);
	else if (CupState == ECupState::GC_Unfractured) PerformanceCounter->RemoveUnfracturedCupGeoColls(1);
	else if (CupState == ECupState::GC_Fractured_ActivePhysAndCol) PerformanceCounter->RemovePhysColActiveFracturedCupGeoColls(1);
	else PerformanceCounter->RemovePhysColDeactiveFracturedCupGeoColls(1);
}

void UMeshFracturableComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
                                              FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (Mesh) LastTickVelocity = Mesh->GetComponentVelocity();

	if (CupState != ECupState::GC_Fractured_ActivePhysAndCol) return;
	if (ActivePhysColTimeAfterFracture > TimeToDisablePhysColAfterFracture)
	{
		DisabledPhysicsAndCollision();
		CupState = ECupState::GC_Fractured_DeactivePhysAndCol;
	}
	else ActivePhysColTimeAfterFracture += DeltaTime;
}


UGeometryCollectionComponent* UMeshFracturableComponent::Fracture(FVector ImpulseDirection)
{
	if (!SwitchMeshForGeometryCollection()) return nullptr;
	
	ZeroDamageThreshold();
	
	GeometryComp->AddImpulse(ImpulseDirection * ImpulseTowardsFracturerOnFracture);

	OnFracture.Broadcast();

	//GeometryComp->GetDynamicCollection()->GetAttribute<int32>()
	
	return GeometryComp;
}

bool UMeshFracturableComponent::SwitchMeshForGeometryCollection()
{
	if (!Mesh) return false;
	if (!GeometryAsset) return false;

	//destroy static mesh, save values
	USceneComponent* Parent = Mesh->GetAttachParent();
	FTransform MeshTransform = Mesh->GetComponentTransform();
	FVector LinearVel = Mesh->GetPhysicsLinearVelocity();
	Mesh->DestroyComponent();
	PerformanceCounter->RemoveCupStaticMeshes(1);

	//create geometry collection, inherit static mesh location, rotation, and velocity
	GeometryComp = NewObject<UGeometryCollectionComponent>(this);
	if (!GeometryComp) return false;
	
	GeometryComp->SetRestCollection(GeometryAsset);

	GeometryComp->SetWorldLocation(MeshTransform.GetLocation());
	GeometryComp->SetWorldRotation(MeshTransform.GetRotation());
	
	GeometryComp->AttachToComponent(Parent, FAttachmentTransformRules::KeepRelativeTransform);
	
	GeometryComp->RegisterComponent();
	GeometryComp->SetSimulatePhysics(true);
	GeometryComp->SetNotifyRigidBodyCollision(true);
	GeometryComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	GeometryComp->AddImpulse(LinearVel * TransferedLinearVelocityMultiplierOnFracture);

	GeometryComp->SetNotifyBreaks(true);
	GeometryComp->OnChaosBreakEvent.AddDynamic(this, &UMeshFracturableComponent::OnFractured);

	CupState = ECupState::GC_Unfractured;
	PerformanceCounter->AddUnfracturedCupGeoColls(1);
	
	return true;
}

void UMeshFracturableComponent::ZeroDamageThreshold()
{
	TArray<float> DamageThresholds;
	for (int i = 0; i < GeometryComp->GetDamageThreshold().Num(); ++i)
	{
		DamageThresholds.Add(0);
	}
	GeometryComp->SetDamageThreshold(DamageThresholds);
}

void UMeshFracturableComponent::DisabledPhysicsAndCollision()
{
	SetGeometryPhysicsAndCollisionStatus(false);
	PerformanceCounter->RemovePhysColActiveFracturedCupGeoColls(1);
	PerformanceCounter->AddPhysColDeactiveFracturedCupGeoColls(1);
}

void UMeshFracturableComponent::SetGeometryPhysicsAndCollisionStatus(bool IsEnabled)
{
	if (!GeometryComp) return;

	GeometryComp->SetSimulatePhysics(IsEnabled);

	if (IsEnabled) GeometryComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	else GeometryComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}


void UMeshFracturableComponent::OnHitFracturer(UPrimitiveComponent* HitComp, AActor* OtherActor,
											   UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (!OtherActor->ActorHasTag(FracturerTag)) return;
	
	FVector ImpulseDirection = LastTickVelocity.GetSafeNormal();
	Fracture(ImpulseDirection);
}

void UMeshFracturableComponent::OnFractured(const FChaosBreakEvent& BreakEvent)
{
	if (CupState == ECupState::GC_Fractured_ActivePhysAndCol) return;
	CupState = ECupState::GC_Fractured_ActivePhysAndCol;

	ActivePhysColTimeAfterFracture = 0;
	
	PerformanceCounter->RemoveUnfracturedCupGeoColls(1);
	PerformanceCounter->AddPhysColActiveFracturedCupGeoColls(1);
	
	GeometryComp->OnChaosBreakEvent.RemoveDynamic(this, &UMeshFracturableComponent::OnFractured);
}
