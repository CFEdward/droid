// Copyright Eduard Ciofu


#include "Player/D_PlayerState.h"
#include "AbilitySystem/D_AbilitySystemComponent.h"

AD_PlayerState::AD_PlayerState()
{
	SetNetUpdateFrequency(100.f);

	AbilitySystemComponent = CreateDefaultSubobject<UD_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

UAbilitySystemComponent* AD_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
