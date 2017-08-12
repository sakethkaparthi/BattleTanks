// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	void Rotate(float RelativeSpeed);
private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 20.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxRotationDegrees = 40.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinRotationDegrees = 0.0f;
	
};
