#pragma once


#include "CoreMinimal.h"
#include "ChaosBlueprint.h"
#include "Components/ActorComponent.h"
#include "PerformanceCounterSubsystem.h"
#include "Chaos/ChaosEngineInterface.h"
#include "MeshFracturableComponent.generated.h"
class UGeometryCollection;


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFracture);


UENUM(BlueprintType)
enum class ECupState : uint8
{
	StaticMesh,
	GC_Unfractured,
	GC_Fractured_ActivePhysAndCol,
	GC_Fractured_DeactivePhysAndCol
};


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OPTIMIZATIONPROJECT_API UMeshFracturableComponent : public UActorComponent
{
	GENERATED_BODY()

	
public:
	UMeshFracturableComponent();

	
	UFUNCTION(BlueprintCallable, Category = "MeshBreakableComponent")
	UGeometryCollectionComponent* Fracture(FVector ImpulseDirection);

	UFUNCTION(BlueprintCallable, Category = "MeshBreakableComponent")
	bool SwitchMeshForGeometryCollection();

	UFUNCTION(BlueprintCallable, Category = "MeshBreakableComponent")
	void SetGeometryPhysicsAndCollisionStatus(bool IsEnabled);

	
protected:
	virtual void BeginPlay() override;
	virtual void OnUnregister() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
	//Non-Editor Properties
	UPROPERTY()
	UPerformanceCounterSubsystem* PerformanceCounter = nullptr;

	UPROPERTY()
	ECupState CupState = ECupState::StaticMesh;
	
	UPROPERTY()
	UStaticMeshComponent* Mesh = nullptr;

	UPROPERTY()
	FVector LastTickVelocity = FVector::ZeroVector;
	
	UPROPERTY()
	UGeometryCollectionComponent* GeometryComp = nullptr;

	UPROPERTY()
	UChaosDestructionListener* ChaosListener = nullptr;
	
	UPROPERTY()
	float ActivePhysColTimeAfterFracture = 0;

	UPROPERTY(BlueprintAssignable)
	FOnFracture OnFracture;
	
	
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

	UPROPERTY(EditDefaultsOnly)
	float TimeToDisablePhysColAfterFracture = 10.0f;


	//Methods
	UFUNCTION()
	void ZeroDamageThreshold();

	UFUNCTION()
	void DisabledPhysicsAndCollision();
	

	//Events
	UFUNCTION()
	void OnHitFracturer(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		FVector NormalImpulse, const FHitResult& Hit);
	
	UFUNCTION()
	void OnFractured(const FChaosBreakEvent& BreakEvent);
};
