// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindRandomLocation.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

UBTTask_FindRandomLocation::UBTTask_FindRandomLocation()
{
	NodeName = TEXT("Find Random Location");

	//Make a filter: only accpet Vector type
	BlackboardKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(
	UBTTask_FindRandomLocation, BlackboardKey));
}

EBTNodeResult::Type UBTTask_FindRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	FNavLocation Location{};

	//get AI pawn
	AAIController* NPCController{ OwnerComp.GetAIOwner() };
	const APawn* AIPawn{ NPCController->GetPawn() };

	//get pawn origin
	const FVector OriginLocation{ AIPawn->GetActorLocation() };

	// navigation system, find random location
	const UNavigationSystemV1* NavSystem{ UNavigationSystemV1::GetCurrent(GetWorld()) };
	if (IsValid(NavSystem) && NavSystem->GetRandomPointInNavigableRadius(OriginLocation, SearchRange, Location))
	{
		NPCController->GetBlackboardComponent()->SetValueAsVector(BlackboardKey.SelectedKeyName, Location);
	}

	// finish the task with success
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}

FString UBTTask_FindRandomLocation::GetStaticDescription() const
{
	return FString::Printf(TEXT("Vector: %s"), *BlackboardKey.SelectedKeyName.ToString());
}
