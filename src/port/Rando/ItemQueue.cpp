#include "ItemQueue.h"

#include <queue>
#include <unordered_map>
#include <map>

#include "port/UI/Notification.h"
#include "port/UI/UIWidgets.hpp"
#include <libultraship/bridge.h>
#include "port/ShipInit.hpp"
#include "port/Rando/Logic/Logic.h"
#include "actor.h"

extern "C" {
#include "functions.h"
extern u8 sHoneycombScore[3];
extern struct {
    u8 D_803832C0[0xD];
    u8 D_803832CD[0xD];
} jiggyscore;
}

#define CVAR_NAME_SHOW_COLLISION_NOTIFICATIONS "gRandoSettings.RandoNotifications"
#define CVAR_SHOW_COLLISION_NOTIFICATIONS CVarGetInteger(CVAR_NAME_SHOW_COLLISION_NOTIFICATIONS, 0)

#define JIGGY_ID_MULTIPLIER(levelId) (1 + (10 * (levelId - 1)))
#define HONEYCOMB_ID_MULTIPLIER(levelId) (1 + (2 * (levelId - 1)))

static std::queue<RandoCheckId> itemQueue;

std::map<actor_e, UIWidgets::Colors> itemColors = {
    { ACTOR_1_UNKNOWN, UIWidgets::Colors::Brown },           { ACTOR_52_BLUE_EGG, UIWidgets::Colors::Cyan },
    { ACTOR_47_EMPTY_HONEYCOMB, UIWidgets::Colors::Yellow }, { ACTOR_49_EXTRA_LIFE, UIWidgets::Colors::Yellow },
    { ACTOR_50_HONEYCOMB, UIWidgets::Colors::Yellow },       { ACTOR_46_JIGGY, UIWidgets::Colors::Yellow },
    { ACTOR_60_JINJO_BLUE, UIWidgets::Colors::SkyBlue },     { ACTOR_62_JINJO_GREEN, UIWidgets::Colors::Green },
    { ACTOR_5F_JINJO_ORANGE, UIWidgets::Colors::Orange },    { ACTOR_61_JINJO_PINK, UIWidgets::Colors::Pink },
    { ACTOR_5E_JINJO_YELLOW, UIWidgets::Colors::Yellow },    { ACTOR_12C_MOLEHILL, UIWidgets::Colors::Cyan },
    { ACTOR_2D_MUMBO_TOKEN, UIWidgets::Colors::Gray },       { ACTOR_51_MUSIC_NOTE, UIWidgets::Colors::Yellow },
    { ACTOR_25E_SNS_EGG, UIWidgets::Colors::Pink },          { ACTOR_25D_ICE_KEY, UIWidgets::Colors::White },
};

std::map<RandoItemId, UIWidgets::Colors> snsColors = {
    { RI_STOP_N_SWOP_EGG_YELLOW, UIWidgets::Colors::Yellow }, { RI_STOP_N_SWOP_EGG_RED, UIWidgets::Colors::Red },
    { RI_STOP_N_SWOP_EGG_GREEN, UIWidgets::Colors::Green },   { RI_STOP_N_SWOP_EGG_BLUE, UIWidgets::Colors::Blue },
    { RI_STOP_N_SWOP_EGG_PINK, UIWidgets::Colors::Pink },     { RI_STOP_N_SWOP_EGG_CYAN, UIWidgets::Colors::Cyan },
    { RI_STOP_N_SWOP_ICE_KEY, UIWidgets::Colors::White },
};

void ItemQueue::Process() {
    if (itemQueue.size() < 1) {
        return;
    }
    
    RandoCheckId randoCheckId = itemQueue.front();

    // Grant item
    RandoSaveCheck randoSaveCheck = RANDO_SAVE_CHECKS[randoCheckId];
    ItemQueue::GiveItem(randoSaveCheck.randoItemId);
    ItemQueue::SendNotification(randoSaveCheck.randoItemId);

    itemQueue.pop();
}

void ItemQueue::GiveItem(RandoItemId randoItemId) {
    RandoItemType itemType = Rando::StaticData::Items[randoItemId].randoItemType;
    int16_t worldId = Rando::StaticData::Items[randoItemId].worldId;
    uint16_t combId;
    uint16_t maxHoneycombs;
    uint32_t jiggyId;

    switch (itemType) {
        case RITYPE_BLUE_EGG:
            coMusicPlayer_playMusic(COMUSIC_C_EGG_COLLECTED, 32000);
            item_inc(ITEM_D_EGGS);
            break;
        case RITYPE_EMPTY_HONEYCOMB:
            combId = HONEYCOMB_ID_MULTIPLIER(worldId);
            maxHoneycombs = worldId == LEVEL_B_SPIRAL_MOUNTAIN ? 6 : 2;
            if (worldId > LEVEL_6_LAIR) {
                combId = HONEYCOMB_ID_MULTIPLIER(worldId - 1);
            }
            for (int i = 0; i < (maxHoneycombs); i++) {
                if ((sHoneycombScore[((combId + i) - 1) / 8] & (1 << ((combId + i) & 7))) == 0) {
                    honeycombscore_set((honeycomb_e)(combId + i), 1);
                    break;
                }
            }
            coMusicPlayer_playMusic(COMUSIC_17_EMPTY_HONEYCOMB_COLLECTED, 28000);
            item_inc(ITEM_13_EMPTY_HONEYCOMB);
            if (!(item_getCount(ITEM_13_EMPTY_HONEYCOMB) < 6)) {
                gcpausemenu_80314AC8(0);
            }
            break;
        case RITYPE_EXTRA_LIFE:
            coMusicPlayer_playMusic(COMUSIC_15_EXTRA_LIFE_COLLECTED, 0x7FFF);
            item_inc(ITEM_16_LIFE);
            break;
        case RITYPE_HONEYCOMB:
            coMusicPlayer_playMusic(COMUSIC_16_HONEYCOMB_COLLECTED, 28000);
            item_inc(ITEM_14_HEALTH);
            break;
        case RITYPE_JIGGY:
            jiggyId = JIGGY_ID_MULTIPLIER(worldId);
            for (int32_t i = jiggyId; i <= (jiggyId + 9); i++) {
                if ((jiggyscore.D_803832C0[(i - 1) / 8] & (1 << (i & 7))) == 0) {
                    jiggyscore_setCollected(i, 1);
                    break;
                }
            }
            coMusicPlayer_playMusic(COMUSIC_D_JINGLE_JIGGY_COLLECTED, -1);
            item_inc(ITEM_E_JIGGY);
            spawnOrbit();
            break;
        case RITYPE_JINJO:
            break;
        case RITYPE_MOLEHILL:
            break;
        case RITYPE_MUMBO_TOKEN:
            break;
        case RITYPE_MUSIC_NOTE:
            break;
        case RITYPE_SNS_EGG:
            break;
        case RITYPE_SNS_KEY:
            break;
        case RITYPE_AP_ITEM:
            break;
        default:
            break;
    }
}

void ItemQueue::SendNotification(RandoItemId randoItemId) {
    if (CVAR_SHOW_COLLISION_NOTIFICATIONS) {
        RandoItemType itemType = Rando::StaticData::Items[randoItemId].randoItemType;
        actor_e actorId = (actor_e)Rando::StaticData::Items[randoItemId].actorId;
        std::string prefix = "";
        std::string message = Rando::StaticData::Items[randoItemId].name;
        std::string suffix = "";
        ImVec4 itemColor = UIWidgets::ColorValues.at(itemColors.at(actorId));

        if (itemType == RITYPE_MOLEHILL) {
            prefix = "You learned";
        } else if (itemType == RITYPE_SNS_EGG || itemType == RITYPE_SNS_KEY) {
            int32_t totalsnsItems = Rando::Logic::GetTotalSnsItemsCollected();
            prefix = "You collected ";
            prefix += Rando::StaticData::Items[randoItemId].article;
            suffix = "(";
            suffix += std::to_string(totalsnsItems);
            suffix += " / 7)";

            itemColor = UIWidgets::ColorValues.at(snsColors.at(randoItemId));
        } else {
            prefix = "You collected ";
            prefix += Rando::StaticData::Items[randoItemId].article;
        }

        Notification::Emit({
            .prefix = prefix,
            .prefixColor = UIWidgets::ColorValues.at(UIWidgets::Colors::White),
            .message = message,
            .messageColor = itemColor,
            .suffix = suffix,
            .suffixColor = UIWidgets::ColorValues.at(UIWidgets::Colors::White),
        });
    }
}

void ItemQueue::Clear() {
    while (!itemQueue.empty()) {
        itemQueue.pop();
    }
}

void ItemQueue::AddCheck(RandoCheckId randoCheckId) {
    itemQueue.push(randoCheckId);
}

void RegisterItemQueue() {
    COND_HOOK(GameFrameUpdate, EVENT_PRIORITY_NORMAL, IS_RANDO, [](IEvent* event) { 
        ItemQueue::Process();
    });

    COND_HOOK(OnSaveFileLoad, EVENT_PRIORITY_NORMAL, IS_RANDO, [](IEvent* event) { 
        ItemQueue::Clear();
    });
}

static RegisterShipInitFunc initFunc(RegisterItemQueue, { "IS_RANDO" });
