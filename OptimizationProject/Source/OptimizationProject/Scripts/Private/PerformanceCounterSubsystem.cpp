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

	if (CupStaticMeshes > 1500)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "Stop Debugging");
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

	if (UnfracturedCupGeoColls > 1500)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "Stop Debugging");
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

	if (FracturedCupGeoColls > 1500)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "Stop Debugging");
}

void UPerformanceCounterSubsystem::RemoveFracturedCupGeoColls(int Value)
{
	FracturedCupGeoColls -= Value;

#if UE_TRACE_ENABLED
	TRACE_COUNTER_SET(FracturedCupGeoColls, FracturedCupGeoColls);
#endif
}
