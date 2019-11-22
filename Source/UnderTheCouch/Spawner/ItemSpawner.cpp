// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemSpawner.h"
#include "Engine/World.h"
#include "../Resources/ResourceBase.h"

// Sets default values
AItemSpawner::AItemSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItemSpawner::BeginPlay()
{
	Super::BeginPlay();

	Spawn();
	
}

// Called every frame
void AItemSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItemSpawner::Spawn()
{
	if (ToSpawn)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			FVector SpawnLocation = GetActorLocation();
			FRotator SpawnRotation = GetActorRotation();
			// TODO: Add randomness to spawn (Velocity?)
			World->SpawnActor<AResourceBase>(ToSpawn, SpawnLocation, SpawnRotation, SpawnParams);
		}
	}
}

