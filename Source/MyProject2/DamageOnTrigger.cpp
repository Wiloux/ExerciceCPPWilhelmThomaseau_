// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageOnTrigger.h"
#include "MyProject2Character.h"

ADamageOnTrigger::ADamageOnTrigger() {

	OnActorBeginOverlap.AddDynamic(this, &ADamageOnTrigger::OnBeginEvent);
	OnActorEndOverlap.AddDynamic(this, &ADamageOnTrigger::OnLeaveEvent);
}

void ADamageOnTrigger::BeginPlay() {

	Super::BeginPlay();
}

void ADamageOnTrigger::OnBeginEvent(class AActor* overlappedActor, class AActor* otherActor) {

	if (otherActor && otherActor != this) {

			AMyProject2Character* c = Cast<AMyProject2Character>(otherActor);
			if (c == nullptr || otherActor == this) //< if (!Character)
				return;

			c->StartStopDmgTimer(true);
	}

}

void ADamageOnTrigger::OnLeaveEvent(class AActor* overlappedActor, class AActor* otherActor) {

	if (otherActor && otherActor != this) {

		AMyProject2Character* c = Cast<AMyProject2Character>(otherActor);
		if (c == nullptr || otherActor == this) //< if (!Character)
			return;

		c->StartStopDmgTimer(false);
	}

}

