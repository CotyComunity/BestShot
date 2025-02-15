// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterController.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/PlayerInput.h"
#include "Kismet/KismetSystemLibrary.h"

#include "MyGame1/UI/MenuManager.h"

//------------------------------------------------
// �R���X�g���N�^
//------------------------------------------------
ACharacterController::ACharacterController()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// �����蔻��p�̃R�[���o�b�N��o�^
	if (UCapsuleComponent* Comp = GetCapsuleComponent()) {
		Comp->OnComponentBeginOverlap.AddDynamic(this, &ACharacterController::OnOverlapBegin);
	}
}

//------------------------------------------------
// ���s���ɌĂ΂��
//------------------------------------------------
void ACharacterController::BeginPlay()
{
	Super::BeginPlay();
	
}

//------------------------------------------------
// �X�V���ɌĂ΂��
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

	// �����o�^���Ă���G���n���X����擾�o����
	UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("Shooting", EKeys::LeftMouseButton));
	PlayerInputComponent->BindAction("Shooting", IE_Pressed, this, &ACharacterController::OnGunShot);
}

//------------------------------------------------
// �ˌ���
//------------------------------------------------
void ACharacterController::OnGunShot()
{
	if (!IsPullGun) {
		return;
	}
	if (UMenuManager* Manager = GetWorld()->GetGameInstance()->GetSubsystem<UMenuManager>())
	{
		Manager->GunShot();
	}
}

//------------------------------------------------
// �d�Ȃ������ɌĂ΂��
//------------------------------------------------
void ACharacterController::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
#if WITH_EDITOR
	// �������藎������߂�ǂ���������
	if (!OtherActor) {
		return;
	}
#endif

	if (OtherActor->ActorHasTag("Gun")) {
		IsPullGun = true;
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
// �����蔻��̓o�^
//------------------------------------------------
void ACharacterController::SetOnOverlapBegin(FOnOverlapBeginDelegate::FDelegate Delegate)
{
	OnOverlapBeginDelegate.AddUnique(Delegate);
}
#pragma endregion
#endif
