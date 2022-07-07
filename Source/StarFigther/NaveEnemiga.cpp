// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemiga.h"
#include "Proyectil.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "StateParalisis.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

ANaveEnemiga::ANaveEnemiga()
{

	// Movement
	MoveSpeed = 1000.0f;
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = false;

	//AI del enemigo
	AIPerComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AI Perception Component"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));

	Energy = 100.0f;

	// Weapon

	SightConfig->SightRadius = 1250.0f;
	SightConfig->LoseSightRadius = 1280.0f;
	SightConfig->PeripheralVisionAngleDegrees = 120.0f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->SetMaxAge(0.1f);

	AIPerComp->ConfigureSense(*SightConfig);
	AIPerComp->SetDominantSense(SightConfig->GetSenseImplementation());
	AIPerComp->OnPerceptionUpdated.AddDynamic(this, &ANaveEnemiga::OnSensed);

	//CurrentVelocity = FVector::ZeroVector;


}

void ANaveEnemiga::BeginPlay()
{
	//BaseLocation = this->GetActorLocation();
}

void ANaveEnemiga::Tick(float DeltaSeconds)
{
	//const float ForwardValue = 1 ;
	//const float RightValue = GetInputAxisValue(MoveRightBinding);

	/*if (ForwardValue != 0.0f || RightValue != 0.0f) {

		if (ForwardValue != FireForwardValue) {
			FireForwardValue = ForwardValue;
		}

		if (RightValue != FireRightValue) {
			FireRightValue = RightValue;
		}
	}*/

	//UE_LOG(LogTemp, Warning, TEXT("ForwardValue: %f RightValue: %f"), ForwardValue, RightValue);

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions

	const FVector MoveDirection = FVector(-0.20f, 0.0f, 0.f);


	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
		//RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
		/*
		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}*/
	}

}

void ANaveEnemiga::Fire() {
	bCanFire = true;
	/*UE_LOG(LogTemp, Warning, TEXT("Se presiono la barra espaciadora"));
	// Create fire direction vector

	UE_LOG(LogTemp, Warning, TEXT("FireForwardValue: %f FireRightValue: %f"), FireForwardValue, FireRightValue);
	*/
	const FVector FireDirection = FVector(0.0f, 1.0f, 0.f);
	//const FVector FireDirection = GetActorLocation();
	// Try and fire a shot
	//FireShot(FireDirection);
}

/*void ANaveEnemiga::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{

		// If we are pressing fire stick in a direction
		//if (FireDirection.SizeSquared() > 0.0f)
		//{
		const FRotator FireRotation = FireDirection.Rotation();
		// Spawn projectile at an offset from this pawn
		const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			//Haciendo colision
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride =
				ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

			// spawn the projectile
			World->SpawnActor<AProyectil>(SpawnLocation, FireRotation, ActorSpawnParams);
			//UE_LOG(LogTemp, Warning, TEXT("SpawnLocation(X, Y) = %s, %s FireRotation(X, Y) =  s, s"), SpawnLocation.X, SpawnLocation.Y);
			//UE_LOG(LogTemp, Warning, TEXT("World not nullptr"));
		}

		//bCanFire = false;
		World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveEnemiga::ShotTimerExpired, FireRate);

		bCanFire = false;
		//}
	}
}*/

void ANaveEnemiga::ShotTimerExpired()
{
	bCanFire = true;
}

void ANaveEnemiga::OnSensed(const TArray<AActor*>& UpdatedActors)
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

			bCanFire = true;
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset) - FVector(0.0f, -10.0f, 0.f);
			//const FVector SpawnLocation2 = GetActorLocation() + FireRotation.RotateVector(GunOffset) + FVector(0.0f, 10.0f, 0.f);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				World->SpawnActor<AProyectil>(SpawnLocation, FireRotation);
				//World->SpawnActor<AProyectil>(SpawnLocation2, FireRotation);
				//UE_LOG(LogTemp, Warning, TEXT("SpawnLocation(X, Y) = %s, %s FireRotation(X, Y) =  s, s"), SpawnLocation.X, SpawnLocation.Y);
				//UE_LOG(LogTemp, Warning, TEXT("World not nullptr"));
			}
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveEnemiga::ShotTimerExpired, FireRate);

			if (FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			}
		}
		else
		{

		}
	}
}

void ANaveEnemiga::SetNewRotation(FVector TargetPosition, FVector CurrentPosition)
{
	FVector NewDirection = TargetPosition - CurrentPosition;
	NewDirection.Z = 0.0f;

	EnemyRotation = NewDirection.Rotation();

	SetActorRotation(EnemyRotation);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void ANaveEnemiga::AlterManeuvers(ANave* myBattleStrategy)
{
	//Try to cast the passed Strategy and set it to the current one
	BattleStrategy = Cast<INaveEnemigaStrategy>(myBattleStrategy);
	//Log Error if the cast failed
	if (!BattleStrategy)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red,TEXT("Invalid Cast! See Output log for more details"));
		UE_LOG(LogTemp, Error, TEXT("AlterManeuvers(): The Actor is not a BattleShipStrategy!Are you sure that the Actor implements that interface ? "));
	}
}
void ANaveEnemiga::Engage()
{
	//Log Error if the current Strategy is NULL
	if (!BattleStrategy) {
		UE_LOG(LogTemp, Error, TEXT("Engage(): BattleStrategy is NULL, make sure it's initialized.")); return; }
			//Execute the current Strategy Maneuver
			BattleStrategy->Maneuver();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void ANaveEnemiga::Initialize()
{
	StateParalisis = GetWorld()->SpawnActor<AStateParalisis>(AStateParalisis::StaticClass());
	StateParalisis->SetNaveEnemiga(this);
}

void ANaveEnemiga::Movimiento()
{
	State->Movimiento();
	MoveSpeed=0;
}

IState* ANaveEnemiga::GetState()
{
	return State;
}

IState* ANaveEnemiga::GetStateParalisis()
{
	return StateParalisis;
}

void ANaveEnemiga::SetState(IState* myState)
{
	State = myState;
}

FString ANaveEnemiga::GetCurrentState()
{
	//Returns the 'Name' of current State
	return "Actual Nave State: " + State->ToString();
}