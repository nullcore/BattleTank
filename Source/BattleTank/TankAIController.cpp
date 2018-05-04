// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "TankAIController.h"


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
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController %s has found %s."), *ControlledTank->GetName(), *PlayerTank->GetName());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}