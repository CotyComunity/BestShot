// Fill out your copyright notice in the Description page of Project Settings.


#include "TestUI.h"
#include "MyGame1/Player/CharacterController.h"
#include "Components/GridPanel.h"


//------------------------------------------------
// 表示するときに呼ばれる
//------------------------------------------------
void UTestUI::NativeConstruct()
{
	Super::NativeConstruct();

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
	}
	else {
		Tutorial1->SetVisibility(ESlateVisibility::Visible);
		Tutorial2->SetVisibility(ESlateVisibility::Collapsed);
	}
}
