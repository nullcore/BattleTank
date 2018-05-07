// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "Tank.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
}



void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// don't even bother if there's no tank to control
	if (!GetControlledTank()) return;

	// aim at the on screen UI reticle
	AimToReticle();
}



// returns the tank currently controlled by the player
ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}



// start tank moving barrel to align shot with UI reticle
void ATankPlayerController::AimToReticle() const
{
	// if ray-tracing returns a hit
	FVector HitLocation;
	if (GetHitLocation(OUT HitLocation)) 
	{
		// passes to Tank.h to handle aiming
		GetControlledTank()->AimAt(HitLocation);
	}

	return;
}



// retrives any visible object under the UI reticle
bool ATankPlayerController::GetHitLocation(FVector& HitLocation) const
{
	// find reticle position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(OUT ViewportSizeX, OUT ViewportSizeY);
	FVector2D ReticlePosition = FVector2D(ViewportSizeX * ReticleOffset.X, ViewportSizeY * ReticleOffset.Y);

	// deproject the camera position and the camera look direction
	FVector CameraPosition, LookDirection;
	if (DeprojectScreenPositionToWorld(
			ReticlePosition.X,
			ReticlePosition.Y,
			OUT CameraPosition,
			OUT LookDirection))
	{
		// ray-trace and determine a hit location
		GetRayTraceResults(CameraPosition, LookDirection, OUT HitLocation);
		return true;
	}
	else 
	{
		HitLocation = FVector(0);
		return false; 
	}
}



// returns a hit location for a ray traced through the reticle
bool ATankPlayerController::GetRayTraceResults(FVector CameraPosition, FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	FVector Start = CameraPosition;
	FVector End = CameraPosition + (LookDirection * RayTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
			OUT HitResult,
			Start,
			End,
			ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	else
	{
		return false;
	}
}