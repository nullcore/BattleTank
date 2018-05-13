// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"



// initializes references to both tank tracks
void UTankMovementComponent::InitializeMovementComponent(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
    if (!LeftTrackToSet || !RightTrackToSet) { return; }
    
    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;
}



// receives input, requests appropriate movement from tank tracks
void UTankMovementComponent::IntendMoveForward(float Throw)
{
    auto Log1 = GetName();
    //UE_LOG(LogTemp, Display, TEXT("%s: %f"), *Log1, Throw);
}

