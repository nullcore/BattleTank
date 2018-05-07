// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"



// elevate gun barrel the correct amount this frame
void UTankTurret::Rotate(float RelativeSpeed)
{
	// ensure minimum/maximum speed compliance
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	float DeltaRotation = RelativeSpeed * DegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float NewRotation = RelativeRotation.Yaw + DeltaRotation;

	// sets the barrel pitch
	SetRelativeRotation(FRotator(0, NewRotation, 0));
}
