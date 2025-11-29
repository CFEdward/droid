// Copyright Eduard Ciofu

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "D_BaseCharacter.generated.h"

struct FOnAttributeChangeData;
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
	
	/** Character Parent */
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	/** end Character Parent */

	/** AbilitySystem Interface */
	FORCEINLINE virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return nullptr; }
	/** end AbilitySystem Interface */
	
	UFUNCTION(BlueprintCallable, Category = "Droid|Death")
	virtual void HandleRespawn();
	
	UPROPERTY(BlueprintAssignable)
	FASCInitialized OnASCInitialized;
	
	FORCEINLINE virtual UAttributeSet* GetAttributeSet() const { return nullptr;}
	FORCEINLINE bool IsAlive() const { return bAlive; }
	FORCEINLINE void SetAlive(const bool bAliveStatus) { bAlive = bAliveStatus; }

protected:

	void GiveStartupAbilities();
	void InitializeAttributes() const;
	
	void OnHealthChanged(const FOnAttributeChangeData& AttributeChangeData);
	virtual void HandleDeath();
	
private:

	UPROPERTY(EditDefaultsOnly, Category = "Droid|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;
	
	UPROPERTY(EditDefaultsOnly, Category = "Droid|Effects")
	TSubclassOf<UGameplayEffect> InitializeAttributesEffect;
	
	UPROPERTY(BlueprintReadOnly, Replicated, meta = (AllowPrivateAccess = "true"))
	bool bAlive{ true };
};
