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
	
	UFUNCTION(BlueprintCallable, Category = "Droid|Abilities")
	void SetAbilityLevel(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level);
	UFUNCTION(BlueprintCallable, Category = "Droid|Abilities")
	void AddToAbilityLevel(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level = 1);
	
private:
	
	void HandleAutoActivatedAbility(const FGameplayAbilitySpec& AbilitySpec);
};
