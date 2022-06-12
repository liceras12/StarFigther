// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Capsula.h"
#include "CapsulaEnergia01.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGTHER_API ACapsulaEnergia01 : public ACapsula
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Generar() override;
};
