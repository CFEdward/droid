// Copyright Eduard Ciofu

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "D_PlayerState.generated.h"

class UAbilitySystemComponent;

UCLASS()
class DROID_API AD_PlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	
	AD_PlayerState();

	/** AbilitySystem Interface */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	/** end AbilitySystem Interface */
	
private:

	UPROPERTY(VisibleAnywhere, Category = "Droid|Abilities")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
};
