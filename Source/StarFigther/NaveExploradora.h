// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Subscriber.h"
#include "Morph.h"
#include "NaveExploradora.generated.h"

UCLASS()
class STARFIGTHER_API ANaveExploradora : public AActor/*, public ISubscriber*///, public IMorph
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANaveExploradora();

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Ship", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* ShipMeshComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Ship")
		float Energy;

	/* The speed our ship moves around the level */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
		float MoveSpeed;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Static names for axis bindings
	static const FName MoveForwardBinding;
	static const FName MoveRightBinding;


	FORCEINLINE float GetEnergy() const { return Energy; }
	FORCEINLINE float GetMoveSpeed() const { return MoveSpeed; }

	FORCEINLINE void SetEnergy(float _Energy) { Energy = _Energy; }
	FORCEINLINE void SetMoveSpeed(float _MoveSpeed) { MoveSpeed = _MoveSpeed; }

};
