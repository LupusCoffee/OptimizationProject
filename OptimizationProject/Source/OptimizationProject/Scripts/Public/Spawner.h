#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class OPTIMIZATIONPROJECT_API ASpawner : public AActor
{
	GENERATED_BODY()

public:
	ASpawner();

	//Edit
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ActorToSpawnAsset;

	UPROPERTY(EditAnywhere)
	int AmountToSpawn = 0;

	UPROPERTY(EditAnywhere)
	float WidthBetweenSpawnLocations = 100;
	
	UPROPERTY(EditAnywhere, meta = (ToolTip = "2D Dimensions of Spawn Area"))
	int SpawnAreaX = 0;
	UPROPERTY(EditAnywhere, meta = (ToolTip = "2D Dimensions of Spawn Area"))
	int SpawnAreaY = 0;

	UPROPERTY(EditAnywhere)
	int SpawnHeight = 200;

	//Visible
	UPROPERTY(VisibleAnywhere)
	TArray<AActor*> SpawnedActors;
	
protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void SpawnActors();

	UFUNCTION()
	void SpawnActor(float SpawnCordX, float SpawnCordY);
};
