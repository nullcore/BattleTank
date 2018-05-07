// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}



// retrieves a reference to the barrel's static mesh
void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}



// handles the actual movements required for aiming
void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; } // abandons if no barrel is found

	FVector TossVelocity;
	FVector Start = Barrel->GetSocketLocation(FName("Projectile"));
	FVector End = HitLocation;// +FVector(0, 0, 100);

	// use SuggestProjectileVelocity to get an aim direction
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity	(
		this,
		OUT TossVelocity,
		Start,
		End,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace);

	if (bHaveAimSolution)
	{
		FVector AimDirection = TossVelocity.GetSafeNormal();
		MoveBarrelTo(AimDirection);
	}
	else
	{
		UE_LOG(LogTemp, Display, 
			TEXT("<%f><%s> No solution Found!"), 
				GetWorld()->GetTimeSeconds(),
				*GetOwner()->GetName());
	}
}



// moves the barrel
void UTankAimingComponent::MoveBarrelTo(FVector AimDirection)
{
	FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator AimRotation = AimDirection.Rotation();
	FRotator DeltaRotation = AimRotation - BarrelRotation;

	UE_LOG(LogTemp, Warning,
		TEXT("<%f><%s> %s"),
		GetWorld()->GetTimeSeconds(),
		*GetOwner()->GetName(),
		*AimRotation.ToString());

	Barrel->Elevate(5); // TODO remove magic number
}
