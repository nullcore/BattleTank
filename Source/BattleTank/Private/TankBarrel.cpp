// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"



// elevate gun barrel the correct amount this frame
void UTankBarrel::Elevate(float RelativeSpeed)
{
	// ensure minimum/maximum speed compliance
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	float DeltaElevation = RelativeSpeed * DegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float NewElevation = FMath::Clamp<float>(RelativeRotation.Pitch + DeltaElevation, MinElevation, MaxElevation);

	// sets the barrel pitch
	SetRelativeRotation(FRotator(NewElevation, 0, 0));
}