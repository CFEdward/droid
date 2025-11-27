// Copyright Eduard Ciofu


#include "UI/D_WidgetComponent.h"
#include "AbilitySystem/D_AbilitySystemComponent.h"
#include "AbilitySystem/D_AttributeSet.h"
#include "Blueprint/WidgetTree.h"
#include "Characters/D_BaseCharacter.h"
#include "UI/D_AttributeWidget.h"

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

bool UD_WidgetComponent::IsASCInitialized() const
{
	return AbilitySystemComponent.IsValid() && AttributeSet.IsValid();
}

void UD_WidgetComponent::OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	AbilitySystemComponent = Cast<UD_AbilitySystemComponent>(ASC);
	AttributeSet = Cast<UD_AttributeSet>(AS);
	
	if (!IsASCInitialized()) return;
	InitAttributeDelegate();
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

bool UD_WidgetComponent::BindWidgetToAttributeChanges(UWidget* WidgetObject, const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const
{
	UD_AttributeWidget* AttributeWidget = Cast<UD_AttributeWidget>(WidgetObject);
	if (!IsValid(AttributeWidget)) return true;	// we only care about D_AttributeWidgets
	if (!AttributeWidget->MatchesAttributes(Pair)) return true;	// only subscribe for matching Attributes
		
	AttributeWidget->OnAttributeChange(Pair, AttributeSet.Get());	// for initial values
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Key).AddLambda([this, AttributeWidget, &Pair]
		(const FOnAttributeChangeData& AttributeChangeData)
		{
			AttributeWidget->OnAttributeChange(Pair, AttributeSet.Get());	// for changes during the game
		}
	);
	return false;
}

void UD_WidgetComponent::BindToAttributeChanges()
{
	for (const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair : AttributeMap)
	{
		BindWidgetToAttributeChanges(GetUserWidgetObject(), Pair);	// for checking the owned widget object
		
		GetUserWidgetObject()->WidgetTree->ForEachWidget([this, &Pair](UWidget* ChildWidget)
			{
				BindWidgetToAttributeChanges(ChildWidget, Pair);
			}
		);
	}
}
