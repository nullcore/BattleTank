// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankMovementComponent.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "Engine/World.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// create default components (pointer protection added at construction in .h)
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));
	TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("MovementComponent"));
}


// aims the tank at the specified location
void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed); // TODO handle in TankAimingComponent directly
}



//fire projectile
void ATank::Fire() // TODO handle in TankAimingComponent directly
{
	// checks for a barrel and projectile blueprint, logs and exits if not found
	FString ThisTank = GetName();
	Barrel = TankAimingComponent->Barrel;
	if (!Barrel)
	{
		UE_LOG(LogTemp, Error, TEXT("%s has no Barrel assigned!"), *ThisTank);
		return;
	}
	if (!ProjectileBlueprint)
	{
		UE_LOG(LogTemp, Error, TEXT("%s has no ProjectileBlueprint assigned!"), *ThisTank);
		return;
	}

	// check for a barrel and if gun is reloaded
	bool bReloaded = ( (GetWorld()->GetTimeSeconds() - LastFireTime) > ReloadTime );
	if (Barrel && ProjectileBlueprint && bReloaded)
	{
		// spawns a projectile
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile")));

		// launches that projectile
		Projectile->LaunchProjectile(LaunchSpeed);

		//resets fire time for reload checking
		LastFireTime = GetWorld()->GetTimeSeconds();
	}
}