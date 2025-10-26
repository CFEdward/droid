// Copyright Eduard Ciofu

#pragma once

#include "CoreMinimal.h"
#include "D_BaseCharacter.h"
#include "D_EnemyCharacter.generated.h"

UCLASS()
class DROID_API AD_EnemyCharacter : public AD_BaseCharacter
{
	GENERATED_BODY()

public:

	AD_EnemyCharacter();

protected:

	/** Character Parent **/
	virtual void BeginPlay() override;
	//** end Character Parent **/
	
	/** AbilitySystem Interface */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	/** end AbilitySystem Interface */

private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
};
