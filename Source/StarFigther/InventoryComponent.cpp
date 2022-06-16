// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int32 UInventoryComponent::AddToInventory(AInventoryActor* _ActorToAdd)
{
	return CurrentInventory.Add(_ActorToAdd);
}

void UInventoryComponent::RemoveFromInventory(AInventoryActor* _ActorToRemove)
{
	CurrentInventory.Remove(_ActorToRemove);
}
//CapsulaArma1
int32 UInventoryComponent::AddToInventoryArma1(ACapsulaArma1* _CapsulaToAdd)
{
	return CurrentArma1.Add(_CapsulaToAdd);
}

