// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageOnTick.h"
#include "MyProject2Character.h"
#include "Components/CapsuleComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
ADamageOnTick::ADamageOnTick()
{
	//// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = false;

	//Box = CreateDefaultSubobject<UBoxComponent>(this, TEXT("Box"));
	//Light = CreateDefaultSubobject<UPointLightComponent>(this, TEXT("Light"));
	//Box->bGenerateOverlapEvents = true;
	//Box->SetRelativeScale3D(FVector(2, 2, 5));
	//RootComponent = Box;
	//Light->Intensity = 10000;
	//Light->SetLightColor(FColor::Red);
	//Light->AttachParent = RootComponent;

	//TriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &ADamageOnTick::OnOverlapBegin);
	//TriggerCapsule->OnComponentEndOverlap.AddDynamic(this, &ADamageOnTick::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ADamageOnTick::BeginPlay()
{
	Super::BeginPlay();

	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, 999, 0, 5);

}

// Called every frame
void ADamageOnTick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//
//void ADamageOnTick::OnOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult)
//{
//
//	AMyProject2Character* c = Cast<AMyProject2Character>(OtherActor);
//	UE_LOG(LogTemp, Warning, TEXT("Hamburger"));
//
//
//	if (OtherActor && (OtherActor != this) && OtherComp)
//	{
//		if (c == nullptr || OtherActor == this) //< if (!Character)
//			return;
//
//		UE_LOG(LogTemp, Warning, TEXT("Hamburger"));
//
//		c->StartStopDmgTimer(true);
//	}
//}
//
//void ADamageOnTick::OnOverlapEnd(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
//{
//	if (OtherActor && (OtherActor != this) && OtherComp)
//	{
//		AMyProject2Character* c = Cast<AMyProject2Character>(OtherActor);
//		if (c == nullptr || OtherActor == this) //< if (!Character)
//			return;
//
//		UE_LOG(LogTemp, Warning, TEXT("Fart"));
//
//		c->StartStopDmgTimer(false);
//	}
//}

