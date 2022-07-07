// Fill out your copyright notice in the Description page of Project Settings.


#include "StateParalisis.h"
#include "NaveEnemiga.h"

// Sets default values
AStateParalisis::AStateParalisis()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStateParalisis::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStateParalisis::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FString AStateParalisis::ToString()
{
	return FString();
}

void AStateParalisis::SetNaveEnemiga(ANaveEnemiga* Enemigo)
{
	NaveEnemiga = Enemigo;
}

void AStateParalisis::Movimiento()
{
	//NaveEnemiga->SetState(NaveEnemiga -> GetReducMovState());
}





