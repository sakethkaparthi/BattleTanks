// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle) {
	auto ForceApplied = GetForwardVector() * MaxForcePerTrack * Throttle ;//Vector of force to apply
	auto ForceLocation = GetComponentLocation();//Location to apply force at
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}