#include "port/ShipInit.hpp"
#include "port/Enhancements/Events/Hooks/Events.h"
#include "port/Rando/Logic/Logic.h"
#include "port/Rando/CustomCollectible/CustomCollectible.h"

#define BLUE_EGG_OPTION_ENABLED RANDO_SAVE_OPTIONS[RO_SHUFFLE_BLUE_EGGS].optionValue
#define MUSIC_NOTE_OPTION_ENABLED RANDO_SAVE_OPTIONS[RO_SHUFFLE_MUSIC_NOTES].optionValue

bool OverridePropSpawn(s16 spawnPosition[3], int32_t propAsset) {
    s32 position[3] = { spawnPosition[0], spawnPosition[1], spawnPosition[2] };
    
    if (!IS_RANDO) {
        return false;
    }

    if (!BLUE_EGG_OPTION_ENABLED && propAsset == ASSET_6D7_SPRITE_BLUE_EGGS) {
        return false;
    }

    if (!MUSIC_NOTE_OPTION_ENABLED && propAsset == ASSET_6D6_SPRITE_MUSIC_NOTE) {
        return false;
    }

    RandoCheckId randoCheckId = Rando::StaticData::GetCheckByPosition(position[0], position[1], position[2]);
    if (randoCheckId == RC_UNKNOWN) {
        return false;
    }

    if (!Rando::Logic::IsCheckShuffled(randoCheckId)) {
        return false;
    }

    if (Rando::Logic::IsCheckObtained(randoCheckId)) {
        return true;
    }

    CustomCollectible::QueueProp(position, randoCheckId);
    return true;
}

void RegisterRandoPropBehaviour() {
    COND_VB_SHOULD(VB_OVERRIDE_PROP_SPAWN, EVENT_PRIORITY_NORMAL, true, {
        s16* spawnPosition = va_arg(args, s16*);
        int32_t propAsset = va_arg(args, int32_t);
        *should = OverridePropSpawn(spawnPosition, propAsset); 
    });
}

static RegisterShipInitFunc initFunc(RegisterRandoPropBehaviour, { "IS_RANDO" });
