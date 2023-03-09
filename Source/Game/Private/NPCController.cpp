// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCController.h"

ANPCController::ANPCController()
{
	NPCBehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behavior Tree Component"));
	NPCBlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard Component"));
}

void ANPCController::BeginPlay()
{
	Super::BeginPlay();


	// Run behavior tree component
	if (IsValid(NPCBehaviorTree.Get()))
	{	
		RunBehaviorTree(NPCBehaviorTree.Get());
		NPCBehaviorTreeComponent->StartTree(*NPCBehaviorTree.Get());
	}
}

void ANPCController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (IsValid(NPCBlackboardComponent.Get()) && IsValid(NPCBehaviorTree.Get()))
	{
		NPCBlackboardComponent->InitializeBlackboard((*NPCBehaviorTree.Get()->BlackboardAsset.Get()));
	}
}
