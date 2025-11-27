// Copyright Eduard Ciofu

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "D_AttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName)			\
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName);	\
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName);				\
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName);				\
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAttributesInitialized);

UCLASS()
class DROID_API UD_AttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	
	/** Object Parent */
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	/** end Object Parent */
	
	/** AttributeSet Parent */
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	/** end AttributeSet Parent */
	
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
	ATTRIBUTE_ACCESSORS(ThisClass, Health);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);
	ATTRIBUTE_ACCESSORS(ThisClass, MaxHealth);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldValue);
	ATTRIBUTE_ACCESSORS(ThisClass, Mana);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana)
	FGameplayAttributeData MaxMana;
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldValue);
	ATTRIBUTE_ACCESSORS(ThisClass, MaxMana);
};
