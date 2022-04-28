// Copyright Epic Games, Inc. All Rights Reserved.


#include "StarFigtherGameModeBase.h"
#include "NaveAereaJugador.h"

AStarFigtherGameModeBase::AStarFigtherGameModeBase()
{
	DefaultPawnClass = ANaveAereaJugador::StaticClass();
}
