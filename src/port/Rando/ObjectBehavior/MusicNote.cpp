#include "ObjectBehavior.h"
#include "port/Rando/Logic/Logic.h"
#include "port/Rando/CustomObject/CustomObject.h"

#include <libultraship/bridge.h>
#include "port/UI/cvar_prefixes.h"
#include <libultraship/bridge/consolevariablebridge.h>
#include "port/Enhancements/Events/PortEnhancements.h"
#include "port/Enhancements/Events/Hooks/Events.h"

extern "C" {
void item_inc(enum item_e item);
extern u8 D_80385FF0[0xE];
}

#define OPTION_ENABLED RANDO_SAVE_OPTIONS[RO_SHUFFLE_MUSIC_NOTES].optionValue

void Rando::ObjectBehavior::InitMusicNoteBehavior() {
    COND_HOOK(OnSetJiggyList, EVENT_PRIORITY_NORMAL, IS_RANDO && OPTION_ENABLED, [](IEvent* event) {
        OnSetJiggyList* ev = (OnSetJiggyList*)event;

        item_set(ITEM_C_NOTE, D_80385FF0[ev->levelId]);
    })
}
