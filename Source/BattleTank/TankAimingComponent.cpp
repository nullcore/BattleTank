// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}



// retrieves a reference to the barrel's static mesh
void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;
}



//// Called when the game starts
//void UTankAimingComponent::BeginPlay()
//{
//	Super::BeginPlay();
//}
//
//
//
//// Called every frame
//void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//}



// handles the actual movements required for aiming
void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; } // abandons if no barrel is found

	// use SuggestProjectileVelocity to get an aim direction
	FVector TossVelocity;
	FVector Start = Barrel->GetSocketLocation(FName("Projectile"));

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OUT TossVelocity,
		Start,
		HitLocation,
		LaunchSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (bHaveAimSolution)
	{
		auto AimDirection = TossVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *TankName, *AimDirection.ToString());
	}


		//this,
		//OUT TossVelocity,
		//Start,
		//HitLocation,
		//LaunchSpeed,
		//ESuggestProjVelocityTraceOption::DoNotTrace);

	//if (bHaveAimSolution)
	//{
	//	FVector AimDirection = TossVelocity.GetSafeNormal();
	//	FString TankName = GetOwner()->GetName();
	//	UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *AimDirection.ToString());
	//}
}