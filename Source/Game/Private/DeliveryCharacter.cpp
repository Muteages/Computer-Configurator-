// Fill out your copyright notice in the Description page of Project Settings.


#include "DeliveryCharacter.h"

// Sets default values
ADeliveryCharacter::ADeliveryCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetupStimulus();
}

// Called when the game starts or when spawned
void ADeliveryCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADeliveryCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADeliveryCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ADeliveryCharacter::SetupStimulus()
{
	PlayerStimulus = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("Player Stimulus"));
	PlayerStimulus->RegisterForSense(TSubclassOf<UAISense_Sight>());
	PlayerStimulus->RegisterWithPerceptionSystem();
}

