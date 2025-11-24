// Copyright Eduard Ciofu

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "D_GameplayAbility.generated.h"

UCLASS()
class DROID_API UD_GameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Droid|Debug")
	bool bDrawDebugs{ false };
	
protected:
	
	/** UGameplayAbility Parent */
	void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	/** end UGameplayAbility Parent */
};
