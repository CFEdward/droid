// Copyright Eduard Ciofu

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "D_BaseCharacter.generated.h"

class UGameplayAbility;

UCLASS(Abstract)
class DROID_API AD_BaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	AD_BaseCharacter();

	/** AbilitySystem Interface */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	/** end AbilitySystem Interface */

protected:

	void GiveStartupAbilities();

private:

	UPROPERTY(EditDefaultsOnly, Category = "Droid|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;
};
