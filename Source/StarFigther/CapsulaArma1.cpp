// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaArma1.h"

// Sets default values
//ACapsulaArma1::ACapsulaArma1()
//{
//	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//	PrimaryActorTick.bCanEverTick = true;
//
//}

// Called when the game starts or when spawned
void ACapsulaArma1::BeginPlay()
{
	Super::BeginPlay();

	Nombre = "Capsula arma 01";
	TipoCapsula = "Capasula de ametralladora"; //Vida, Energia, Armadura, Armas, ....
	TipoEfecto = "Incrementa numero y velocidad balas"; //Egregar salud, agregar arma
	TipoDuracion = "Mientra este activo";
	TiempoDuracion = 10.0f;
}

void ACapsulaArma1::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, TEXT("Generando una capsula de arma01"));
}
