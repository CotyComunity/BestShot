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
	
	// ������
	virtual void Initialize(FSubsystemCollectionBase& Collection);

	// �j��
	virtual void Deinitialize() { UGameInstanceSubsystem::Deinitialize(); };

public:
	// �Q�[���N������BP����Ăяo�����
	UFUNCTION(BlueprintCallable, Category = "GameManager")
	void BeginPlay();

};
