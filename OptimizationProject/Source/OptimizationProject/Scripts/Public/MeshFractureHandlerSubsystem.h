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
	//Methods
	UFUNCTION()
	void InitData();
	
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
	UPerformanceCounterSubsystem* PerformanceCounterSubsystem;

	UPROPERTY()
	UPerformanceCounterSubsystem* PerformanceCounter = nullptr;

	UPROPERTY()
	TArray<UGeometryCollectionComponent*> FracturedGeometryCollections;
	
	UPROPERTY()
	int LastUsedGeoCollIndex = 0;

	
	//Variables Set By Data Asset
	UPROPERTY()
	bool UsePooling = true;
	
	UPROPERTY()
	int PoolSizeForReuse = 250;

	UPROPERTY()
	int AmountOfPreFracturedGeometryCollections = 250;

	UPROPERTY()
	UGeometryCollection* GeometryAsset = nullptr;


	//pre broken geo coll amount -> for each chosen mesh fracturable actor
	//max pool size -> for each chosen mesh fracturable actor

	//in data, simply set for whichever mesh fracturable actor ya want


	//Methods
	UFUNCTION()
	void SpawnGeometryCollection(float SpawnCordX, float SpawnCordY, float SpawnCordZ);
};
