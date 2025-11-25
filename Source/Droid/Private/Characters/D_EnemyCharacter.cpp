// Copyright Eduard Ciofu


#include "Characters/D_EnemyCharacter.h"
#include "AbilitySystem/D_AbilitySystemComponent.h"
#include "AbilitySystem/D_AttributeSet.h"

AD_EnemyCharacter::AD_EnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<UD_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<UD_AttributeSet>("AttributeSet");
}

void AD_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (!IsValid(GetAbilitySystemComponent())) return;

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	
	if (!HasAuthority()) return;

	GiveStartupAbilities();
}

UAbilitySystemComponent* AD_EnemyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
