// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankTurret.h"
#include "TankBarrel.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false; 
}



// retrieves references to the turret and barrel static meshes
void UTankAimingComponent::SetReferences(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet)
{
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
		MoveTurretTo(AimDirection);
		MoveBarrelTo(AimDirection);
	}
}



// moves the turret to a specified direction
void UTankAimingComponent::MoveTurretTo(FVector AimDirection)
{
	FRotator AimRotation = AimDirection.Rotation();
	FRotator TurretRotation = Turret->GetForwardVector().Rotation();
	FRotator DeltaRotation = AimRotation - TurretRotation;

	if (FMath::Abs(DeltaRotation.Yaw) < 180)
	{ 	
		Turret->Rotate(DeltaRotation.Yaw);
	}
	else
	{
		Turret->Rotate(-DeltaRotation.Yaw);
	}

}

// moves the barrel to a specified direction
void UTankAimingComponent::MoveBarrelTo(FVector AimDirection)
{
	FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator AimRotation = AimDirection.Rotation();
	FRotator DeltaRotation = AimRotation - BarrelRotation;

	Barrel->Elevate(DeltaRotation.Pitch);
}
