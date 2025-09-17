#pragma once


#include "CoreMinimal.h"
#include "MeshFractureHandlerData.h"
#include "Subsystems/WorldSubsystem.h"
#include "MeshFractureHandlerSubsystem.generated.h"
class UPerformanceCounterSubsystem;
class UGeometryCollection;


UCLASS()
class OPTIMIZATIONPROJECT_API UMeshFractureHandlerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

	
public:
	//Internal Methods
	UFUNCTION()
	void AddFracturedGeoColl(UGeometryCollectionComponent* GeoColl);
	
	UFUNCTION()
	UGeometryCollectionComponent* GetFracturedGeoColl();

	UFUNCTION()
	bool CanReuseFracturedGeoColls();

	
protected:
	//Core Overrides
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;


	//Internal Variables
	UPROPERTY()
	UPerformanceCounterSubsystem* PerformanceCounter = nullptr;

	//todo: the following seven variables need to be part of a struct --> make a map with each type of geometry collection
	UPROPERTY()
	TArray<UGeometryCollectionComponent*> FracturedGeometryCollections; //todo: make into map, one for each type
	
	UPROPERTY()
	int LastUsedGeoCollIndex = 0;										//todo: make into map, one for each type

	
	//Data-Asset-Set Variables											//todo: make into map, one for each type
	UPROPERTY()
	bool UsePooling = true;
	
	UPROPERTY()
	int PoolSizeForReuse = 250;

	UPROPERTY()
	int AmountOfPreFracturedGeometryCollections = 250;

	UPROPERTY()
	UGeometryCollection* GeometryAsset = nullptr;


	//Internal Methods
	UFUNCTION()
	void InitData();
	
	UFUNCTION()
	void SpawnPreFracturedGeometryCollection(float SpawnCordX, float SpawnCordY, float SpawnCordZ);
};
