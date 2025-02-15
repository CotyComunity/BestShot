// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// includeの順番でエラーが出ることがあるから注意
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TestUI.generated.h"

// 基本は前方宣言
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
	// 表示するときに呼ばれる
	virtual void NativeConstruct() final;

	// テキストの表示更新
	void SetupText(bool IsPullGun);

	// 銃を撃った時のアニメーション再生
	void GunShot();

private:
	// アニメーション再生
	void Play(AnimType Type);

private:
	UPROPERTY()
	TSoftObjectPtr<UGridPanel> Tutorial1 = nullptr;

	UPROPERTY()
	TSoftObjectPtr<UGridPanel> Tutorial2 = nullptr;

	// アニメーションはTransientのプロパティが必須
	UPROPERTY(Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* In01 = nullptr;
	UPROPERTY(Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* In02 = nullptr;
	UPROPERTY(Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* Shot = nullptr;
};
