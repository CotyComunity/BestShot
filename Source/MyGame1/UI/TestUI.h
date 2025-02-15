// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// include�̏��ԂŃG���[���o�邱�Ƃ����邩�璍��
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TestUI.generated.h"

// ��{�͑O���錾
class UGridPanel;

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

private:
	UPROPERTY()
	TSoftObjectPtr<UGridPanel> Tutorial1 = nullptr;

	UPROPERTY()
	TSoftObjectPtr<UGridPanel> Tutorial2 = nullptr;
};
