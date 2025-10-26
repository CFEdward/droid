// Copyright Eduard Ciofu

#pragma once

#include "CoreMinimal.h"
#include "D_BaseCharacter.h"
#include "D_PlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class DROID_API AD_PlayerCharacter : public AD_BaseCharacter
{
	GENERATED_BODY()

public:

	AD_PlayerCharacter();

	/** D_BaseCharacter Override */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	/** end D_BaseCharacter Override */

	/** Character Override */
	virtual void PossessedBy(AController* NewController) override;
	/** end Character Override */

	/** Pawn Override */
	virtual void OnRep_PlayerState() override;
	/** end Pawn Override */
	
private:

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	TObjectPtr<UCameraComponent> FollowCamera;
};
