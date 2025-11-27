// Copyright Eduard Ciofu

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Components/WidgetComponent.h"
#include "D_WidgetComponent.generated.h"

class UAbilitySystemComponent;
class UD_AttributeSet;
class UD_AbilitySystemComponent;
class AD_BaseCharacter;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DROID_API UD_WidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	TMap<FGameplayAttribute, FGameplayAttribute> AttributeMap;
	
private:
	
	void InitAbilitySystemData();
	bool IsASCInitialized() const;
	void InitAttributeDelegate();
	
	bool BindWidgetToAttributeChanges(UWidget* WidgetObject, const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const;

	UFUNCTION()
	void OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS);
	UFUNCTION()
	void BindToAttributeChanges();
	
	TWeakObjectPtr<AD_BaseCharacter> DroidCharacter;
	TWeakObjectPtr<UD_AbilitySystemComponent> AbilitySystemComponent;
	TWeakObjectPtr<UD_AttributeSet> AttributeSet;
};
