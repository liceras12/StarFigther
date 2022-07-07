// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nave.h"
#include "Subscriber.h"
#include "Morph.h"
#include "SlingShot.h"
#include "NaveEnemigaStrategy.h"
#include "State.h"
#include "NaveEnemiga.generated.h"

/**
 * 
 */
class ANaveAereaJugador;

UCLASS()
class STARFIGTHER_API ANaveEnemiga : public ANave//, public ISlingShot//, public IMorph
{
	GENERATED_BODY()
	
public:
	ANaveEnemiga();

	virtual void BeginPlay() override;
	// Begin Actor Interface
	virtual void Tick(float DeltaSeconds) override;

	void Fire();

	/* Fire a shot in the specified direction */
	void FireShot(FVector FireDirection);

	/* Handler for the fire timer expiry */
	void ShotTimerExpired();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* FireSound;

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		FVector GunOffset;

	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float FireRate;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* DamageCollision;

	//AI del enemigo
	UPROPERTY(VisibleDefaultsOnly, Category = enemy)
		class UAIPerceptionComponent* AIPerComp;

	UPROPERTY(VisibleDefaultsOnly, Category = enemy)
		class UAISenseConfig_Sight* SightConfig;

	UFUNCTION()
		void OnSensed(const TArray<AActor*>& UpdatedActors);

	UPROPERTY(VisibleAnywhere, Category = Movement)
		FRotator EnemyRotation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
		FRotator CurrentVelocity;

	UPROPERTY(VisibleAnywhere, Category = Movement)
		FRotator BaseLocation;

	void SetNewRotation(FVector TargetPosition, FVector CurrentPosition);


private:

	/* Flag to control firing  */
	uint32 bCanFire : 1;

	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;
//////////////////////////////////////////////////////////////////////////////
public:
	// Change the Maneuver and set "BattleStrategy" variable
	void AlterManeuvers(ANave* myBattleStrategy);
	// Engage with the current Battle Strategy
	void Engage();

private:
	//The current Battle Strategy
	INaveEnemigaStrategy* BattleStrategy;

////////////////////////////////////////////////////////////////////////////
private:
	//The No Dollars State of this Slot Machine
	IState* StateParalisis;

	IState* State;

public:

	void Initialize();
	//Insert a Coin
	void Movimiento();
	
	IState* GetState();
	//Get the No Dollars State of this Slot Machine
	IState* GetStateParalisis();
	//Get the String of the current State
	FString GetCurrentState();

	void SetState(IState* myState);
};
