// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"



// initializes references to both tank tracks
void UTankMovementComponent::InitializeMovementComponent(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;
}



// receives input, requests appropriate movement from tank tracks
void UTankMovementComponent::IntendMove(float Throw)
{
    if (!LeftTrack || !RightTrack) { return; }
    
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(Throw);
}



// receives input, requests appropriate movement from tank tracks
void UTankMovementComponent::IntendRotate(float Throw)
{
    if (!LeftTrack || !RightTrack) { return; }
    
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(-Throw);
}