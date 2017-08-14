// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"


void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("TankAIController Possessing %s"), *GetControlledTank()->GetName())
	ATank* PlayerTank = GetPlayerTank();
	if(PlayerTank)
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController Possessing %s"), *PlayerTank->GetName())
	else
		UE_LOG(LogTemp, Warning, TEXT("Could not find Player Controlled Tank"))
	PrimaryActorTick.bCanEverTick = true;
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if(!PlayerTank)
		return nullptr;
	else
		return Cast<ATank>(PlayerTank);
}