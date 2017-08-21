// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "TankAimingComponent.generated.h"
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void AimAt(FVector HitLocation);

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable)
	void Initialize(UTankBarrel* BarrelToSet,UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable)
	void Fire();

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Locked;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4500;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")	
	double TimeToReload = 3;
	double LastFiredTime = 0;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	bool IsBarrelMoving();

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret= nullptr;
	void MoveBarrel(FVector);

	FVector AimDirection;
};
