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

	// returns the tank currently controlled by the player
	ATank* GetControlledTank() const;

	// start tank moving barrel to align shot with UI reticle
	void AimToReticle();
	
	// ray trace from camera through reticle
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
};
