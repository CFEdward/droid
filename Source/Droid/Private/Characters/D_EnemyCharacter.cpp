// Copyright Eduard Ciofu


#include "Characters/D_EnemyCharacter.h"
#include "AbilitySystemComponent.h"

AD_EnemyCharacter::AD_EnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
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
