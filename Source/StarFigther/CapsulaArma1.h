// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Capsula.h"
#include "CapsulaArma1.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGTHER_API ACapsulaArma1 : public ACapsula
{
	GENERATED_BODY()
public:
	ACapsulaArma1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* CapsulaMeshComponent;
public:
	virtual void Generar() override;

	virtual void Destruir() ;

	virtual void PickUp();
};
