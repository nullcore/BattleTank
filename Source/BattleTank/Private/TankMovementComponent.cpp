// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"



// receives input, requests appropriate movement from tank tracks
void UTankMovementComponent::IntendMoveForward(float Throw)
{
    auto Log1 = GetName();
    UE_LOG(LogTemp, Display, TEXT("%s: %f"), *Log1, Throw);
}

