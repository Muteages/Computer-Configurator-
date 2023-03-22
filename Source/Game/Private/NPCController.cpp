// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCController.h"
#include "DeliveryCharacter.h"
#include "Delegates/Delegate.h"
#include "Perception/AIPerceptionComponent.h"

ANPCController::ANPCController()
{
	NPCBehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behavior Tree Component"));
	NPCBlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard Component"));

	SetupSightConfig();
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

	NPCPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &ANPCController::OnPerception);			
}

void ANPCController::OnPerception(AActor* actor, FAIStimulus Stimulus)
{
	if (auto const ch = Cast<ADeliveryCharacter>(actor))
	{
		NPCBlackboardComponent->SetValueAsBool("IsDetectPlayer", Stimulus.WasSuccessfullySensed());
	}
}

void ANPCController::SetupSightConfig()
{
	NPCPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AI Perception Component"));

	NPCSightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));

	// params
	NPCSightConfig->SightRadius = 2000.f;
	NPCSightConfig->LoseSightRadius = NPCSightConfig->SightRadius + 200.f;
	NPCSightConfig->PeripheralVisionAngleDegrees = 90.f;
	NPCSightConfig->SetMaxAge(5.f);
	NPCSightConfig->AutoSuccessRangeFromLastSeenLocation = 100.f;
	NPCSightConfig->DetectionByAffiliation.bDetectEnemies = true;
	NPCSightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	NPCSightConfig->DetectionByAffiliation.bDetectNeutrals = true;


	// bind config to perception component
	NPCPerceptionComponent->SetDominantSense(NPCSightConfig->GetSenseImplementation());
	NPCPerceptionComponent->ConfigureSense(*NPCSightConfig);
}
