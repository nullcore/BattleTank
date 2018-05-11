// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"



class UTankTurret;
class UTankBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent(); // TODO  can we ditch this?

	// retrieves a reference to the turret and barrel static meshes
	void SetTurretReference(UTankTurret* TurretToSet); // TODO  combine into SetReferences()
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	// handles the actual movements required for aiming
	void AimAt(FVector HitLocation, float LaunchSpeed);

private:
	// variables to hold turret and barrel mesh references
	UTankTurret* Turret = nullptr;
	UTankBarrel* Barrel = nullptr;

	// moves the turret and barrel to a specified direction
	void MoveTurretTo(FVector AimDirection); // TODO  combine with MoveBarrelTo()
	void MoveBarrelTo(FVector AimDirection);
};
