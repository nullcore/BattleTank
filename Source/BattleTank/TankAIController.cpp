// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}



void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// don't even bother if there's no tank to control, or no player tank
	if (!GetControlledTank() || !GetPlayerTank()) { return; }

	// aim at the player's tank
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
}



// returns the tank currently controlled by the AI
ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}



// returns the tank currently controlled by the player
ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}