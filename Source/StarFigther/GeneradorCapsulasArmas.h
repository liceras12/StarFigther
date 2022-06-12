// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GeneradorCapsulas.h"
#include "GeneradorCapsulasArmas.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGTHER_API AGeneradorCapsulasArmas : public AGeneradorCapsulas
{
	GENERATED_BODY()
	virtual ACapsula* FabricarCapsula(FString NombreTipoCapsula) override;
};
