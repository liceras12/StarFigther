// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneradorCapsulasEnergia.h"
#include "CapsulaEnergia01.h"
#include "CapsulaEnergia2.h"
#include "CapsulaVida01.h"


ACapsula* AGeneradorCapsulasEnergia::FabricarCapsula(FString NombreTipoCapsula)
{
    float UbicacionAparicionCapsulax = FMath::RandRange(-1000, 1000);
    float UbicacionAparicionCapsulay = FMath::RandRange(-1000, 1000);

    if (NombreTipoCapsula.Equals("Energia1")) {
        return GetWorld()->SpawnActor<ACapsulaEnergia01>(FVector(UbicacionAparicionCapsulax, UbicacionAparicionCapsulay, 150.0f), FRotator::ZeroRotator);
    }
    else if (NombreTipoCapsula.Equals("Energia2")) {
        return GetWorld()->SpawnActor<ACapsulaEnergia2>(FVector(UbicacionAparicionCapsulax, UbicacionAparicionCapsulay, 150.0f), FRotator::ZeroRotator);
    }
    else if (NombreTipoCapsula.Equals("Vida1")) {
        return GetWorld()->SpawnActor<ACapsulaVida01>(FVector(UbicacionAparicionCapsulax, UbicacionAparicionCapsulay, 150.0f), FRotator::ZeroRotator);
    }

    return nullptr;
}