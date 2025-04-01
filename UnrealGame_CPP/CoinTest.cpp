// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinTest.h"
#include "GameFramework/Character.h"
//#include "Kismet/GameplayStatics.h"

// Sets default values
ACoinTest::ACoinTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	SphereCollider = CreateDefaultSubobject<USphereComponent>("Sphere Collider");
	SetRootComponent(SphereCollider);
	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ACoinTest::OnBeginOverlapComponentEvent);



	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");

	SetRootComponent(MeshComponent);
	MeshComponent->SetupAttachment(SphereCollider);
	MeshComponent->SetGenerateOverlapEvents(false);

	RotatingMovementComponent = CreateDefaultSubobject<URotatingMovementComponent>("RotatingMovementComponent");

}

// Called when the game starts or when spawned
void ACoinTest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoinTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoinTest::OnBeginOverlapComponentEvent(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Destroy();
}

