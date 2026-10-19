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
	void SendHitReactEventToActors(const TArray<AActor*>& ActorsHit);
	
private:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Droid|Abilities", meta = (AllowPrivateAccess = "true"))
	float HitBoxRadius{ 100.f };
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Droid|Abilities", meta = (AllowPrivateAccess = "true"))
	float HitBoxForwardOffset{ 200.f };
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Droid|Abilities", meta = (AllowPrivateAccess = "true"))
	float HitBoxElevationOffset{ 20.f };
};
