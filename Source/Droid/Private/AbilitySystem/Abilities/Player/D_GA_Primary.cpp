// Copyright Eduard Ciofu


#include "AbilitySystem/Abilities/Player/D_GA_Primary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayTags/D_Tags.h"


void UD_GA_Primary::SendHitReactEventToActors(const TArray<AActor*>& ActorsHit)
{
	for (AActor* HitActor : ActorsHit)
	{
		FGameplayEventData Payload;
		Payload.Instigator = GetAvatarActorFromActorInfo();
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(HitActor, DTags::Events::Enemy::HitReact, Payload);
	}
}
