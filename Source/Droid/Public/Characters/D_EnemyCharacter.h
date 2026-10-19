// Copyright Eduard Ciofu

#pragma once

#include "CoreMinimal.h"
#include "D_BaseCharacter.h"
#include "D_EnemyCharacter.generated.h"

class UAttributeSet;

UCLASS()
class DROID_API AD_EnemyCharacter : public AD_BaseCharacter
{
	GENERATED_BODY()

public:

	AD_EnemyCharacter();

	/** Character Parent */
	virtual void BeginPlay() override;
	/** end Character Parent */
	
	/** D_BaseCharacter Parent */
	FORCEINLINE virtual UAttributeSet* GetAttributeSet() const override { return AttributeSet; }
	/** end D_BaseCharacter Parent */
	/** AbilitySystem Interface */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	/** end AbilitySystem Interface */
	
	void StopMovementUntilLanded();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Droid|AI")
	float AcceptanceRadius{ 500.f };
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Droid|AI")
	float MinAttackDelay{ .1f };
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Droid|AI")
	float MaxAttackDelay{ .5f };
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Droid|AI")
	bool bIsBeingLaunched{ false };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Droid|AI")
	float SearchRange{ 1000.f };
	
protected:
	
	/** D_BaseCharacter Parent */
	virtual void HandleDeath() override;
	/** end D_BaseCharacter Parent */
	
private:
	
	UFUNCTION()
	void EnableMovementOnLanded(const FHitResult& HitResult);

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
