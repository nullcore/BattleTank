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
	// accepts values from -1 to 1
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float DegreesPerSecond = 20;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevation = 0;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevation = 30;
};
