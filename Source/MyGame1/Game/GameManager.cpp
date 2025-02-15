// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "MyGame1/UI/MenuManager.h"


//------------------------------------------------
// ������
//------------------------------------------------
void UGameManager::Initialize(FSubsystemCollectionBase& Collection)
{
	UGameInstanceSubsystem::Initialize(Collection);
}

//------------------------------------------------
// �Q�[���N������BP����Ăяo�����
//------------------------------------------------
void UGameManager::BeginPlay()
{
	if (UMenuManager* Manager = GetWorld()->GetGameInstance()->GetSubsystem<UMenuManager>())
	{
		Manager->SetupTestUI();
	}
}