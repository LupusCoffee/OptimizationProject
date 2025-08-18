#pragma once


#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MeshFracturableComponent.generated.h"
class UGeometryCollection;


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFracture);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OPTIMIZATIONPROJECT_API UMeshFracturableComponent : public UActorComponent
{
	GENERATED_BODY()

	
public:
	UMeshFracturableComponent();

	
	UPROPERTY(BlueprintAssignable, Category = "MeshBreakableComponent")
	FOnFracture OnFracture;

	
	UFUNCTION(BlueprintCallable, Category = "MeshBreakableComponent")
	UGeometryCollectionComponent* Fracture(FVector ImpulseDirection);

	UFUNCTION(BlueprintCallable, Category = "MeshBreakableComponent")
	bool SwitchMeshForGeometryCollection();

	
protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
	//Non-Editor Properties
	UPROPERTY()
	UStaticMeshComponent* Mesh = nullptr;
	
	UPROPERTY()
	UGeometryCollectionComponent* GeometryComp = nullptr;

	UPROPERTY()
	FVector LastTickVelocity = FVector::ZeroVector;

	
	//Editor Properties
	UPROPERTY(EditDefaultsOnly)
	bool FractureOnFracturerTagHit = true;
	
	UPROPERTY(EditDefaultsOnly)
	FName FracturerTag = "Fracturer";
	
	UPROPERTY(EditDefaultsOnly)
	UGeometryCollection* GeometryAsset = nullptr;
	
	UPROPERTY(EditDefaultsOnly, meta = (ToolTip = "Multiplier set on the velocity transfered from the static mesh to the newly created geometry collection."))
	float TransferedLinearVelocityMultiplierOnFracture = 5.0;

	UPROPERTY(EditDefaultsOnly, meta = (ToolTip = "Impulse on the geometry collection directed towards the actor that fractured, when the geo col fractures."))
	float ImpulseTowardsFracturerOnFracture = 6000;

	
	UFUNCTION()
	void OnHitFracturer(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void ZeroDamageThreshold();
};
