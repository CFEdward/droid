// Copyright Eduard Ciofu


#include "UI/D_WidgetComponent.h"
#include "AbilitySystem/D_AbilitySystemComponent.h"
#include "AbilitySystem/D_AttributeSet.h"
#include "Characters/D_BaseCharacter.h"

void UD_WidgetComponent::BeginPlay()
{
	Super::BeginPlay();
	
	InitAbilitySystemData();
	if (!IsASCInitialized())
	{
		DroidCharacter->OnASCInitialized.AddDynamic(this, &ThisClass::OnASCInitialized);
	}
}

void UD_WidgetComponent::InitAbilitySystemData()
{
	DroidCharacter = Cast<AD_BaseCharacter>(GetOwner());
	AttributeSet = Cast<UD_AttributeSet>(DroidCharacter->GetAttributeSet());
	AbilitySystemComponent = Cast<UD_AbilitySystemComponent>(DroidCharacter->GetAbilitySystemComponent());
}

void UD_WidgetComponent::OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	AbilitySystemComponent = Cast<UD_AbilitySystemComponent>(ASC);
	AttributeSet = Cast<UD_AttributeSet>(AS);
	
	// TODO: Check if the AttributeSet has b een initialized with the first GE.
	// if not, bind to some delegate that will be broadcast when it is initialized
}

bool UD_WidgetComponent::IsASCInitialized() const
{
	return AbilitySystemComponent.IsValid() && AttributeSet.IsValid();
}
