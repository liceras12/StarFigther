// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaArma2.h"

#include "Components/StaticMeshComponent.h"
#include "Engine/CollisionProfile.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ACapsulaArma2::ACapsulaArma2()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/Sphere1.Sphere1'"));

	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsulaMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = CapsulaMeshComponent;
	CapsulaMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	CapsulaMeshComponent->SetStaticMesh(ShipMesh.Object);
}

// Called when the game starts or when spawned
void ACapsulaArma2::BeginPlay()
{
	Super::BeginPlay();
	Nombre = "Capsula arma 02";
	TipoCapsula = "Capasula de rifle"; //Vida, Energia, Armadura, Armas, ....
	TipoEfecto = "Incrementa presicion en el disparo"; //Egregar salud, agregar arma
	TipoDuracion = "Mientra este activo";
	TiempoDuracion = 10.0f;

	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &ACapsulaArma2::Destruir, TiempoDuracion);
}

void ACapsulaArma2::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, TEXT("Generando una capsula de arma02"));
}

void ACapsulaArma2::Destruir()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se esta destruyendo la capsula")));
	Destroy();
}
