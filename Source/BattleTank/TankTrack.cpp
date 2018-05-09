// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"



// sets throttle for this track
void UTankTrack::SetThrottle(float Throttle)
{
	auto Name = GetName();
	 UE_LOG(LogTemp, Display, TEXT("%s: %f"), *Name, Throttle);
}
