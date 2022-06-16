// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneradorCapsulasArmas.h"
#include "CapsulaArma1.h"
#include "CapsulaArma2.h"
#include "CapsulaEscudo1.h"

ACapsula* AGeneradorCapsulasArmas::FabricarCapsula(FString NombreTipoCapsula)
{
    float UbicacionAparicionCapsulax = FMath::RandRange(-1000, 1000);
    float UbicacionAparicionCapsulay = FMath::RandRange(-1000, 1000);

    if (NombreTipoCapsula.Equals("Arma1")) {
        return GetWorld()->SpawnActor<ACapsulaArma1>(FVector(UbicacionAparicionCapsulax, UbicacionAparicionCapsulay, 150.0f), FRotator::ZeroRotator);
    }
    else if (NombreTipoCapsula.Equals("Arma2")) {
        return GetWorld()->SpawnActor<ACapsulaArma2>(FVector(UbicacionAparicionCapsulax, UbicacionAparicionCapsulay, 150.0f), FRotator::ZeroRotator);
    }
    else if (NombreTipoCapsula.Equals("Escudo1")) {
        return GetWorld()->SpawnActor<ACapsulaEscudo1>(FVector(UbicacionAparicionCapsulax, UbicacionAparicionCapsulay, 150.0f), FRotator::ZeroRotator);
    }

    return nullptr;
}
