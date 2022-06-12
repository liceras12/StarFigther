// Copyright Epic Games, Inc. All Rights Reserved.


#include "StarFigtherGameModeBase.h"
#include "GeneradorCapsulasArmas.h"
#include "GeneradorCapsulasEnergia.h"
#include "NaveAereaJugador.h"

AStarFigtherGameModeBase::AStarFigtherGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;

	DefaultPawnClass = ANaveAereaJugador::StaticClass();
}

void AStarFigtherGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float ProbabilidadAparicionCapsula = FMath::RandRange(0, 10000);
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Dentro de Tick")));
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %f"), ProbabilidadAparicionCapsula));

	if (ProbabilidadAparicionCapsula < 5.0f) {

		//Create the Shops
		AGeneradorCapsulas* GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasArmas>(AGeneradorCapsulasArmas::StaticClass());
		ACapsula* Capsula = GeneradorCapsulaArma->GetCapsula("Arma1");
		//GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasEnergia>(AGeneradorCapsulasEnergia::StaticClass());
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));

	}
	else if (ProbabilidadAparicionCapsula > 5.0f && ProbabilidadAparicionCapsula < 10.0f) {

		//Create the Shops
		AGeneradorCapsulas* GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasArmas>(AGeneradorCapsulasArmas::StaticClass());
		ACapsula* Capsula = GeneradorCapsulaArma->GetCapsula("Arma2");
		//GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasEnergia>(AGeneradorCapsulasEnergia::StaticClass());
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));

	}
	else if (ProbabilidadAparicionCapsula > 10.0f && ProbabilidadAparicionCapsula < 12.0f) {

		//Create the Shops
		AGeneradorCapsulas* GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasArmas>(AGeneradorCapsulasArmas::StaticClass());
		ACapsula* Capsula = GeneradorCapsulaArma->GetCapsula("Escudo1");
		//GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasEnergia>(AGeneradorCapsulasEnergia::StaticClass());
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));

	}
	else if (ProbabilidadAparicionCapsula > 12.0f && ProbabilidadAparicionCapsula < 18.0f) {

		//Create the Shops
		AGeneradorCapsulas* GeneradorCapsula = GetWorld()->SpawnActor<AGeneradorCapsulasEnergia>(AGeneradorCapsulasEnergia::StaticClass());
		ACapsula* Capsula = GeneradorCapsula->GetCapsula("Energia1");
		//GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasEnergia>(AGeneradorCapsulasEnergia::StaticClass());
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));

	}

}

void AStarFigtherGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Dentro de BeginPlay")));
}