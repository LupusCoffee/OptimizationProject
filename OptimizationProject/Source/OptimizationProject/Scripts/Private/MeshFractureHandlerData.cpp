#include "Scripts/Public/MeshFractureHandlerData.h"

bool UMeshFractureHandlerData::UsesPooling()
{
	return UsePooling;
}

int UMeshFractureHandlerData::GetPoolSizeForResue()
{
	return PoolSizeForReuse;
}

int UMeshFractureHandlerData::GetAmountOfPreFracturedGeometryCollections()
{
	return AmountOfPreFracturedGeometryCollections;
}

UGeometryCollection* UMeshFractureHandlerData::GetGeometryCollectionAsset()
{
	return GeometryAsset;
}
