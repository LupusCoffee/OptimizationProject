#include "Scripts/Public/PerformanceCounterSubsystem.h"
#include "ProfilingDebugging/CountersTrace.h"

#if UE_TRACE_ENABLED
#include "Trace/Trace.h"
TRACE_DECLARE_INT_COUNTER(CupStaticMeshes,							TEXT("Cup Static Meshes"));
TRACE_DECLARE_INT_COUNTER(UnfracturedCupGeoColls,					TEXT("Unfractured Cup GCs"));
TRACE_DECLARE_INT_COUNTER(PhysColActiveFracturedCupGeoColls,		TEXT("PhysCol-Active Fractured Cup GCs"));
TRACE_DECLARE_INT_COUNTER(PhysColDeactiveFracturedCupGeoColls,		TEXT("PhysCol-Deactive Fractured Cup GCs"));
#endif


void UPerformanceCounterSubsystem::AddCupStaticMeshes(int Value)
{
	CupStaticMeshes += Value;

#if UE_TRACE_ENABLED
	TRACE_COUNTER_SET(CupStaticMeshes, CupStaticMeshes);
#endif

	if (CupStaticMeshes > 500 && CupStaticMeshes < 505)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, "500 CupStaticMeshes");

	if (CupStaticMeshes > 1000 && CupStaticMeshes < 1005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, "1000 CupStaticMeshes");

	if (CupStaticMeshes > 1500 && CupStaticMeshes < 1505)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, "1500 CupStaticMeshes");

	if (CupStaticMeshes > 2000 && CupStaticMeshes < 2005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, "2000 CupStaticMeshes");

	if (CupStaticMeshes > 3000 && CupStaticMeshes < 3005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, "3000 CupStaticMeshes");

	if (CupStaticMeshes > 4000 && CupStaticMeshes < 4005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, "4000 CupStaticMeshes");
	
	if (CupStaticMeshes > 5000 && CupStaticMeshes < 5005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, "5000 CupStaticMeshes");
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
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, "500 UnfracturedCupGeoColls");

	if (UnfracturedCupGeoColls > 1000 && UnfracturedCupGeoColls < 1005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, "1000 UnfracturedCupGeoColls");

	if (UnfracturedCupGeoColls > 1500 && UnfracturedCupGeoColls < 1505)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, "1500 UnfracturedCupGeoColls");

	if (UnfracturedCupGeoColls > 2000 && UnfracturedCupGeoColls < 2005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, "2000 UnfracturedCupGeoColls");

	if (UnfracturedCupGeoColls > 3000 && UnfracturedCupGeoColls < 3005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, "3000 UnfracturedCupGeoColls");

	if (UnfracturedCupGeoColls > 4000 && UnfracturedCupGeoColls < 4005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, "4000 UnfracturedCupGeoColls");
	
	if (UnfracturedCupGeoColls > 5000 && UnfracturedCupGeoColls < 5005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, "5000 UnfracturedCupGeoColls");
}

void UPerformanceCounterSubsystem::RemoveUnfracturedCupGeoColls(int Value)
{
	UnfracturedCupGeoColls -= Value;

#if UE_TRACE_ENABLED
	TRACE_COUNTER_SET(UnfracturedCupGeoColls, UnfracturedCupGeoColls);
#endif
}

void UPerformanceCounterSubsystem::AddPhysColActiveFracturedCupGeoColls(int Value)
{
	PhysColActiveFracturedCupGeoColls += Value;

#if UE_TRACE_ENABLED
	TRACE_COUNTER_SET(PhysColActiveFracturedCupGeoColls, PhysColActiveFracturedCupGeoColls);
#endif

	if (PhysColActiveFracturedCupGeoColls > 500 && PhysColActiveFracturedCupGeoColls < 505)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, "500 PhysColActiveFracturedCupGeoColls");

	if (PhysColActiveFracturedCupGeoColls > 1000 && PhysColActiveFracturedCupGeoColls < 1005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, "1000 PhysColActiveFracturedCupGeoColls");

	if (PhysColActiveFracturedCupGeoColls > 1500 && PhysColActiveFracturedCupGeoColls < 1505)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, "1500 PhysColActiveFracturedCupGeoColls");

	if (PhysColActiveFracturedCupGeoColls > 2000 && PhysColActiveFracturedCupGeoColls < 2005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, "2000 PhysColActiveFracturedCupGeoColls");

	if (PhysColActiveFracturedCupGeoColls > 3000 && PhysColActiveFracturedCupGeoColls < 3005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, "3000 PhysColActiveFracturedCupGeoColls");

	if (PhysColActiveFracturedCupGeoColls > 4000 && PhysColActiveFracturedCupGeoColls < 4005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, "4000 PhysColActiveFracturedCupGeoColls");
	
	if (PhysColActiveFracturedCupGeoColls > 5000 && PhysColActiveFracturedCupGeoColls < 5005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, "5000 PhysColActiveFracturedCupGeoColls");
}

void UPerformanceCounterSubsystem::RemovePhysColActiveFracturedCupGeoColls(int Value)
{
	PhysColActiveFracturedCupGeoColls -= Value;

#if UE_TRACE_ENABLED
	TRACE_COUNTER_SET(PhysColActiveFracturedCupGeoColls, PhysColActiveFracturedCupGeoColls);
#endif
}

void UPerformanceCounterSubsystem::AddPhysColDeactiveFracturedCupGeoColls(int Value)
{
	PhysColDeactiveFracturedCupGeoColls += Value;

#if UE_TRACE_ENABLED
	TRACE_COUNTER_SET(PhysColDeactiveFracturedCupGeoColls, PhysColDeactiveFracturedCupGeoColls);
#endif
	
	if (PhysColDeactiveFracturedCupGeoColls > 500 && PhysColDeactiveFracturedCupGeoColls < 505)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "500 PhysColDeactiveFracturedCupGeoColls");

	if (PhysColDeactiveFracturedCupGeoColls > 1000 && PhysColDeactiveFracturedCupGeoColls < 1005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "1000 PhysColDeactiveFracturedCupGeoColls");

	if (PhysColDeactiveFracturedCupGeoColls > 1500 && PhysColDeactiveFracturedCupGeoColls < 1505)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "1500 PhysColDeactiveFracturedCupGeoColls");

	if (PhysColDeactiveFracturedCupGeoColls > 2000 && PhysColDeactiveFracturedCupGeoColls < 2005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "2000 PhysColDeactiveFracturedCupGeoColls");

	if (PhysColDeactiveFracturedCupGeoColls > 3000 && PhysColDeactiveFracturedCupGeoColls < 3005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "3000 PhysColDeactiveFracturedCupGeoColls");

	if (PhysColDeactiveFracturedCupGeoColls > 4000 && PhysColDeactiveFracturedCupGeoColls < 4005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "4000 PhysColDeactiveFracturedCupGeoColls");
	
	if (PhysColDeactiveFracturedCupGeoColls > 5000 && PhysColDeactiveFracturedCupGeoColls < 5005)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "5000 PhysColDeactiveFracturedCupGeoColls");
}

void UPerformanceCounterSubsystem::RemovePhysColDeactiveFracturedCupGeoColls(int Value)
{
	PhysColDeactiveFracturedCupGeoColls -= Value;

#if UE_TRACE_ENABLED
	TRACE_COUNTER_SET(PhysColDeactiveFracturedCupGeoColls, PhysColDeactiveFracturedCupGeoColls);
#endif
}
