// Fill out your copyright notice in the Description page of Project Settings.


#include "StarFigtherPlayerController.h"


void AStarFigtherPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//float ProbabilidadAparicionCapsula = FMath::RandRange(0, 1);
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Dentro de Tick")));
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %f"), ProbabilidadAparicionCapsula));

	//if (ProbabilidadAparicionCapsula > 0.1f) {

	//	//Create the Shops
	//	AGeneradorCapsulas* GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasArmas>(AGeneradorCapsulasArmas::StaticClass());
	//	ACapsula* Capsula = GeneradorCapsulaArma->GetCapsula("Arma1");
	//	//GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasEnergia>(AGeneradorCapsulasEnergia::StaticClass());
	//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));

	//}
}
