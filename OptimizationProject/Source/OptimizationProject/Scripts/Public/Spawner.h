#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpawn, AActor*, Actor);


UCLASS()
class OPTIMIZATIONPROJECT_API ASpawner : public AActor
{
	GENERATED_BODY()

public:
	//Constructor
	ASpawner();

	
	//Delegates
	UPROPERTY(BlueprintAssignable)
	FOnSpawn OnSpawn;

	
protected:
	//Core Overrides
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	
	//Edit
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ActorToSpawnAsset;

	UPROPERTY(EditAnywhere)
	float SpawnFrequency = 10;

	UPROPERTY(EditAnywhere)
	float WidthBetweenSpawnLocations = 100;
	
	UPROPERTY(EditAnywhere, meta = (ToolTip = "2D Dimensions of Spawn Area"))
	int SpawnAreaX = 0;
	
	UPROPERTY(EditAnywhere, meta = (ToolTip = "2D Dimensions of Spawn Area"))
	int SpawnAreaY = 0;
	
	UPROPERTY(EditAnywhere)
	int SpawnHeight = 200;

	UPROPERTY(EditAnywhere)
	int SpawnAreaRandMin = -100;
	
	UPROPERTY(EditAnywhere)
	int SpawnAreaRandMax = 100;

	
	//Visible
	UPROPERTY(VisibleAnywhere)
	TArray<AActor*> SpawnedActors;

	
	//Internal
	UPROPERTY()
	float CurrentTime = 0;
	

	//Internal Methods
	UFUNCTION()
	void SpawnActors();

	UFUNCTION()
	void SpawnActor(float SpawnCordX, float SpawnCordY);
};
