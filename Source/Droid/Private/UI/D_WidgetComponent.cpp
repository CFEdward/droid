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
		return;
	}
	
	InitAttributeDelegate();
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
	
	if (!IsASCInitialized()) return;
	InitAttributeDelegate();
}

void UD_WidgetComponent::BindToAttributeChanges()
{
	// TODO: Listen for changes to Gameplay Attributes and update our widgets accordingly
}

bool UD_WidgetComponent::IsASCInitialized() const
{
	return AbilitySystemComponent.IsValid() && AttributeSet.IsValid();
}

void UD_WidgetComponent::InitAttributeDelegate()
{
	if (!AttributeSet->bAttributesInitialized)
	{
		AttributeSet->OnAttributesInitialized.AddDynamic(this, &ThisClass::BindToAttributeChanges);
	}
	else
	{
		BindToAttributeChanges();
	}
}
