// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneradorCapsulasEnergia.h"
#include "CapsulaEnergia01.h"
#include "CapsulaEnergia2.h"
#include "CapsulaVida01.h"


ACapsula* AGeneradorCapsulasEnergia::FabricarCapsula(FString NombreTipoCapsula)
{
    if (NombreTipoCapsula.Equals("Energia1")) {
        return GetWorld()->SpawnActor<ACapsulaEnergia01>(ACapsulaEnergia01::StaticClass());
    }
    else if (NombreTipoCapsula.Equals("Energia2")) {
        return GetWorld()->SpawnActor<ACapsulaEnergia2>(ACapsulaEnergia2::StaticClass());
    }
    else if (NombreTipoCapsula.Equals("Vida1")) {
        return GetWorld()->SpawnActor<ACapsulaVida01>(ACapsulaVida01::StaticClass());
    }

    return nullptr;
}