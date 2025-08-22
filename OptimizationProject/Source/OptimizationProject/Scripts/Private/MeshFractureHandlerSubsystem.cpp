#include "Scripts/Public/MeshFractureHandlerSubsystem.h"
#include "Scripts/Public/PerformanceCounterSubsystem.h"
#include "Scripts/Public/PerfProjGameInstance.h"

void UMeshFractureHandlerSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);

	PerformanceCounter = GetWorld()->GetSubsystem<UPerformanceCounterSubsystem>();

	InitData();

	//TODO: spawn pre-fractured geometry collections 
	/*for (int i = 0; i < PreFracturedGeometryCollections; ++i)
		SpawnGeometryCollection(0,0, -1900);*/
}

void UMeshFractureHandlerSubsystem::InitData()
{
	UMeshFractureHandlerData* Data = GetWorld()->GetGameInstance<UPerfProjGameInstance>()->GetMeshFractureHandlerData();

	UsePooling = Data->UsesPooling();
	PoolSizeForReuse = Data->GetPoolSizeForResue();
	AmountOfPreFracturedGeometryCollections = Data->GetAmountOfPreFracturedGeometryCollections();
	GeometryAsset = Data->GetGeometryCollectionAsset();
}

void UMeshFractureHandlerSubsystem::SpawnGeometryCollection(float SpawnCordX, float SpawnCordY, float SpawnCordZ)
{
	//TODO: spawn pre-fractured geometry collections

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
	if (!UsePooling) return false;
	if (PoolSizeForReuse <= 0) return false;
	if (FracturedGeometryCollections.Num() <= PoolSizeForReuse) return false;
	
	return true;
}