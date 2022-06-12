// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneradorCapsulasArmas.h"
#include "CapsulaArma1.h"
#include "CapsulaArma2.h"
#include "CapsulaEscudo1.h"

ACapsula* AGeneradorCapsulasArmas::FabricarCapsula(FString NombreTipoCapsula)
{
    if (NombreTipoCapsula.Equals("Arma1")) {
        return GetWorld()->SpawnActor<ACapsulaArma1>(ACapsulaArma1::StaticClass());
    }
    else if (NombreTipoCapsula.Equals("Arma2")) {
        return GetWorld()->SpawnActor<ACapsulaArma2>(ACapsulaArma2::StaticClass());
    }
    else if (NombreTipoCapsula.Equals("Escudo1")) {
        return GetWorld()->SpawnActor<ACapsulaEscudo1>(ACapsulaEscudo1::StaticClass());
    }

    return nullptr;
}
