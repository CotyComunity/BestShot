// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// include�̏��ԂŃG���[���o�邱�Ƃ����邩�璍��
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TestUI.generated.h"

// ��{�͑O���錾
class UGridPanel;
class UWidgetAnimation;

enum class AnimType
{
	AnimIn01,
	AnimIn02,
	AnimShot,
};


/**
 * 
 */
UCLASS()
class UTestUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// �\������Ƃ��ɌĂ΂��
	virtual void NativeConstruct() final;

	// �e�L�X�g�̕\���X�V
	void SetupText(bool IsPullGun);

	// �e�����������̃A�j���[�V�����Đ�
	void GunShot();

private:
	// �A�j���[�V�����Đ�
	void Play(AnimType Type);

private:
	UPROPERTY()
	TSoftObjectPtr<UGridPanel> Tutorial1 = nullptr;

	UPROPERTY()
	TSoftObjectPtr<UGridPanel> Tutorial2 = nullptr;

	// �A�j���[�V������Transient�̃v���p�e�B���K�{
	UPROPERTY(Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* In01 = nullptr;
	UPROPERTY(Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* In02 = nullptr;
	UPROPERTY(Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* Shot = nullptr;
};
