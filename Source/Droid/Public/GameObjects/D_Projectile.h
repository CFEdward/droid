// Copyright Eduard Ciofu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "D_Projectile.generated.h"

class UGameplayEffect;
class UProjectileMovementComponent;

UCLASS()
class DROID_API AD_Projectile : public AActor
{
	GENERATED_BODY()

public:

	AD_Projectile();
	
	/** Actor Parent */
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	/** end Actor Parent */
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Droid|Damage", meta = (ExposeOnSpawn, ClampMin = "0.0"))
	float Damage{ 10.f };
	
protected:
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Droid|Projectile")
	void SpawnImpactEffects();
	
private:
	
	UPROPERTY(VisibleAnywhere, Category = "Droid|Projectile")
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;

	UPROPERTY(EditDefaultsOnly, Category = "Droid|Damage")
	TSubclassOf<UGameplayEffect> DamageEffect;
};
