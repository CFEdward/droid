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

UCLASS(Abstract)
class DROID_API AD_BaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	AD_BaseCharacter();
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FASCInitializedDelegate, UAbilitySystemComponent*, ASC, UAttributeSet*, AS);
	UPROPERTY(BlueprintAssignable)
	FASCInitializedDelegate OnASCInitialized;
	
	/** Character Parent */
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	/** end Character Parent */

	/** AbilitySystem Interface */
	FORCEINLINE virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return nullptr; }
	/** end AbilitySystem Interface */
	
	UFUNCTION(BlueprintCallable, Category = "Droid|Death", meta = (DisplalyName = "Handle Respawn"))
	virtual void BP_HandleRespawn();
	
	UFUNCTION(BlueprintCallable, Category = "Droid|Attributes", meta = (DisplayName = "Reset Attributes"))
	void BP_ResetAttributes() const;
	
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
	UPROPERTY(EditDefaultsOnly, Category = "Droid|Effects")
	TSubclassOf<UGameplayEffect> ResetAttributesEffect;
	
	UPROPERTY(BlueprintReadOnly, Replicated, meta = (AllowPrivateAccess = "true"))
	bool bAlive{ true };
};
