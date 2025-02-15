// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// includeの順番でエラーが出ることがあるから注意
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TestUI.generated.h"

// 基本は前方宣言
class UGridPanel;

/**
 * 
 */
UCLASS()
class UTestUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// 表示するときに呼ばれる
	virtual void NativeConstruct() final;

	// テキストの表示更新
	void SetupText(bool IsPullGun);

private:
	UPROPERTY()
	TSoftObjectPtr<UGridPanel> Tutorial1 = nullptr;

	UPROPERTY()
	TSoftObjectPtr<UGridPanel> Tutorial2 = nullptr;
};
