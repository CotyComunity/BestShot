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

	// 初期化
	virtual void Initialize(FSubsystemCollectionBase& Collection) { UGameInstanceSubsystem::Initialize(Collection); };

	// 破棄
	virtual void Deinitialize() { UGameInstanceSubsystem::Deinitialize(); };

public:
	// TestUIの初期化
	void SetupTestUI();

	// TestUIの更新
	void PullGun();

	// 撃った時のUI更新
	void GunShot();

private:
	TSoftObjectPtr<class UTestUI> TestUIPtr = nullptr;
};
