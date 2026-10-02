// Copyright Eduard Ciofu


#include "Characters/D_EnemyCharacter.h"
#include "AbilitySystem/D_AbilitySystemComponent.h"
#include "AbilitySystem/D_AttributeSet.h"
#include "Runtime/AIModule/Classes/AIController.h"

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
	OnASCInitialized.Broadcast(GetAbilitySystemComponent(), GetAttributeSet());
	
	if (!HasAuthority()) return;

	GiveStartupAbilities();
	InitializeAttributes();
	
	GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(UD_AttributeSet::GetHealthAttribute()).AddUObject(this, &ThisClass::OnHealthChanged);
}

UAbilitySystemComponent* AD_EnemyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AD_EnemyCharacter::HandleDeath()
{
	Super::HandleDeath();
	
	AAIController* AIController = GetController<AAIController>();
	if (!IsValid(AIController)) return;
	AIController->StopMovement();
}
