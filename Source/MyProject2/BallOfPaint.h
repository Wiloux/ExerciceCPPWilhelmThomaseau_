// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/DecalActor.h"
#include "Components/DecalComponent.h"
#include "BallOfPaint.generated.h"

UCLASS()
class MYPROJECT2_API ABallOfPaint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallOfPaint();

	UFUNCTION()
	void FireBall();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		UStaticMeshComponent* ProjectileMeshComponent;
  // Sphere collision component.
    UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
    USphereComponent* CollisionComponent;

    // Projectile movement component.
    UPROPERTY(VisibleAnywhere, Category = Movement)
    UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(VisibleAnywhere)
	UMaterialInterface* ActionDecalToSpawn;


	UFUNCTION()
		void OnBeginEvent(class AActor* overlappedActor, class AActor* otherActor);
};
