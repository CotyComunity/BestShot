// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameManager.generated.h"

/**
 * 
 */
UCLASS()
class MYGAME1_API UGameManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	// 初期化
	virtual void Initialize(FSubsystemCollectionBase& Collection);

	// 破棄
	virtual void Deinitialize() { UGameInstanceSubsystem::Deinitialize(); };

public:
	// ゲーム起動時にBPから呼び出される
	UFUNCTION(BlueprintCallable, Category = "GameManager")
	void BeginPlay();

};
