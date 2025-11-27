// Copyright Eduard Ciofu

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "D_BaseCharacter.generated.h"

class UAttributeSet;
class UGameplayEffect;
class UGameplayAbility;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FASCInitialized, UAbilitySystemComponent*, ASC, UAttributeSet*, AS);

UCLASS(Abstract)
class DROID_API AD_BaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	AD_BaseCharacter();

	/** AbilitySystem Interface */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	/** end AbilitySystem Interface */
	
	UPROPERTY(BlueprintAssignable)
	FASCInitialized OnASCInitialized;
	
	FORCEINLINE virtual UAttributeSet* GetAttributeSet() const { return nullptr;}

protected:

	void GiveStartupAbilities();
	void InitializeAttributes() const;

private:

	UPROPERTY(EditDefaultsOnly, Category = "Droid|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;
	
	UPROPERTY(EditDefaultsOnly, Category = "Droid|Effects")
	TSubclassOf<UGameplayEffect> InitializeAttributesEffect;
};
