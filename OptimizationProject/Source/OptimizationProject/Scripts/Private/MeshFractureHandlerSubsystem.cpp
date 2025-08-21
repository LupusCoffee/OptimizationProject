#include "Scripts/Public/MeshFractureHandlerSubsystem.h"
#include "GeometryCollection/GeometryCollectionComponent.h"
#include "Scripts/Public/PerformanceCounterSubsystem.h"

void UMeshFractureHandlerSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);

	PerformanceCounter = GetWorld()->GetSubsystem<UPerformanceCounterSubsystem>();

	//set initial stuff based on mesh fracture handler data

	/*for (int i = 0; i < PreFracturedGeometryCollections; ++i)
		SpawnGeometryCollection(0,0, -1900);*/
}

void UMeshFractureHandlerSubsystem::SpawnGeometryCollection(float SpawnCordX, float SpawnCordY, float SpawnCordZ)
{
	/*UGeometryCollectionComponent* GeometryComp = NewObject<UGeometryCollectionComponent>(this);
	if (!GeometryComp) return;
	
	GeometryComp->SetRestCollection(GeometryAsset);

	GeometryComp->SetWorldLocation(FVector(SpawnCordX, SpawnCordY, SpawnCordZ));
	
	GeometryComp->RegisterComponent();
	GeometryComp->SetSimulatePhysics(true);
	GeometryComp->SetNotifyRigidBodyCollision(true);
	GeometryComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	GeometryComp->SetNotifyBreaks(true);
	GeometryComp->OnChaosBreakEvent.AddDynamic(this, &UMeshFracturableComponent::OnFractured); //as soon as they have fractured, we turn off collision and physics
	
	PerformanceCounter->AddPhysColActiveFracturedCupGeoColls()*/
}

void UMeshFractureHandlerSubsystem::AddFracturedGeoColl(UGeometryCollectionComponent* GeoColl)
{
	if (FracturedGeometryCollections.Contains(GeoColl)) return;

	FracturedGeometryCollections.Add(GeoColl);
}

UGeometryCollectionComponent* UMeshFractureHandlerSubsystem::GetFracturedGeoColl()
{
	LastUsedGeoCollIndex++;
	
	if (LastUsedGeoCollIndex >= FracturedGeometryCollections.Num()) LastUsedGeoCollIndex = 0;
	
	return FracturedGeometryCollections[LastUsedGeoCollIndex];
}

bool UMeshFractureHandlerSubsystem::CanReuseFracturedGeoColls()
{
	if (FracturedGeometryCollections.Num() > PoolSizeForReuse) return true;
	
	return false;
}