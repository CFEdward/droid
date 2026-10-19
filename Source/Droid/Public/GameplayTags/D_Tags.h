#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"

namespace DTags
{
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(None);
}

namespace DTags::DAbilities
{
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(ActivateOnGiven);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Primary);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Secondary);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Tertiary);
}

namespace DTags::Events
{
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(KillScored);
}

namespace DTags::Events::Player
{
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(HitReact);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Death);
}

namespace DTags::Events::Enemy
{
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(HitReact);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(EndAttack);
}

namespace DTags::SetByCaller
{
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Projectile);
}