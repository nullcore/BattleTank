// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;



/**
 * fly-by wire control interpretation, outputs force to tracks
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	// initializes references to both tank tracks
	UFUNCTION(BlueprintCallable, Category = Setup)
	void InitializeMovementComponent(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

	// receives input, requests appropriate movement from tank tracks
	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendMove(float Throw);
	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendRotate(float Throw);

	// TODO check if this can be private
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

private:
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
};
