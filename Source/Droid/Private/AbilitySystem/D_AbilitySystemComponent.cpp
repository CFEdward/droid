// Copyright Eduard Ciofu

#include "AbilitySystem/D_AbilitySystemComponent.h"

UD_AbilitySystemComponent::UD_AbilitySystemComponent()
{
}

void UD_AbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UD_AbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
