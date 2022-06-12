// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "InventoryActor.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGTHER_API AInventoryActor : public AStaticMeshActor
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Datos", meta = (AllowPrivateAccess = "true"))
	FString Nombre;

public:
	AInventoryActor();
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	virtual void PickUp();
	virtual void PutDown(FTransform TargetLocation);

	FORCEINLINE FString GetNombre() const { return Nombre; }
	FORCEINLINE void SetNombre(const FString _Nombre) { Nombre = _Nombre; }
};
