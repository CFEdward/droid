// Copyright Eduard Ciofu

#include "Droid/Public/Characters/D_BaseCharacter.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/D_AttributeSet.h"

AD_BaseCharacter::AD_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	// Tick and refresh bone transforms whether rendered or not - for bone updates on a dedicated server
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
}

void AD_BaseCharacter::GiveStartupAbilities()
{
	if (!IsValid(GetAbilitySystemComponent())) return;
	
	for (const auto& Ability : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability);
		GetAbilitySystemComponent()->GiveAbility(AbilitySpec);
	}
}

void AD_BaseCharacter::InitializeAttributes() const
{
	ensureMsgf(IsValid(InitializeAttributesEffect), TEXT("InitializeAttributesEffect not set."));

	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(InitializeAttributesEffect, 1.f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	Cast<UD_AttributeSet>(GetAttributeSet())->PostAttributesInitialized();
}
