// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "GameFrameWork/Actor.h"
#include "Engine/TriggerBox.h"
#include "DamageOnTrigger.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API ADamageOnTrigger : public ATriggerBox
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay();

public:
	ADamageOnTrigger();

	UFUNCTION()
	void OnBeginEvent(class AActor* overlappedActor, class AActor* otherActor);
	UFUNCTION()
	void OnLeaveEvent(class AActor* overlappedActor, class AActor* otherActor);

};
