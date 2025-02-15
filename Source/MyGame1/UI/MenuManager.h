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

	// ‰Šú‰»
	virtual void Initialize(FSubsystemCollectionBase& Collection) { UGameInstanceSubsystem::Initialize(Collection); };

	// ”jŠü
	virtual void Deinitialize() { UGameInstanceSubsystem::Deinitialize(); };

public:
	// TestUI‚Ì‰Šú‰»
	void SetupTestUI();

	// TestUI‚ÌXV
	void PullGun();


private:
	TSoftObjectPtr<class UTestUI> TestUIPtr = nullptr;
};
