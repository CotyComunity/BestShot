// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuManager.h"
#include "TestUI.h"
#include "Blueprint/UserWidget.h"

//------------------------------------------------
// TestUIの初期化
//------------------------------------------------
void UMenuManager::SetupTestUI()
{
	// 初回起動時に呼び出す
	// プレイヤーが銃取った時に切り替えやる

	FString Path = TEXT("/Game/BestShot/Test/UI/WBP_TestUI.WBP_TestUI_C");
	TSubclassOf<UTestUI> WidgetClass = TSoftClassPtr<UTestUI>(FSoftObjectPath(*Path)).LoadSynchronous();
	TestUIPtr = CreateWidget<UTestUI>(GetWorld(), WidgetClass);

	if (UTestUI* TestUI = TestUIPtr.LoadSynchronous())
	{
		TestUI->AddToViewport();
	}
}

//------------------------------------------------
// TestUIの更新
//------------------------------------------------
void UMenuManager::PullGun()
{
	if (UTestUI* TestUI = TestUIPtr.LoadSynchronous())
	{
		TestUI->SetupText(true);
	}
}

//------------------------------------------------
// 撃った時のUI更新
//------------------------------------------------
void UMenuManager::GunShot()
{
	if (UTestUI* TestUI = TestUIPtr.LoadSynchronous())
	{
		TestUI->GunShot();
	}
}
