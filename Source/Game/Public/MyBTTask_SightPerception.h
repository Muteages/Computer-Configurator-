// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "MyBTTask_SightPerception.generated.h"

/**
 * 
 */


UCLASS()
class GAME_API UMyBTTask_SightPerception : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UMyBTTask_SightPerception();

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual FString GetStaticDescription() const override;

public: 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Search")
		float SearchRange = 200.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Search")
		bool Isdetect = false;
};
