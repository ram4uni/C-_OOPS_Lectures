// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Components/SphereComponent.h"


#include "CoinTest.generated.h"

UCLASS()
class OFFERDAY_TEST_API ACoinTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoinTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Coin Info")
	//UStaticMeshComponent* _MeshComponent;
	TObjectPtr<UStaticMeshComponent> MeshComponent;


	UPROPERTY(EditDefaultsOnly, Category = "Coin Info")
	URotatingMovementComponent* RotatingMovementComponent;
	//TObjectPtr<URotatingMovementComponent> RotatingMovementComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Coin Info")
	USphereComponent* SphereCollider;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UFUNCTION()
	void OnBeginOverlapComponentEvent(class UPrimitiveComponent* OverlappedComp,
		class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
