// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryActor.h"
#include "CapsulaArma1.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STARFIGTHER_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY()
		TArray<AInventoryActor*> CurrentInventory;

	UFUNCTION()
		int32 AddToInventory(AInventoryActor* _ActorToAdd);

	UFUNCTION()
		void RemoveFromInventory(AInventoryActor* ActorToRemove);

	UPROPERTY()
		TArray<ACapsulaArma1*> CurrentArma1;

	UFUNCTION()
		int32 AddToInventoryArma1(ACapsulaArma1* _CapsulaToAdd);

	

};
