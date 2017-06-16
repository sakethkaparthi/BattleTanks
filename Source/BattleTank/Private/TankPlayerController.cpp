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