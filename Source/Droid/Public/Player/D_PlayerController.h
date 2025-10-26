// Copyright Eduard Ciofu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "D_PlayerController.generated.h"

struct FGameplayTag;
struct FInputActionValue;
class UInputAction;
class UInputMappingContext;

UCLASS()
class DROID_API AD_PlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	/** PlayerController Parent **/
	virtual void SetupInputComponent() override;
	/** end PlayerController Parent **/
	
private:

	void Jump();
	void StopJumping();
	void Look(const FInputActionValue& Value);
	void Move(const FInputActionValue& Value);

	void Primary();
	void Secondary();
	void Tertiary();
	
	void ActivateAbility(const FGameplayTag& AbilityTag) const;
	
	UPROPERTY(EditDefaultsOnly, Category = "Droid|Input")
	TArray<TObjectPtr<UInputMappingContext>> InputMappingContexts;
	
	UPROPERTY(EditDefaultsOnly, Category = "Droid|Input|Movement")
	TObjectPtr<UInputAction> JumpAction;
	UPROPERTY(EditDefaultsOnly, Category = "Droid|Input|Movement")
	TObjectPtr<UInputAction> LookAction;
	UPROPERTY(EditDefaultsOnly, Category = "Droid|Input|Movement")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Droid|Input|Abilities")
	TObjectPtr<UInputAction> PrimaryAction;
	UPROPERTY(EditDefaultsOnly, Category = "Droid|Input|Abilities")
	TObjectPtr<UInputAction> SecondaryAction;
	UPROPERTY(EditDefaultsOnly, Category = "Droid|Input|Abilities")
	TObjectPtr<UInputAction> TertiaryAction;
};
