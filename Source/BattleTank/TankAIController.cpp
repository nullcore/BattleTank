// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	// determine the currently controlled tank and player tank
	ATank* ControlledTank = GetControlledTank();
	ATank* PlayerTank = GetPlayerTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("TankAIController is not controlling a tank!"));
	}
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("TankAIController cannot determine player tank!"))
	}
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