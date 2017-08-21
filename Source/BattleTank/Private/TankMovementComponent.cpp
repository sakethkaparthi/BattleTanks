// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* left, UTankTrack* right) {
	if (!ensure(left && right)) { return; }
	LeftTrack = left;
	RightTrack = right;
}

void UTankMovementComponent::IntendMoveForward(float Throw) {
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw) {
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector &MoveVelocity, bool bForceMaxSpeed) {
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	//How much to move along the local x axis to be parallel to the player tank 
	auto Throw = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(Throw);

	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntendTurnRight(RightThrow);
}