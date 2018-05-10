// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"



// sets throttle for this track
void UTankTrack::SetThrottle(float Throttle)
{
	FVector ForceApplied = GetForwardVector() * Throttle * MaxForce;
	FVector ForceLocation = GetComponentLocation();
	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	
	if (TankRoot)
	{
		TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

		auto Log1 = GetName();
		UE_LOG(LogTemp, Display, TEXT("%s: %f"), *Log1, Throttle);
	}
}
