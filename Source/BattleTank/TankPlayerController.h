// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere) // reticle is halfway across the screen
	float ReticleXLocation = 0.5;
	UPROPERTY(EditAnywhere) // reticle is a third down the screen
	float ReticleYLocation = 0.33333;

	// returns the tank currently controlled by the player
	ATank* GetControlledTank() const;

	// start tank moving barrel to align shot with UI reticle
	void AimToReticle() const;
	
	// ray trace from camera through reticle
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	// de-projects reticle to a look direction
	bool GetLookDirection(FVector2D ReticlePosition, FVector& OutLookDirection) const;
};
