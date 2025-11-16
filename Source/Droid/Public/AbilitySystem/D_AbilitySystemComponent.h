// Copyright Eduard Ciofu

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "D_AbilitySystemComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DROID_API UD_AbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

protected:
	
	/** UAbilitySystemComponent Parent */
	virtual void OnGiveAbility(FGameplayAbilitySpec& AbilitySpec) override;
	virtual void OnRep_ActivateAbilities() override;
	/** end UAbilitySystemComponent Parent */
	
private:
	
	void HandleAutoActivatedAbility(const FGameplayAbilitySpec& AbilitySpec);
};
