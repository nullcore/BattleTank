// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"



UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	// how close AI tank will move toward player tank
	UPROPERTY(EditDefaultsOnly)
	float AcceptanceRadius = 3000;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
