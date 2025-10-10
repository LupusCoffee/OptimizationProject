#include "Scripts/Public/ExposedGeometryCollection.h"
#include "GeometryCollection/GeometryCollectionComponent.h"


//Constructor
AExposedGeometryCollection::AExposedGeometryCollection()
{
	PrimaryActorTick.bCanEverTick = true;

	GeometryComp = CreateDefaultSubobject<UGeometryCollectionComponent>("GeometryCollectionComp");
}

void AExposedGeometryCollection::Init(UGeometryCollection* Asset)
{
	GeometryComp->SetRestCollection(Asset);
}


//Core Overrides
void AExposedGeometryCollection::BeginPlay()
{
	Super::BeginPlay();
	
}

void AExposedGeometryCollection::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}


//External Methods



//Delegates
void AExposedGeometryCollection::OnHitSurface()
{
	
}


//Internal Methods
void AExposedGeometryCollection::PushTowardsSurface()
{
	
}
