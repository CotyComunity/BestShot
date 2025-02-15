// Fill out your copyright notice in the Description page of Project Settings.


#include "TestUI.h"
#include "MyGame1/Player/CharacterController.h"
#include "Animation/WidgetAnimation.h"
#include "Components/GridPanel.h"


//------------------------------------------------
// 表示するときに呼ばれる
//------------------------------------------------
void UTestUI::NativeConstruct()
{
	UUserWidget::NativeConstruct();

	check(Tutorial1);
	check(Tutorial2);

	SetupText(false);

#if TestDelegate
	FOnOverlapBeginDelegate::FDelegate OnOverlapBeginDelegate;
	OnOverlapBeginDelegate.BindUFunction(this, "PullGun");
	//SetOnOverlapBegin
#endif
}

//------------------------------------------------
// テキストの表示更新
//------------------------------------------------
void UTestUI::SetupText(bool IsPullGun)
{
	if (IsPullGun) {
		Tutorial1->SetVisibility(ESlateVisibility::Collapsed);
		Tutorial2->SetVisibility(ESlateVisibility::Visible);
		Play(AnimType::AnimIn02);
	}
	else {
		Tutorial1->SetVisibility(ESlateVisibility::Visible);
		Tutorial2->SetVisibility(ESlateVisibility::Collapsed);
		Play(AnimType::AnimIn01);
	}
}

//------------------------------------------------
// 銃を撃った時のアニメーション再生
//------------------------------------------------
void UTestUI::GunShot()
{
	Play(AnimType::AnimShot);
}

//------------------------------------------------
// アニメーション再生
//------------------------------------------------
void UTestUI::Play(AnimType Type)
{
	switch (Type) {
	case AnimType::AnimIn01:
		if (!IsAnimationPlaying(In01)) {
			PlayAnimation(In01, 0.0f, 0);
		}
		break;
	case AnimType::AnimIn02:
		if (!IsAnimationPlaying(In02)) {
			PlayAnimation(In02, 0.0f, 1);
		}
		break;
	case AnimType::AnimShot:
		if (IsAnimationPlaying(Shot)) {
			StopAnimation(Shot);
		}
		PlayAnimation(Shot, 0.0f, 1);
		break;
	}
}
