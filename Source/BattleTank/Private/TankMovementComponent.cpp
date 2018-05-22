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



// overrides NavMeshComponent, implementing our own movement based on pathfinding
void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
    FVector TankFacing = GetOwner()->GetActorForwardVector();
    FVector ForwardVector = MoveVelocity.GetSafeNormal();

    // finds parallel-ness of vectors (1 is facing, 0 is perpendicular, -1 is behind)
    float DotProduct = FVector::DotProduct(TankFacing, ForwardVector);

    IntendMove(DotProduct);

	// LOG   LOG   LOG 
    UE_LOG(LogTemp, Warning, TEXT("TF: %s"), *TankFacing.ToString());
    UE_LOG(LogTemp, Warning, TEXT("MV: %s"), *ForwardVector.ToString());
	// LOG   LOG   LOG 
}
