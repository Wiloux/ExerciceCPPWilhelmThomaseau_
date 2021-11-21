// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamageOnTick.generated.h"

UCLASS()
class MYPROJECT2_API ADamageOnTick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADamageOnTick();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//TSubobjectPtr<UBoxComponent>Box;
	//TSubobjectPtr<UPointLightComponent>Light;


	//UFUNCTION()
	//	void OnOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult);
	//UFUNCTION()
	//	void OnEndOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	//UPROPERTY(VisibleAnywhere)
	//	int32 Damage;

	//UPROPERTY(VisibleAnywhere, Category = "Trigger Capsule")
	//	class UCapsuleComponent* TriggerCapsule;
};
