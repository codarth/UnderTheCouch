// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerNCamera.generated.h"

UCLASS()
class UNDERTHECOUCH_API APlayerNCamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerNCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(VisibleAnywhere, Category = Camera)
		class USpringArmComponent* SpringArm;

	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category = Display)
		class UStaticMeshComponent* Mesh;	// TODO: Don't really need a mesh

	UPROPERTY(VisibleAnywhere, Category = Camera)
		float TargetArmLength = 1000.0f;
	UPROPERTY(VisibleAnywhere, Category = Camera)
		bool bCameraLag = true;
	UPROPERTY(VisibleAnywhere, Category = Camera)
		float CameraLagSpeed = 5.0f;

	UPROPERTY(VisibleAnywhere, Category = Movement)
		float MovementScaler = 400.0f;

	UPROPERTY(VisibleAnywhere, Category = Movement)
		float ZoomMin = 50.0f;
	UPROPERTY(VisibleAnywhere, Category = Movement)
		float ZoomMax = 5000.0f;
	UPROPERTY(VisibleAnywhere, Category = Movement)
		float ZoomFactor = 50.0f;

	// TODO: Remove UPROPERTY where not needed

private:

	void MoveForward(float Value);
	void MoveRight(float Value);
	void CameraPan(float Value);
	void CameraTilt(float Value);
	void EnableRotate();
	void DisableRotate();
	void Zoom(float Value);

	FVector2D MovementInput;
	FRotator RotateInput;
	bool b_RotateEnabled;
	float PitchMin = -80.0f;
	float PitchMax = -15.0f;

};
