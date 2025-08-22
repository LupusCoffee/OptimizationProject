// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MeshFractureHandlerData.h"
#include "Engine/GameInstance.h"
#include "PerfProjGameInstance.generated.h"

UCLASS(Blueprintable)
class OPTIMIZATIONPROJECT_API UPerfProjGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION()
	UMeshFractureHandlerData* GetMeshFractureHandlerData();

protected:
	UPROPERTY(EditAnywhere)
	UMeshFractureHandlerData* MeshFractureHandlerData;
};
