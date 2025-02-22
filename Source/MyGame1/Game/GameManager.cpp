// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "MyGame1/UI/MenuManager.h"


//------------------------------------------------
// 初期化
//------------------------------------------------
void UGameManager::Initialize(FSubsystemCollectionBase& Collection)
{
	UGameInstanceSubsystem::Initialize(Collection);
}

//------------------------------------------------
// ゲーム起動時にBPから呼び出される
//------------------------------------------------
void UGameManager::BeginPlay()
{
	if (UMenuManager* Manager = GetWorld()->GetGameInstance()->GetSubsystem<UMenuManager>())
	{
		Manager->SetupTestUI();
	}
}