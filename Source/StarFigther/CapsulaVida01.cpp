// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaVida01.h"


void ACapsulaVida01::BeginPlay()
{
	Super::BeginPlay();

	Nombre = "Capsula vida 01";
	TipoCapsula = "Capsula que sube al maximo nivel la energia"; //Vida, Energia, Armadura, Armas, ....
	TipoEfecto = "Incrementa a tope la energia en el momento"; //Egregar salud, agregar arma
	TipoDuracion = "Mientra este vivo el jugador";
	TiempoDuracion = 10.0f;
}

void ACapsulaVida01::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, TEXT("Generando una capsula de vida01"));
}
