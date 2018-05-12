// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"



/**
 * fly-by wire control interpretation, outputs force to tracks
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	// receives input, requests appropriate movement from tank tracks
	UFUNCTION(BlueprintCallable, Category = Setup)
	void IntendMoveForward(float Throw);
};
