// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAerea.h"
#include "SlingShot.h"
//#include "Subscriber.h"
//#include "Publisher.h"
//#include "InventoryComponent.h"
#include "NaveAereaJugador.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGTHER_API ANaveAereaJugador : public ANaveAerea//, public APublisher, public ISlingShot
{
	GENERATED_BODY()
	
	/** The camera */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

public:
	ANaveAereaJugador();
	

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		FVector GunOffset;

	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float FireRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* FireSound;

	/* Fire a shot in the specified direction */
	void FireShot(FVector FireDirection);

	/* Handler for the fire timer expiry */
	void ShotTimerExpired();

	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Fire();
	void Fire01();

	//void FireArma1();

	UPROPERTY()
		class UInventoryComponent* InventarioJugador;

	UFUNCTION()
		void TakeItem(class AInventoryActor* _InventoryItem);
	///
	/*UPROPERTY()
		class UInventoryComponent* InventarioArmaJugador;
	
	UFUNCTION()
		void TakeCapsula(class ACapsulaArma1* _InventoryCapsula);
		*/
	///

	UFUNCTION()
		void DropItem();

	UFUNCTION()
		virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, 
			bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	UFUNCTION()
		void ListarObjetosContenedor();

	UFUNCTION()
		void Probar();

	TMap<FString, int> ItemsPlayer;
	TMap<int32, float> TMapPrueba;

private:
	ISlingShot* SlingShot;


	/* Flag to control firing  */
	uint32 bCanFire : 1;

	/* Arma1 ->Ametralladora */
	uint32 Arma1 : 1;

	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;

	float FireForwardValue;
	float FireRightValue;


public:
	/** Returns CameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetCameraComponent() const { return CameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	//Set the Weapon Actor
	void SetSlingShot(AActor* SlingShotObj);
	//Fire with the SlingShot
	void Sling();


	//Observer
	//colocando partes de publisher
	/*private:
		//The Subscribers of this Publisher
		UPROPERTY()
			TArray<AActor*> Subscribers = TArray<AActor*>();

	public:
		//Add the pased Subscriber to the list
		virtual void Subscribe(AActor* Subscriber);
		//Remove the passed Subscriber from the list
		virtual void UnSubscribe(AActor* SubscriberToRemove);
		//Notify all the Subscribers that something has changed
		virtual void NotifySubscribers();

		void ActionNave(bool movimientodetec);

		bool movimiento = false;*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
