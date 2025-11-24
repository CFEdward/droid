// Copyright Eduard Ciofu

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/D_GameplayAbility.h"
#include "D_GA_Primary.generated.h"

UCLASS()
class DROID_API UD_GA_Primary : public UD_GameplayAbility
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintCallable, Category = "Droid|Abilities")
	void HitBoxOverlapTest();
	
private:
	
	UPROPERTY(EditDefaultsOnly, Category = "Droid|Abilities")
	float HitBoxRadius{ 100.f };
	UPROPERTY(EditDefaultsOnly, Category = "Droid|Abilities")
	float HitBoxForwardOffset{ 200.f };
	UPROPERTY(EditDefaultsOnly, Category = "Droid|Abilities")
	float HitBoxElevationOffset{ 20.f };
};
