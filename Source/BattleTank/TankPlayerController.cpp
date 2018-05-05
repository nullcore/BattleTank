// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"

#define OUT

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

	if (!GetControlledTank()) return;

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
		UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *HitLocation.ToString());
	}

	return;
}

// ray trace from camera through reticle
bool ATankPlayerController::GetHitLocation(FVector& HitLocation) const
{
	// find reticle position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(OUT ViewportSizeX, OUT ViewportSizeY);
	FVector2D ReticlePosition = FVector2D(ViewportSizeX * ReticleOffset.X, ViewportSizeY * ReticleOffset.Y);

	// get the camera position and direction the camera is looking through the reticle
	FVector CameraPosition, LookDirection;
	if (DeprojectScreenPositionToWorld(
			ReticlePosition.X,
			ReticlePosition.Y,
			OUT CameraPosition,
			OUT LookDirection))
	{
		// ray-trace and determine a hit location
		GetRayTraceResults(CameraPosition, LookDirection, OUT HitLocation);
	}

	return true;
}

// returns a hit location for a ray traced along LookVector
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