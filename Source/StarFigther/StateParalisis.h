// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "State.h"
#include "StateParalisis.generated.h"

UCLASS()
class STARFIGTHER_API AStateParalisis : public AActor, public IState
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStateParalisis();

private:
	UPROPERTY()
	class ANaveEnemiga* NaveEnemiga;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Execute the routine when a coin is inserted
	virtual void Movimiento() override;

	//Get the String this State
	virtual FString ToString() override;
	//Set the Slot Machine of this state
	virtual void SetNaveEnemiga(class ANaveEnemiga* Enemigo) override;
};
