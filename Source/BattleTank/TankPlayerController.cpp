// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// determine the currently controlled tank
	ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank) { 
		UE_LOG(LogTemp, Error, TEXT("TankPlayerController is not controlling a tank!")); 
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimToReticle();
}

// returns the tank currently controlled by the player
ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

// start tank moving barrel to align shot with UI reticle
void ATankPlayerController::AimToReticle()
{
	if (!GetControlledTank()) return;

	//TODO: get world location by ray-tracing through reticle

	// if it hits something
		// tell controlled tank to aim at this point
}