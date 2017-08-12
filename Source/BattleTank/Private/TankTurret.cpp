// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed) {
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Yaw + RotationChange;
	auto Rotation = FMath::Clamp<float>(RawNewElevation, MinRotationDegrees, MaxRotationDegrees);
	SetRelativeRotation(FRotator(0, Rotation, 0));
}


