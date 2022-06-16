// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaArma1.h"

#include "Components/StaticMeshComponent.h"
#include "Engine/CollisionProfile.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ACapsulaArma1::ACapsulaArma1()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/Sphere.Sphere'"));

	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsulaMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = CapsulaMeshComponent;
	CapsulaMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	CapsulaMeshComponent->SetStaticMesh(ShipMesh.Object);
	SetActorEnableCollision(true);
}

// Called when the game starts or when spawned
void ACapsulaArma1::BeginPlay()
{
	Super::BeginPlay();

	Nombre = "Capsula arma 01";
	TipoCapsula = "Capasula de ametralladora"; //Vida, Energia, Armadura, Armas, ....
	TipoEfecto = "Incrementa numero y velocidad balas"; //Egregar salud, agregar arma
	TipoDuracion = "Mientra este activo";
	TiempoDuracion = 10.0f;

	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &ACapsulaArma1::Destruir, TiempoDuracion);
}

void ACapsulaArma1::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, TEXT("Generando una capsula de arma01"));
}

void ACapsulaArma1::Destruir()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se esta destruyendo la capsula")));
	Destroy();
}

void ACapsulaArma1::PickUp()
{
	SetActorTickEnabled(false);
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}
