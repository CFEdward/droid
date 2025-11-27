// Copyright Eduard Ciofu

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/D_AttributeSet.h"
#include "Blueprint/UserWidget.h"
#include "D_AttributeWidget.generated.h"

UCLASS(Abstract)
class DROID_API UD_AttributeWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	void OnAttributeChange(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair, const UD_AttributeSet* AttributeSet);
	bool MatchesAttributes(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const;
	
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Attribute Change"))
	void BP_OnAttributeChange(float NewValue, float NewMaxValue);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Droid|Attributes")
	FGameplayAttribute Attribute;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Droid|Attributes")
	FGameplayAttribute MaxAttribute;
};
