// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "TankPlayerController.generated.h"

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere) // where the reticle appears on screen (offset from left-top)
	FVector2D ReticleOffset = FVector2D(0.5, 0.33333);
	UPROPERTY(EditAnywhere) // ray-tracing range
	float RayTraceRange = 1000000;

	// returns the tank currently controlled by the player
	ATank* GetControlledTank() const;

	// start tank moving barrel to align shot with UI reticle
	void AimToReticle() const;
	
	// ray trace from camera through reticle
	bool GetHitLocation(FVector& HitLocation) const;

	// returns a hit location for a ray traced along LookVector
	bool GetRayTraceResults(FVector CameraPosition, FVector LookDirection, FVector & HitLocation) const;
};
