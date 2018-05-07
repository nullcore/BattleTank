// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"



// elevate gun barrel the correct amount this frame
void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1); // ensures maximum speed compliance
	float ElevationChange = RelativeSpeed * DegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	float Elevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation); // limits elevation range

	SetRelativeRotation(FRotator(Elevation, 0, 0));
}