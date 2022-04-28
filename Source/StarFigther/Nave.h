// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Nave.generated.h"

class UStaticMeshComponent;

UCLASS()
class STARFIGTHER_API ANave : public APawn
{
private:
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Ship", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* ShipMeshComponent;
public:
	// Sets default values for this pawn's properties
	ANave();

	/* The speed our ship moves around the level */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
		float MoveSpeed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Ship")
		float Energy;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Static names for axis bindings
	static const FName MoveForwardBinding;
	static const FName MoveRightBinding;
};
