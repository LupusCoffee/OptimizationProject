#include "Scripts/Public/PerformanceCounterSubsystem.h"
#include "ProfilingDebugging/CountersTrace.h"
#if UE_TRACE_ENABLED
#include "Trace/Trace.h"
TRACE_DECLARE_INT_COUNTER(CupStaticMeshes,        TEXT("Cup Static Meshes"));
TRACE_DECLARE_INT_COUNTER(UnfracturedCupGeoColls, TEXT("Unfractured Cup GCs"));
TRACE_DECLARE_INT_COUNTER(FracturedCupGeoColls,   TEXT("Fractured Cup GCs"));
#endif


void UPerformanceCounterSubsystem::AddCupStaticMeshes(int Value)
{
	CupStaticMeshes += Value;

#if UE_TRACE_ENABLED
	TRACE_COUNTER_SET(CupStaticMeshes, CupStaticMeshes);
#endif

	if (CupStaticMeshes > 500 && CupStaticMeshes < 505)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, "500 CupStaticMeshes");

	if (CupStaticMeshes > 1000 && CupStaticMeshes < 1005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, "1000 CupStaticMeshes");

	if (CupStaticMeshes > 1500 && CupStaticMeshes < 1505)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, "1500 CupStaticMeshes");
}

void UPerformanceCounterSubsystem::RemoveCupStaticMeshes(int Value)
{
	CupStaticMeshes -= Value;

#if UE_TRACE_ENABLED
	TRACE_COUNTER_SET(CupStaticMeshes, CupStaticMeshes);
#endif
}

void UPerformanceCounterSubsystem::AddUnfracturedCupGeoColls(int Value)
{
	UnfracturedCupGeoColls += Value;

#if UE_TRACE_ENABLED
	TRACE_COUNTER_SET(UnfracturedCupGeoColls, UnfracturedCupGeoColls);
#endif

	if (UnfracturedCupGeoColls > 500 && UnfracturedCupGeoColls < 505)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, "500 UnfracturedCupGeoColls");

	if (UnfracturedCupGeoColls > 1000 && UnfracturedCupGeoColls < 1005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, "1000 UnfracturedCupGeoColls");

	if (UnfracturedCupGeoColls > 1500 && UnfracturedCupGeoColls < 1505)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, "1500 UnfracturedCupGeoColls");
}

void UPerformanceCounterSubsystem::RemoveUnfracturedCupGeoColls(int Value)
{
	UnfracturedCupGeoColls -= Value;

#if UE_TRACE_ENABLED
	TRACE_COUNTER_SET(UnfracturedCupGeoColls, UnfracturedCupGeoColls);
#endif
}

void UPerformanceCounterSubsystem::AddFracturedCupGeoColls(int Value)
{
	FracturedCupGeoColls += Value;

#if UE_TRACE_ENABLED
	TRACE_COUNTER_SET(FracturedCupGeoColls, FracturedCupGeoColls);
#endif

	if (FracturedCupGeoColls > 500 && FracturedCupGeoColls < 505)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "500 FracturedCupGeoColls");

	if (FracturedCupGeoColls > 1000 && FracturedCupGeoColls < 1005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "1000 FracturedCupGeoColls");

	if (FracturedCupGeoColls > 1500 && FracturedCupGeoColls < 1505)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "1500 FracturedCupGeoColls");
}

void UPerformanceCounterSubsystem::RemoveFracturedCupGeoColls(int Value)
{
	FracturedCupGeoColls -= Value;

#if UE_TRACE_ENABLED
	TRACE_COUNTER_SET(FracturedCupGeoColls, FracturedCupGeoColls);
#endif
}
