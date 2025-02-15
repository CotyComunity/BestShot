// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "MyGame1/UI/MenuManager.h"


//------------------------------------------------
// ‰Šú‰»
//------------------------------------------------
void UGameManager::Initialize(FSubsystemCollectionBase& Collection)
{
	UGameInstanceSubsystem::Initialize(Collection);
}

//------------------------------------------------
// ƒQ[ƒ€‹N“®Žž‚ÉBP‚©‚çŒÄ‚Ño‚³‚ê‚é
//------------------------------------------------
void UGameManager::BeginPlay()
{
	if (UMenuManager* Manager = GetWorld()->GetGameInstance()->GetSubsystem<UMenuManager>())
	{
		Manager->SetupTestUI();
	}
}