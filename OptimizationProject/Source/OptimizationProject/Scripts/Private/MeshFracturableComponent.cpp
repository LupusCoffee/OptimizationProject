#include "Scripts/Public/MeshFracturableComponent.h"
#include "GeometryCollection/GeometryCollectionComponent.h"


UMeshFracturableComponent::UMeshFracturableComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMeshFracturableComponent::BeginPlay()
{
	Super::BeginPlay();

	Mesh = GetOwner()->FindComponentByClass<UStaticMeshComponent>();

	//Set Events
	if (!Mesh || !FractureOnFracturerTagHit) return;
	Mesh->OnComponentHit.AddDynamic(this, &UMeshFracturableComponent::OnHitFracturer);
}

void UMeshFracturableComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!Mesh) return;
	LastTickVelocity = Mesh->GetComponentVelocity();
}

void UMeshFracturableComponent::OnHitFracturer(UPrimitiveComponent* HitComp, AActor* OtherActor,
                                               UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->ActorHasTag(FracturerTag))
	{
		FVector ImpulseDirection = LastTickVelocity.GetSafeNormal();
		Fracture(ImpulseDirection);
	}
}

UGeometryCollectionComponent* UMeshFracturableComponent::Fracture(FVector ImpulseDirection)
{
	if (!SwitchMeshForGeometryCollection()) return nullptr;
	
	ZeroDamageThreshold();
	
	GeometryComp->AddImpulse(ImpulseDirection * ImpulseTowardsFracturerOnFracture);

	OnFracture.Broadcast();
	
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

