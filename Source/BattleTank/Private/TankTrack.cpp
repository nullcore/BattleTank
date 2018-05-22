// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"



// sets throttle for this track
void UTankTrack::SetThrottle(float Throttle)
{
	// prevents throttle from exceeding inteded values
	// Throttle = FMath::Clamp<float>(Throttle, -0.5, 1); // TODO properly clamp input (still receives double input)

	FVector ForceApplied = GetForwardVector() * Throttle * MaxForce;
	FVector ForceLocation = GetComponentLocation();
	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	
	if (TankRoot)
	{
		TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
	}
}
