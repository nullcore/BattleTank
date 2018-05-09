// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}



void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// find the AI controlled tank and the player's tank
	ATank* AITank = Cast<ATank>(GetPawn());
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (AITank && PlayerTank) 
	{
		// aim and fire
		AITank->AimAt(PlayerTank->GetActorLocation());
		// AITank->Fire(); // TODO turn AI firing back on
	}
}