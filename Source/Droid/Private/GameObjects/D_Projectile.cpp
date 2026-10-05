// Copyright Eduard Ciofu


#include "GameObjects/D_Projectile.h"
#include "AbilitySystemComponent.h"
#include "Characters/D_PlayerCharacter.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameplayTags/D_Tags.h"
#include "Utils/D_BlueprintLibrary.h"


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

	AD_PlayerCharacter* PlayerCharacter = Cast<AD_PlayerCharacter>(OtherActor);
	if (!IsValid(PlayerCharacter) || !PlayerCharacter->IsAlive()) return;
	const UAbilitySystemComponent* PlayerASC = PlayerCharacter->GetAbilitySystemComponent();
	if (!IsValid(PlayerASC) || !HasAuthority()) return;
	
	FGameplayEventData Payload;
	Payload.Instigator = GetOwner();
	Payload.Target = PlayerCharacter;
	UD_BlueprintLibrary::SendDamageEventToPlayer(PlayerCharacter, DamageEffect, Payload, DTags::SetByCaller::Projectile, Damage);
	
	Destroy();
}
