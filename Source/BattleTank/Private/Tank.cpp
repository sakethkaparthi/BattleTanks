// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine/World.h"
#include "TankBarrel.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation) {
	if(ensure(TankAimingComponent))
		TankAimingComponent->AimAt(HitLocation,LaunchSpeed);
}

void ATank::Fire() {
	if (ensure(TankAimingComponent))
		TankAimingComponent->Fire(ProjectileBlueprint,LaunchSpeed);
}