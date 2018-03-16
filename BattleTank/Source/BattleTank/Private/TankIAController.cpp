// Fill out your copyright notice in the Description page of Project Settings.

#include "TankIAController.h"
#include "Engine/World.h"

void ATankIAController::BeginPlay()
{
	Super::BeginPlay();

	auto Controlledtank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank) // Check if is a player in the scene
	{
		UE_LOG(LogTemp, Error, TEXT("IA Controller did not find a Player"))
	}
	if (!Controlledtank) // Check if the IA Controller manage to possess a Tank
	{
		UE_LOG(LogTemp, Error, TEXT("IA Controller is not possessing a tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("IA Controller is possessing : %s and found the player %s ."), *Controlledtank->GetName(), *PlayerTank->GetName())
	}
}

void ATankIAController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(GetPlayerTank())
	{
		// TODO Move Toward the player

		// Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire if ready
	}
}

ATank* ATankIAController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankIAController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

