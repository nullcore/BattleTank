// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"



class UTankAimingComponent; 
class UTankTurret;
class UTankBarrel;
class AProjectile;
class UTankMovementComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// aims the tank at the specified location
	void AimAt(FVector HitLocation);

	// fire projectile
	UFUNCTION(BlueprintCallable)
	void Fire();

protected:
	// protected pointers for components
	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	ATank();

	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// defines the tank's projectile
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;
	// sets the firing speed of the tank's cannon
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 30000;
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTime = 3;
	// determines when the last shot was fired
	float LastFireTime = -ReloadTime; // initialized to allow immediate firing

	// local reference to barrel
	UTankBarrel* Barrel = nullptr;
};
