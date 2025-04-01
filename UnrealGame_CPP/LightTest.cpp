// Fill out your copyright notice in the Description page of Project Settings.


#include "LightTest.h"
#include "Components/SceneComponent.h"

// Sets default values
ALightTest::ALightTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DesiredIntensity = 5000.0f;
	PointLight1 = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light_CPP"));
	PointLight1->Intensity = DesiredIntensity;
	PointLight1->LightColor = FColor(128, 0, 255);
	//PointLight1->bVisible = false;
	RootComponent = PointLight1;

	Sphere1 = CreateDefaultSubobject<USphereComponent>(TEXT("LightSphere"));
	Sphere1->InitSphereRadius(250.0f);
	Sphere1->SetupAttachment(RootComponent);

	Sphere1->OnComponentBeginOverlap.AddDynamic(this, &ALightTest::OnOverlapBegin);		// set up a notification for when this component overlaps something
	Sphere1->OnComponentEndOverlap.AddDynamic(this, &ALightTest::OnOverlapEnd);		// set up a notification for when this component overlaps something



}

// Called when the game starts or when spawned
void ALightTest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALightTest::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}

void ALightTest::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}

void ALightTest::ToggleLight()
{
	PointLight1->ToggleVisibility();
}