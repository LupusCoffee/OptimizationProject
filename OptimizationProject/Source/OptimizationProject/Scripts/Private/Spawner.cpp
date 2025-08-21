#include "Scripts/Public/Spawner.h"


ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	CurrentTime = SpawnFrequency;
}

void ASpawner::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (CurrentTime < SpawnFrequency)
	{
		CurrentTime += DeltaSeconds;
		return;
	}
	
	if (!ActorToSpawnAsset) return;
	SpawnActors();
	CurrentTime = 0.0f;
}

void ASpawner::SpawnActors()
{
	for (int x = 0; x < SpawnAreaX; x++)
	{
		for (int y = 0; y < SpawnAreaY; y++)
		{
			SpawnActor(
				x * WidthBetweenSpawnLocations + FMath::RandRange(SpawnAreaRandMin, SpawnAreaRandMax),
				y * WidthBetweenSpawnLocations + FMath::RandRange(SpawnAreaRandMin, SpawnAreaRandMax)
			);
		}
	}
}

void ASpawner::SpawnActor(float SpawnCordX, float SpawnCordY)
{
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = this;
	SpawnParameters.Instigator = GetInstigator();

	FVector Location = FVector(SpawnCordX, SpawnCordY, SpawnHeight);
	FRotator Rotation = FRotator(0, 0, 0);

	AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorToSpawnAsset, Location, Rotation);
	if (!SpawnedActor) return;

	SpawnedActors.Add(SpawnedActor);
	OnSpawn.Broadcast(SpawnedActor);
}

