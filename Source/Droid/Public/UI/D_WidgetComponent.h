// Copyright Eduard Ciofu

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "D_WidgetComponent.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
class UD_AttributeSet;
class UD_AbilitySystemComponent;
class AD_BaseCharacter;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DROID_API UD_WidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;
	
private:
	
	void InitAbilitySystemData();
	bool IsASCInitialized() const;
	
	UFUNCTION()
	void OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS);
	
	TWeakObjectPtr<AD_BaseCharacter> DroidCharacter;
	TWeakObjectPtr<UD_AbilitySystemComponent> AbilitySystemComponent;
	TWeakObjectPtr<UD_AttributeSet> AttributeSet;
};
