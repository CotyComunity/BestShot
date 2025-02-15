// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MenuManager.generated.h"

/**
 * 
 */
UCLASS()
class MYGAME1_API UMenuManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	// ������
	virtual void Initialize(FSubsystemCollectionBase& Collection) { UGameInstanceSubsystem::Initialize(Collection); };

	// �j��
	virtual void Deinitialize() { UGameInstanceSubsystem::Deinitialize(); };

public:
	// TestUI�̏�����
	void SetupTestUI();

	// TestUI�̍X�V
	void PullGun();

	// ����������UI�X�V
	void GunShot();

private:
	TSoftObjectPtr<class UTestUI> TestUIPtr = nullptr;
};
