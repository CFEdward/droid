#include "GameplayTags/D_Tags.h"

namespace DTags
{
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(None, "DTags.None", "Default None Tag.");
}

namespace DTags::DAbilities
{
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(ActivateOnGiven, "DTags.DAbilities.ActivateOnGiven", "Tag for Abilities that should activate immediately once given");
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Primary, "DTags.DAbilities.Primary", "Tag for the Primary Ability");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Secondary, "DTags.DAbilities.Secondary", "Tag for the Secondary Ability");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Tertiary, "DTags.DAbilities.Tertiary", "Tag for the Tertiary Ability");
}

namespace DTags::Events
{
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(KillScored, "DTags.Events.KillScored", "Tag for the Kill Scored Event");
}

namespace DTags::Events::Player
{
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitReact, "DTags.Events.Player.HitReact", "Tag for the Player HitReact Event");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Death, "DTags.Events.Player.Death", "Tag for the Player Death Event");
}

namespace DTags::Events::Enemy
{
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitReact, "DTags.Events.Enemy.HitReact", "Tag for the Enemy HitReact Event");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(EndAttack, "DTags.Events.Enemy.EndAttack", "Tag for the Enemy End Attack Event");
}

namespace DTags::SetByCaller
{
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Projectile, "DTags.SetByCaller.Projectile", "Tag for Set By Caller magnitude for projectiles");
}