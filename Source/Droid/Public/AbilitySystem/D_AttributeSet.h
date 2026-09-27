// Copyright Eduard Ciofu

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "D_AttributeSet.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAttributesInitialized);

UCLASS()
class DROID_API UD_AttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	
	/** Object Parent */
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	/** end Object Parent */
	/** AttributeSet Parent */
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	/** end AttributeSet Parent */
	
	void PostAttributesInitialized();
	
	UPROPERTY(BlueprintAssignable)
	FAttributesInitialized OnAttributesInitialized;
	
	UPROPERTY(ReplicatedUsing = OnRep_AttributesInitialized)
	bool bAttributesInitialized{ false };
	UFUNCTION()
	void OnRep_AttributesInitialized();
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldValue);
	ATTRIBUTE_ACCESSORS_BASIC(ThisClass, Health);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);
	ATTRIBUTE_ACCESSORS_BASIC(ThisClass, MaxHealth);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldValue);
	ATTRIBUTE_ACCESSORS_BASIC(ThisClass, Mana);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana)
	FGameplayAttributeData MaxMana;
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldValue);
	ATTRIBUTE_ACCESSORS_BASIC(ThisClass, MaxMana);
};
