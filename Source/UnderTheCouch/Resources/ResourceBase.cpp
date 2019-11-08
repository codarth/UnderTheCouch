// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceBase.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AResourceBase::AResourceBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AResourceBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AResourceBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

