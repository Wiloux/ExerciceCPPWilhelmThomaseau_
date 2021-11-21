// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/DecalActor.h"
#include "Components/DecalComponent.h"
#include "BallOfPaint.h"


ABallOfPaint::ABallOfPaint()
{
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent){
		CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
		CollisionComponent->InitSphereRadius(10.0f);
		RootComponent = CollisionComponent;
	}

	if (!ProjectileMovementComponent) {
		ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
		ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
		ProjectileMovementComponent->InitialSpeed = 3000.0f;
		ProjectileMovementComponent->MaxSpeed = 3000.0f;
		ProjectileMovementComponent->bRotationFollowsVelocity = true;
		ProjectileMovementComponent->bShouldBounce = true;
		ProjectileMovementComponent->Bounciness = 0.3f;
		ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
	}

	if (!ProjectileMeshComponent)
	{
		ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));
		static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/medalion-1.medalion-1'"));
		if (Mesh.Succeeded())
		{
			ProjectileMeshComponent->SetStaticMesh(Mesh.Object);
		}
	}


	OnActorBeginOverlap.AddDynamic(this, &ABallOfPaint::OnBeginEvent);

	ProjectileMeshComponent->SetRelativeScale3D(FVector(10.0f, 10.0f, 10.0f));
	ProjectileMeshComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABallOfPaint::BeginPlay()
{
	Super::BeginPlay();

}



// Called every frame
void ABallOfPaint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABallOfPaint::OnBeginEvent(class AActor* overlappedActor, class AActor* otherActor) {

	if (otherActor && otherActor != this) {
		ADecalActor* decal = GetWorld()->SpawnActor<ADecalActor>(otherActor->GetActorLocation(), FRotator());
		if (decal)
		{
			decal->SetDecalMaterial(ActionDecalToSpawn);
			decal->SetLifeSpan(2.0f);
			decal->GetDecal()->DecalSize = FVector(32.0f, 64.0f, 64.0f);
			//m_previousActionDecal = decal;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No decal spawned"));
		}
	}

}

void ABallOfPaint::FireBall()
{
	APlayerCameraManager* camManager = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;
	FVector camLocation = camManager->GetCameraLocation();
	FVector camForward = camManager->GetCameraRotation().Vector();

	ProjectileMovementComponent->Velocity = camForward * ProjectileMovementComponent->InitialSpeed;
}

