// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseAI.generated.h"

/**
 * 
 */
UCLASS()
class UNDERTHECOUCH_API ABaseAI : public AAIController
{
	GENERATED_BODY()

public:
	ABaseAI();

	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* Pawn) override;

	virtual void Tick(float DeltaSeconds) override;

	virtual FRotator GetControlRotation() const override;

	//UFUNCTION()
	//	void OnPawnDetected(const TArray<AActor*> &DetectedPawns);

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
	//	float AISightRadius = 500.0f;

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
	//	float AISightAge = 5.0f;

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
	//	float AILoseSightRadius = AISightRadius + 50.0f;

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
	//	float AIFieldOfView = 90.0f;

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
	//	class UAISenseConfig_Sight* SightConfig;


};
