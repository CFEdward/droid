// Copyright Eduard Ciofu

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/D_GameplayAbility.h"
#include "D_GA_HitReact.generated.h"

UCLASS()
class DROID_API UD_GA_HitReact : public UD_GameplayAbility
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintCallable, Category = "Droid|Abilities")
	void CacheHitDirectionVectors(AActor* Instigator);
	
	UPROPERTY(BlueprintReadOnly, Category = "Droid|Abilities")
	FVector AvatarForward;
	UPROPERTY(BlueprintReadOnly, Category = "Droid|Abilities")
	FVector ToInstigator;
};
