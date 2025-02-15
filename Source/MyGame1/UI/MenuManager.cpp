// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuManager.h"
#include "TestUI.h"
#include "Blueprint/UserWidget.h"

//------------------------------------------------
// TestUI�̏�����
//------------------------------------------------
void UMenuManager::SetupTestUI()
{
	// ����N�����ɌĂяo��
	// �v���C���[���e��������ɐ؂�ւ����

	FString Path = TEXT("/Game/BestShot/Test/UI/WBP_TestUI.WBP_TestUI_C");
	TSubclassOf<UTestUI> WidgetClass = TSoftClassPtr<UTestUI>(FSoftObjectPath(*Path)).LoadSynchronous();
	TestUIPtr = CreateWidget<UTestUI>(GetWorld(), WidgetClass);

	if (UTestUI* TestUI = TestUIPtr.LoadSynchronous())
	{
		TestUI->AddToViewport();
	}
}

//------------------------------------------------
// TestUI�̍X�V
//------------------------------------------------
void UMenuManager::PullGun()
{
	if (UTestUI* TestUI = TestUIPtr.LoadSynchronous())
	{
		TestUI->SetupText(true);
	}
}

//------------------------------------------------
// ����������UI�X�V
//------------------------------------------------
void UMenuManager::GunShot()
{
	if (UTestUI* TestUI = TestUIPtr.LoadSynchronous())
	{
		TestUI->GunShot();
	}
}
