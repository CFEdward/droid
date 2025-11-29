// Copyright Eduard Ciofu

#include "AbilitySystem/D_AbilitySystemComponent.h"

#include "GameplayTags/D_Tags.h"

void UD_AbilitySystemComponent::OnGiveAbility(FGameplayAbilitySpec& AbilitySpec)
{
	Super::OnGiveAbility(AbilitySpec);
	
	if (!IsValid(AbilitySpec.Ability)) return;
	
	HandleAutoActivatedAbility(AbilitySpec);
}

void UD_AbilitySystemComponent::OnRep_ActivateAbilities()
{
	Super::OnRep_ActivateAbilities();
	
	ABILITYLIST_SCOPE_LOCK();
	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		HandleAutoActivatedAbility(AbilitySpec);
	}
}

void UD_AbilitySystemComponent::SetAbilityLevel(const TSubclassOf<UGameplayAbility> AbilityClass, const int32 Level)
{
	if (IsValid(GetAvatarActor()) && !GetAvatarActor()->HasAuthority()) return;
	
	if (FGameplayAbilitySpec* AbilitySpec = FindAbilitySpecFromClass(AbilityClass))
	{
		AbilitySpec->Level = Level;
		MarkAbilitySpecDirty(*AbilitySpec);
	}
}

void UD_AbilitySystemComponent::AddToAbilityLevel(const TSubclassOf<UGameplayAbility> AbilityClass, const int32 Level)
{
	if (IsValid(GetAvatarActor()) && !GetAvatarActor()->HasAuthority()) return;
	
	if (FGameplayAbilitySpec* AbilitySpec = FindAbilitySpecFromClass(AbilityClass))
	{
		AbilitySpec->Level += Level;
		MarkAbilitySpecDirty(*AbilitySpec);
	}
}

void UD_AbilitySystemComponent::HandleAutoActivatedAbility(const FGameplayAbilitySpec& AbilitySpec)
{
	for (const FGameplayTag& Tag : AbilitySpec.Ability->GetAssetTags())
	{
		if (Tag.MatchesTagExact(DTags::DAbilities::ActivateOnGiven))
		{
			TryActivateAbility(AbilitySpec.Handle);
			return;
		}
	}
}
