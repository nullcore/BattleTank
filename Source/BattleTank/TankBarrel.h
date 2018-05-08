// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"



UCLASS( meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// elevate gun barrel the correct amount this frame
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float DegreesPerSecond = 5;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElevation = 0;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxElevation = 30;
};
