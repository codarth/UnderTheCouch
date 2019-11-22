// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAI.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"


ABaseAI::ABaseAI()
{
	PrimaryActorTick.bCanEverTick = true;

	//SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>("Sight Config");
	//SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>("Perception Component"));

	//SightConfig->SightRadius = AISightRadius;
	//SightConfig->LoseSightRadius = AILoseSightRadius;
	//SightConfig->PeripheralVisionAngleDegrees = AIFieldOfView;
	//SightConfig->SetMaxAge(AISightAge);

	//SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	//SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	//SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	//GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
	//GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, ABaseAI::OnPawnDetected);
	//GetPerceptionComponent()->ConfigureSense(*SightConfig);

}

void ABaseAI::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Ai"));
}

void ABaseAI::OnPossess(APawn* Pawn)
{
	Super::OnPossess(Pawn);
}

void ABaseAI::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

FRotator ABaseAI::GetControlRotation() const
{
	if (!GetPawn())
	{
		return FRotator(0.0f, 0.0f, 0.0f);
	}

	return FRotator(0.0f, GetPawn()->GetActorRotation().Yaw, 0.0f);
}

//void ABaseAI::OnPawnDetected(const TArray<AActor*>& DetectedPawns)
//{
//
//}
