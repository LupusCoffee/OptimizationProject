#include "Scripts/Public/Spawner.h"

#include "Rendering/CustomRenderPass.h"


ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ASpawner::BeginPlay()
{
	Super::BeginPlay();

	if (!ActorToSpawnAsset) return; //shouldn't actually be here, but whatever for now
	SpawnActors();
}

void ASpawner::SpawnActors()
{
	for (int x = 0; x < SpawnAreaX; x++)
	{
		for (int y = 0; y < SpawnAreaY; y++)
		{
			if (SpawnedActors.Num() >= AmountToSpawn) break;
			SpawnActor(x * WidthBetweenSpawnLocations, y * WidthBetweenSpawnLocations);
		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green,
		FString::Printf(TEXT("Spawned %d actors!"), SpawnedActors.Num()));
}

void ASpawner::SpawnActor(float SpawnCordX, float SpawnCordY)
{
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = this;
	SpawnParameters.Instigator = GetInstigator();

	FVector Location = FVector(SpawnCordX, SpawnCordY, SpawnHeight);
	FRotator Rotation = FRotator(0, 0, 0);

	AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorToSpawnAsset, Location, Rotation);
	if (SpawnedActor) SpawnedActors.Add(SpawnedActor);
}

