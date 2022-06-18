// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class STARFIGTHER_API AGun : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* ProjectileMesh;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
		class UProjectileMovementComponent* ProjectileMovement;
public:	
	// Sets default values for this actor's properties
	AGun();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* FireSound;

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		FVector GunOffset;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns ProjectileMesh subobject **/
	FORCEINLINE UStaticMeshComponent* GetProjectilMesh() const { return ProjectileMesh; }
	/** Returns ProjectileMovement subobject **/
	FORCEINLINE UProjectileMovementComponent* GetProjectilMovement() const { return ProjectileMovement; }

	//AI del enemigo
	UPROPERTY(VisibleDefaultsOnly, Category = enemy)
		class UAIPerceptionComponent* AIPerComp;

	UPROPERTY(VisibleDefaultsOnly, Category = enemy)
		class UAISenseConfig_Sight* SightConfig;

	UFUNCTION()
		void OnSensed(const TArray<AActor*>& UpdatedActors);

	UPROPERTY(VisibleAnywhere, Category = Movement)
		FRotator EnemyRotation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
		FRotator CurrentVelocity;

	UPROPERTY(VisibleAnywhere, Category = Movement)
		FRotator BaseLocation;

	void SetNewRotation(FVector TargetPosition, FVector CurrentPosition);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Fire with the gun
	void Fire();
};
