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
	
	// ‰Šú‰»
	virtual void Initialize(FSubsystemCollectionBase& Collection);

	// ”jŠü
	virtual void Deinitialize() { UGameInstanceSubsystem::Deinitialize(); };

public:
	// ƒQ[ƒ€‹N“®‚ÉBP‚©‚çŒÄ‚Ño‚³‚ê‚é
	UFUNCTION(BlueprintCallable, Category = "GameManager")
	void BeginPlay();

};
