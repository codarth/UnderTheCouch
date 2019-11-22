// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerNCamera.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"

// Sets default values
APlayerNCamera::APlayerNCamera()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-60.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = TargetArmLength;
	SpringArm->bEnableCameraLag = bCameraLag;
	SpringArm->CameraLagSpeed = CameraLagSpeed;


	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);

	b_RotateEnabled = false;

}

// Called when the game starts or when spawned
void APlayerNCamera::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlayerNCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovementInput *= MovementScaler;
	FVector NewLocation = GetActorLocation();
	NewLocation += GetActorForwardVector() * MovementInput.X * DeltaTime;
	NewLocation += GetActorRightVector() * MovementInput.Y * DeltaTime;
	SetActorLocation(NewLocation);

	if (b_RotateEnabled) // TODO: Change to Right Mouse button or Middle from left shift
	{
		{
			FRotator NewRotation = GetActorRotation();
			NewRotation.Yaw += RotateInput.Yaw;
			SetActorRotation(NewRotation);
		}

		{
			FRotator NewRotation = SpringArm->GetComponentRotation();
			NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + RotateInput.Pitch, PitchMin, PitchMax);
			SpringArm->SetWorldRotation(NewRotation);
		}
	}
}

// Called to bind functionality to input
void APlayerNCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveForward", this, &APlayerNCamera::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &APlayerNCamera::MoveRight);
	InputComponent->BindAxis("CameraPan", this, &APlayerNCamera::CameraPan);
	InputComponent->BindAxis("CameraTilt", this, &APlayerNCamera::CameraTilt);

	InputComponent->BindAxis("Zoom", this, &APlayerNCamera::Zoom);

	InputComponent->BindAction("EnableRotate", IE_Pressed, this, &APlayerNCamera::EnableRotate);
	InputComponent->BindAction("EnableRotate", IE_Released, this, &APlayerNCamera::DisableRotate);
}

void APlayerNCamera::MoveForward(float Value)
{
	MovementInput.X = FMath::Clamp<float>(Value, -1.0f, 1.0f);
}

void APlayerNCamera::MoveRight(float Value)
{
	MovementInput.Y = FMath::Clamp<float>(Value, -1.0f, 1.0f);
}

void APlayerNCamera::CameraPan(float Value)
{
	RotateInput.Yaw = Value;
}

void APlayerNCamera::CameraTilt(float Value)
{
	RotateInput.Pitch = Value;
}

void APlayerNCamera::EnableRotate()
{
	b_RotateEnabled = true;
}

void APlayerNCamera::DisableRotate()
{
	b_RotateEnabled = false;
}

void APlayerNCamera::Zoom(float Value)
{
	float TargetLength = SpringArm->TargetArmLength;
	TargetLength = FMath::Clamp(TargetLength + Value * ZoomFactor, ZoomMin, ZoomMax);
	SpringArm->TargetArmLength = TargetLength;
}


