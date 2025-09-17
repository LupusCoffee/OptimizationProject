#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExposedGeometryCollection.generated.h"


class UGeometryCollection;

UCLASS(Blueprintable)
class OPTIMIZATIONPROJECT_API AExposedGeometryCollection : public AActor
{
	GENERATED_BODY()

public:
	//Constructor
	AExposedGeometryCollection();

	
	//External Methods
	UFUNCTION(BlueprintCallable)
	void SetAsset(UGeometryCollection* Asset);

protected:
	//Core Overrides
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	
	//Internal Variables
	UPROPERTY()
	UGeometryCollectionComponent* GeometryComp = nullptr;


	//Delegates
	UFUNCTION()
	void OnHitSurface();

	
	//Internal Methods
	UFUNCTION()
	void PushTowardsSurface();
};
