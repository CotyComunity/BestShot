// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterController.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetSystemLibrary.h"

#include "MyGame1/UI/MenuManager.h"

//------------------------------------------------
// コンストラクタ
//------------------------------------------------
ACharacterController::ACharacterController()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 当たり判定用のコールバックを登録
	if (UCapsuleComponent* Comp = GetCapsuleComponent()) {
		Comp->OnComponentBeginOverlap.AddDynamic(this, &ACharacterController::OnOverlapBegin);
	}
}

//------------------------------------------------
// 実行時に呼ばれる
//------------------------------------------------
void ACharacterController::BeginPlay()
{
	Super::BeginPlay();
	
}

//------------------------------------------------
// 更新時に呼ばれる
//------------------------------------------------
void ACharacterController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//------------------------------------------------
// Called to bind functionality to input
//------------------------------------------------
void ACharacterController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//------------------------------------------------
// 重なった時に呼ばれる
//------------------------------------------------
void ACharacterController::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
#if WITH_EDITOR
	// うっかり落ちたらめんどくさいから
	if (!OtherActor) {
		return;
	}
#endif

	if (OtherActor->ActorHasTag("Gun")) {
		if (UMenuManager* Manager = GetWorld()->GetGameInstance()->GetSubsystem<UMenuManager>())
		{
			Manager->PullGun();
		}
	}
#if TestDelegate
	if (OnOverlapBeginDelegate.IsBound()) {
		OnOverlapBeginDelegate.Broadcast(OtherActor);
	}
#endif
}

#if TestDelegate
#pragma region Delegate
//------------------------------------------------
// 当たり判定の登録
//------------------------------------------------
void ACharacterController::SetOnOverlapBegin(FOnOverlapBeginDelegate::FDelegate Delegate)
{
	OnOverlapBeginDelegate.AddUnique(Delegate);
}
#pragma endregion
#endif
