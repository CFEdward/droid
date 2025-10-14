// Copyright Eduard Ciofu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "D_PlayerController.generated.h"

struct FInputActionValue;
class UInputAction;
class UInputMappingContext;

UCLASS()
class DROID_API AD_PlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	virtual void SetupInputComponent() override;

private:

	void Jump();
	void StopJumping();
	void Look(const FInputActionValue& Value);
	void Move(const FInputActionValue& Value);
	
	UPROPERTY(EditDefaultsOnly, Category = "Droid|Input")
	TArray<TObjectPtr<UInputMappingContext>> InputMappingContexts;
	
	UPROPERTY(EditDefaultsOnly, Category = "Droid|Input")
	TObjectPtr<UInputAction> JumpAction;
	UPROPERTY(EditDefaultsOnly, Category = "Droid|Input")
	TObjectPtr<UInputAction> LookAction;
	UPROPERTY(EditDefaultsOnly, Category = "Droid|Input")
	TObjectPtr<UInputAction> MoveAction;
};
