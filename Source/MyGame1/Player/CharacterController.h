// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterController.generated.h"

#define TestDelegate false	// �C���^�[�t�F�[�X�ɂ��邩�AManager�Ɉڂ�

#if TestDelegate
#pragma region Delegate
//---
// �f���Q�[�g�̍쐬 : https://dokuro.moe/ue4-cpp-how-to-use-delegate/
//---
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOverlapBeginDelegate);
#pragma endregion
#endif

UCLASS()
class MYGAME1_API ACharacterController : public ACharacter
{
	GENERATED_BODY()

public:
	// �R���X�g���N�^
	ACharacterController();

protected:
	// ���s���ɌĂ΂��
	virtual void BeginPlay() override;

public:	
	// �X�V���ɌĂ΂��
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// �d�Ȃ������ɌĂ΂��
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

#if TestDelegate
#pragma region Delegate
	// �����蔻��̓o�^
	void SetOnOverlapBegin(FOnOverlapBeginDelegate::FDelegate Delegate);
#pragma endregion
#endif
private:



#if TestDelegate
#pragma region Delegate
	FOnOverlapBeginDelegate OnOverlapBeginDelegate;
#pragma endregion
#endif
};
