// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"




ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	auto ControlledTank= GetControlledTank();
	if (!ControlledTank) 
		UE_LOG(LogTemp, Error, TEXT("Tank not possessed"))
	else
		UE_LOG(LogTemp,Warning,TEXT("Hello from Player Controller begin play"))
	UE_LOG(LogTemp, Warning, TEXT("Hello from %s pawn"),*ControlledTank->GetName())
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) return;
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"),*HitLocation.ToString())
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & HitResultOut) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString())
	HitResultOut = FVector(1.0f);
	return true;
}
