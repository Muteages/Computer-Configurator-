// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIModule/Classes/BehaviorTree/BehaviorTree.h"
#include "AIModule/Classes/BehaviorTree/BehaviorTreeComponent.h"
#include "AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "NPCController.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API ANPCController : public AAIController
{
	GENERATED_BODY()

public:
	ANPCController();

public:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI System|Behavior Tree")
		TObjectPtr<UBehaviorTree> NPCBehaviorTree;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI System| Behavior Tree Component")
		TObjectPtr<UBehaviorTreeComponent> NPCBehaviorTreeComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI system | BlackBoard Component")
		TObjectPtr<UBlackboardComponent> NPCBlackboardComponent;
};
