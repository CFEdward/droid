﻿// Copyright Eduard Ciofu


#include "Player/D_PlayerState.h"
#include "AbilitySystemComponent.h"

AD_PlayerState::AD_PlayerState()
{
	SetNetUpdateFrequency(100.f);

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

UAbilitySystemComponent* AD_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
