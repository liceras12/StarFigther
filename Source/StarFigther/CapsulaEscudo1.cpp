// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaEscudo1.h"

// Sets default values
//ACapsulaEscudo1::ACapsulaEscudo1()
//{
//	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//	PrimaryActorTick.bCanEverTick = true;
//
//}

// Called when the game starts or when spawned
void ACapsulaEscudo1::BeginPlay()
{
	Super::BeginPlay();
	Nombre = "Capsula escudo 01";
	TipoCapsula = "Capsula de escudo magnetico"; //Vida, Energia, Armadura, Armas, ....
	TipoEfecto = "Imposibilita que una municion normal dañe a la nave del jugador"; //Egregar salud, agregar arma
	TipoDuracion = "10 segundos";
}

void ACapsulaEscudo1::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, TEXT("Generando una capsula de escudo01"));
}
