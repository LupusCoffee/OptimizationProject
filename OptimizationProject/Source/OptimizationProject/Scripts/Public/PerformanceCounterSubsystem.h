#pragma once


#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "PerformanceCounterSubsystem.generated.h"


UCLASS()
class OPTIMIZATIONPROJECT_API UPerformanceCounterSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void AddCupStaticMeshes(int Value);
	UFUNCTION()
	void RemoveCupStaticMeshes(int Value);

	UFUNCTION()
	void AddUnfracturedCupGeoColls(int Value);
	UFUNCTION()
	void RemoveUnfracturedCupGeoColls(int Value);

	UFUNCTION()
	void AddFracturedCupGeoColls(int Value);
	UFUNCTION()
	void RemoveFracturedCupGeoColls(int Value);
	
private:
	/*virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	/*virtual void Deinitialize() override;#1#

	UPROPERTY()
	uint64 StartCycles = 0;*/
	
	UPROPERTY()
	int CupStaticMeshes = 0;

	UPROPERTY()
	int UnfracturedCupGeoColls = 0;

	UPROPERTY()
	int FracturedCupGeoColls = 0;
};
