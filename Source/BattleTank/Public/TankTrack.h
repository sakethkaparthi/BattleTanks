// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"
//Tank Track is used to set max driving force and to apply forces to the tank
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
public:

	//Function to set the apply force/throttle on a track
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	UPROPERTY(EditDefaultsOnly)
	float MaxForcePerTrack = 400000; //In newtons

	UTankTrack();

	virtual void BeginPlay();

	void ApplySidewaysForce();
private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,UPrimitiveComponent* OtherComponent,FVector NormalImpulse, const FHitResult &Hit);
	void DriveTrack();

	float CurrentThrottle = 0;
};
