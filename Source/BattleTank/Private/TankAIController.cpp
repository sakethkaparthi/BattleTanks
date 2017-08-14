// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"


void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	auto ControlledTank = Cast<ATank>(GetPawn());
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank) {
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire();
	}
}