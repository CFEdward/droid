// Copyright Eduard Ciofu

#include "Droid/Public/Characters/D_BaseCharacter.h"

AD_BaseCharacter::AD_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	// Tick and refresh bone transforms whether rendered or not - for bone updates on a dedicated server
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
}

UAbilitySystemComponent* AD_BaseCharacter::GetAbilitySystemComponent() const
{
	return nullptr;
}
