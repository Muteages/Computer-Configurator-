// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBTTask_SightPerception.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

UMyBTTask_SightPerception::UMyBTTask_SightPerception()
{
	NodeName = TEXT("Sight Perception");

	//Make a filter: only accept Vector type
	BlackboardKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(
		UMyBTTask_SightPerception, BlackboardKey));
}

EBTNodeResult::Type UMyBTTask_SightPerception::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// get AI controller
	AAIController* NPCController{ OwnerComp.GetAIOwner() };

	// get player character
	const ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	// get player location
	const FVector PlayerLocation = Player->GetActorLocation();
	
	// navigation system
	const UNavigationSystemV1* NavSystem{ UNavigationSystemV1::GetCurrent(GetWorld()) };
	if (IsValid(NavSystem))
	{
		NPCController->GetBlackboardComponent()->SetValueAsVector(BlackboardKey.SelectedKeyName, PlayerLocation);
	}

	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}

FString UMyBTTask_SightPerception::GetStaticDescription() const
{
	return FString::Printf(TEXT("Vector: %s"), *BlackboardKey.SelectedKeyName.ToString());
}
