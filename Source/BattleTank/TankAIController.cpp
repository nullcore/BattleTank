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
		// aim at the player's tank
		// TODO find a more elegant solution to AI targeting of player tank
		FVector Target = PlayerTank->GetDefaultAttachComponent()->GetSocketLocation(FName("Turret"));
		AITank->AimAt(Target);
		//AITank->Fire(); // TODO limit firing rate
	}
}