// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"


void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	auto ControlledTank = GetPawn();
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	if (ensure(PlayerTank)) {
		MoveToActor(PlayerTank,AcceptanceRadius);
		AimingComponent->AimAt(PlayerTank->GetActorLocation());
		AimingComponent->Fire();
	}
	
}