// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterController.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACharacterController::ACharacterController()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (UCapsuleComponent* Comp = GetCapsuleComponent()) {
		Comp->OnComponentBeginOverlap.AddDynamic(this, &ACharacterController::OnOverlapBegin);
	}
}

// Called when the game starts or when spawned
void ACharacterController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACharacterController::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
#if WITH_EDITOR
	// ‚¤‚Á‚©‚è—Ž‚¿‚½‚ç‚ß‚ñ‚Ç‚­‚³‚¢‚©‚ç
	if (!OtherActor) {
		return;
	}
#endif

	FString Text = OtherActor->GetName();
	UKismetSystemLibrary::PrintString(this, *Text, true, true, FColor::Cyan, 2.f, TEXT("None"));
}

