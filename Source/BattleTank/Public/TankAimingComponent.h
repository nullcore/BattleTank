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
	// retrieves references to the turret and barrel static meshes
	UFUNCTION(BlueprintCallable, Category = Setup)
	void InitializeAimingComponent(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);

	// handles the actual movements required for aiming
	void AimAt(FVector HitLocation, float LaunchSpeed);

//protected: // TODO set back to protected if possible
	// variables to hold turret and barrel mesh references
	UTankTurret* Turret = nullptr;
	UTankBarrel* Barrel = nullptr;

private:
	// moves the turret and barrel to a specified direction
	void MoveBarrelTo(FVector AimDirection);
};
