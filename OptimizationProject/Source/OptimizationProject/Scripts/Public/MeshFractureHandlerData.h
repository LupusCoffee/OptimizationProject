#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MeshFractureHandlerData.generated.h"


class UGeometryCollection;

UCLASS(BlueprintType)
class OPTIMIZATIONPROJECT_API UMeshFractureHandlerData : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION()
	bool UsesPooling();
	
	UFUNCTION()
	int GetPoolSizeForResue();

	UFUNCTION()
	int GetAmountOfPreFracturedGeometryCollections();
	
	UFUNCTION()
	UGeometryCollection* GetGeometryCollectionAsset();
	
protected:
	UPROPERTY(EditDefaultsOnly)
	bool UsePooling = true;
	
	UPROPERTY(EditDefaultsOnly)
	int PoolSizeForReuse = 250;

	UPROPERTY(EditDefaultsOnly)
	int AmountOfPreFracturedGeometryCollections = 250;

	UPROPERTY(EditDefaultsOnly)
	UGeometryCollection* GeometryAsset = nullptr;
};
