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
	ASpawner();
	
protected:
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
	int SpawnAreaRandMin = -100;
	UPROPERTY(EditAnywhere)
	int SpawnAreaRandMax = 100;
	
	UPROPERTY(EditAnywhere)
	int SpawnHeight = 200;
	
	//Visible
	UPROPERTY(VisibleAnywhere)
	TArray<AActor*> SpawnedActors;

	//Non-Visible
	UPROPERTY()
	float CurrentTime = 0;

	UPROPERTY(BlueprintAssignable)
	FOnSpawn OnSpawn;

	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION()
	void SpawnActors();

	UFUNCTION()
	void SpawnActor(float SpawnCordX, float SpawnCordY);
};
