// Copyright Eduard Ciofu

#include "Tasks/D_Task_AttributeChange.h"
#include "AbilitySystemComponent.h"

UD_Task_AttributeChange* UD_Task_AttributeChange::ListenForAttributeChange(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayAttribute Attribute)
{
	UD_Task_AttributeChange* WaitForAttributeChangeTask = NewObject<UD_Task_AttributeChange>();
	WaitForAttributeChangeTask->ASC = AbilitySystemComponent;
	WaitForAttributeChangeTask->AttributeToListenFor = Attribute;
	
	if (!IsValid(AbilitySystemComponent))
	{
		WaitForAttributeChangeTask->RemoveFromRoot();
		return nullptr;
	}
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Attribute).AddUObject(WaitForAttributeChangeTask, &ThisClass::AttributeChanged);
	
	return WaitForAttributeChangeTask;
}

void UD_Task_AttributeChange::AttributeChanged(const FOnAttributeChangeData& Data)
{
	OnAttributeChanged.Broadcast(Data.Attribute, Data.NewValue, Data.OldValue);
}

void UD_Task_AttributeChange::EndTask()
{
	if (ASC.IsValid())
	{
		ASC->GetGameplayAttributeValueChangeDelegate(AttributeToListenFor).RemoveAll(this);
	}
	
	SetReadyToDestroy();
	MarkAsGarbage();
}
