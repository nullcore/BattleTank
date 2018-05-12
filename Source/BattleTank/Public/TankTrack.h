// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"



UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// maximum force tracks per track in Newtons
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxForce = 100000000.0;
	
	// sets throttle for this track
	UFUNCTION(BlueprintCallable)
	void SetThrottle(float Throttle);
};
