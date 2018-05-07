// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"



class UTankBarrel; // forward declaration

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	// retrieves a reference to the barrel's static mesh
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	// TODO SetTurretReference()

	// handles the actual movements required for aiming
	void AimAt(FVector HitLocation, float LaunchSpeed);

private:
	// finds the mesh for the barrel component of the tank
	UTankBarrel* Barrel = nullptr;

	// moves the barrel to a specified direction
	void MoveBarrelTo(FVector AimDirection);
};
