// Fill out your copyright notice in the Description page of Project Settings.


#include "StrategyRetirada.h"

// Sets default values
AStrategyRetirada::AStrategyRetirada()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStrategyRetirada::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStrategyRetirada::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStrategyRetirada::Maneuver()
{
	//Execute the routine of this type of Strategy
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("Debemos salir de aqui!!!"));


}