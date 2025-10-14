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

private:

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	TObjectPtr<UCameraComponent> FollowCamera;
};
