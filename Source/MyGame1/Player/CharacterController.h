// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterController.generated.h"

#define TestDelegate false	// インターフェースにするか、Managerに移す

#if TestDelegate
#pragma region Delegate
//---
// デリゲートの作成 : https://dokuro.moe/ue4-cpp-how-to-use-delegate/
//---
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOverlapBeginDelegate);
#pragma endregion
#endif

UCLASS()
class MYGAME1_API ACharacterController : public ACharacter
{
	GENERATED_BODY()

public:
	// コンストラクタ
	ACharacterController();

protected:
	// 実行時に呼ばれる
	virtual void BeginPlay() override;

public:	
	// 更新時に呼ばれる
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// 重なった時に呼ばれる
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

#if TestDelegate
#pragma region Delegate
	// 当たり判定の登録
	void SetOnOverlapBegin(FOnOverlapBeginDelegate::FDelegate Delegate);
#pragma endregion
#endif
private:



#if TestDelegate
#pragma region Delegate
	FOnOverlapBeginDelegate OnOverlapBeginDelegate;
#pragma endregion
#endif
};
