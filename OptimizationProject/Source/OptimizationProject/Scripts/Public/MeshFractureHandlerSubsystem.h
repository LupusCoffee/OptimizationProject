#pragma once


#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "MeshFractureHandlerSubsystem.generated.h"
class UPerformanceCounterSubsystem;
class UGeometryCollection;

UCLASS()
class OPTIMIZATIONPROJECT_API UMeshFractureHandlerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	//Methods
	UFUNCTION()
	void AddFracturedGeoColl(UGeometryCollectionComponent* GeoColl);
	
	UFUNCTION()
	UGeometryCollectionComponent* GetFracturedGeoColl();

	UFUNCTION()
	bool CanReuseFracturedGeoColls();

	
protected:
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;

	//Variables
	UPROPERTY()
	UPerformanceCounterSubsystem* PerformanceCounter = nullptr;
	
	UPROPERTY()
	TArray<UGeometryCollectionComponent*> FracturedGeometryCollections;
	
	UPROPERTY()
	int PoolSizeForReuse = 500;

	UPROPERTY()
	int PreFracturedGeometryCollections = 1000;

	UPROPERTY()
	UGeometryCollection* GeometryAsset = nullptr;

	UPROPERTY()
	int LastUsedGeoCollIndex = 0;
	
	//pre broken geo coll amount -> for each chosen mesh fracturable actor
	//max pool size -> for each chosen mesh fracturable actor

	//in data, simply set for whichever mesh fracturable actor ya want


	//Methods
	UFUNCTION()
	void SpawnGeometryCollection(float SpawnCordX, float SpawnCordY, float SpawnCordZ);
};
