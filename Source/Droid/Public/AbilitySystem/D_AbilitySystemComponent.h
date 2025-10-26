// Copyright Eduard Ciofu

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "D_AbilitySystemComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DROID_API UD_AbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:

	UD_AbilitySystemComponent();

	/** AbilitySystemComponent Parent **/
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	/** end AbilitySystemComponent Parent **/
	
protected:

	/** AbilitySystemComponent Parent **/
	virtual void BeginPlay() override;
	/** end AbilitySystemComponent Parent **/
};
