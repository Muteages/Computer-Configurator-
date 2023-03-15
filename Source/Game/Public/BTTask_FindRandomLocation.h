// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_FindRandomLocation.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API UBTTask_FindRandomLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTTask_FindRandomLocation();

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual FString GetStaticDescription() const override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SearchArea")
	float SearchRange { 500.f };
};
