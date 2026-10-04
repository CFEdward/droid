// Copyright Eduard Ciofu


#include "GameObjects/D_Projectile.h"
#include "AbilitySystemComponent.h"
#include "Characters/D_PlayerCharacter.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameplayTags/D_Tags.h"


AD_Projectile::AD_Projectile()
{
	PrimaryActorTick.bCanEverTick = false;
	
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile Movement");
	
	bReplicates = true;
}

void AD_Projectile::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	SpawnImpactEffects();

	const AD_PlayerCharacter* PlayerCharacter = Cast<AD_PlayerCharacter>(OtherActor);
	if (!IsValid(PlayerCharacter) || !PlayerCharacter->IsAlive()) return;
	UAbilitySystemComponent* PlayerASC = PlayerCharacter->GetAbilitySystemComponent();
	if (!IsValid(PlayerASC) || !HasAuthority()) return;

	const FGameplayEffectContextHandle ContextHandle = PlayerASC->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = PlayerASC->MakeOutgoingSpec(DamageEffect, 1.f, ContextHandle);
	
	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(SpecHandle, DTags::SetByCaller::Projectile, -Damage);
	
	PlayerASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	
	Destroy();
}
