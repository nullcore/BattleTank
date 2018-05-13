// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankTurret.h"
#include "TankBarrel.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"



// retrieves references to the turret and barrel static meshes
void UTankAimingComponent::InitializeAimingComponent(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet)
{
		if (!TurretToSet || !BarrelToSet) { return; }

		Turret = TurretToSet;
		Barrel = BarrelToSet;
}



// handles the actual movements required for aiming
void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel || !Turret) { return; } // abandons if components are missing

	FVector TossVelocity;
	FVector Start = Barrel->GetSocketLocation(FName("Projectile"));
	FVector End = HitLocation;
	TArray<AActor*> IgnoreList;		// FIXME aim solution ignore list doesn't seem to work
		IgnoreList.Add(GetOwner()); // ignore collisions with owning actor

	// use SuggestProjectileVelocity to get an aim direction
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OUT TossVelocity,
		Start,
		End,
		LaunchSpeed,
		false,					// high-arc
		0,						// collision radius
		0,						// gravity override
		ESuggestProjVelocityTraceOption::DoNotTrace,
		FCollisionResponseParams::DefaultResponseParam,
		IgnoreList,				// actor ignore list
		false);					// debug lines

	if (bHaveAimSolution)
	{
		FVector AimDirection = TossVelocity.GetSafeNormal();
		MoveBarrelTo(AimDirection);
	}
}



// moves the turret and barrel to a specified direction
void UTankAimingComponent::MoveBarrelTo(FVector AimDirection)
{
	// both components can use barrel's rotation, as turret rotation aligns
	FRotator Rotation = Barrel->GetForwardVector().Rotation();

	// current aim rotation and the change in rotation to reach it
	FRotator AimRotation = AimDirection.Rotation();
	FRotator DeltaRotation = AimRotation - Rotation;

	// rotate the turret
	if (FMath::Abs(DeltaRotation.Yaw) < 180)
		{ Turret->Rotate(DeltaRotation.Yaw); }
	else // ensures the shortest path
		{ Turret->Rotate(-DeltaRotation.Yaw); }

	// and elevate the barrel
	Barrel->Elevate(DeltaRotation.Pitch);
}
