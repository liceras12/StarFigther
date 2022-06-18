// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GunOffset = FVector(90.f, 0.f, 0.f);

	// Static reference to the mesh to use for the projectile
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectilMeshAsset(TEXT("/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile"));

	// Create mesh component for the projectile sphere
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh0"));
	ProjectileMesh->SetStaticMesh(ProjectilMeshAsset.Object);
	ProjectileMesh->SetupAttachment(RootComponent);
	ProjectileMesh->BodyInstance.SetCollisionProfileName("Projectile");
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AGun::OnHit);		// set up a notification for when this component hits something
	RootComponent = ProjectileMesh;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement0"));
	ProjectileMovement->UpdatedComponent = ProjectileMesh;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.f; // No gravity

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;


	//AI del enemigo
	AIPerComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AI Perception Component"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));

	SightConfig->SightRadius = 1250.0f;
	SightConfig->LoseSightRadius = 1280.0f;
	SightConfig->PeripheralVisionAngleDegrees = 120.0f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->SetMaxAge(0.1f);

	AIPerComp->ConfigureSense(*SightConfig);
	AIPerComp->SetDominantSense(SightConfig->GetSenseImplementation());
	AIPerComp->OnPerceptionUpdated.AddDynamic(this, &AGun::OnSensed);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AGun::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 20.0f, GetActorLocation());
	}

	Destroy();
}

void AGun::Fire()
{
	UWorld* const World = GetWorld();
		// spawn the projectile
		World->SpawnActor<AGun>(FVector (50.0f, 50.0f, 150.0f), FRotator::ZeroRotator);
	//Print Fire log
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("Nuesta Torreta esta disparando"));
}
void AGun::OnSensed(const TArray<AActor*>& UpdatedActors)
{
	for (int i = 0; i < UpdatedActors.Num(); i++)
	{
		FActorPerceptionBlueprintInfo Info;
		AIPerComp->GetActorsPerception(UpdatedActors[i], Info);

		if (Info.LastSensedStimuli[0].WasSuccessfullySensed())
		{
			FVector dir = UpdatedActors[i]->GetActorLocation() - GetActorLocation();
			dir.Z = 0.0f;

			//CurrentVelocity = dir.GetSafeNormal() * MoveSpeed;

			SetNewRotation(UpdatedActors[i]->GetActorLocation(), GetActorLocation());

			const FVector FireDirection = dir.GetClampedToMaxSize(1.0f);
			//const FVector FireDirection = GetActorLocation();
			// Try and fire a shot
			//FireShot(FireDirection);

			
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset) - FVector(0.0f, -10.0f, 0.f);
			//const FVector SpawnLocation2 = GetActorLocation() + FireRotation.RotateVector(GunOffset) + FVector(0.0f, 10.0f, 0.f);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				World->SpawnActor<AGun>(SpawnLocation, FireRotation);
				//World->SpawnActor<AProyectil>(SpawnLocation2, FireRotation);
				//UE_LOG(LogTemp, Warning, TEXT("SpawnLocation(X, Y) = %s, %s FireRotation(X, Y) =  s, s"), SpawnLocation.X, SpawnLocation.Y);
				//UE_LOG(LogTemp, Warning, TEXT("World not nullptr"));
			}
			//World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AGun::ShotTimerExpired, FireRate);

			/*if (FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			}*/
		}
	}
}

void AGun::SetNewRotation(FVector TargetPosition, FVector CurrentPosition)
{
	FVector NewDirection = TargetPosition - CurrentPosition;
	NewDirection.Z = 0.0f;

	EnemyRotation = NewDirection.Rotation();

	SetActorRotation(EnemyRotation);
}

