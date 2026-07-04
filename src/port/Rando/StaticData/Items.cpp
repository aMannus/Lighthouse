#include "StaticData.h"
#include <libultraship/bridge/consolevariablebridge.h>
#include "port/ShipUtils.h"
#include "port/Rando/Rando.h"
// #include "port/Rando/Logic/Logic.h"

#include "enums.h"

namespace Rando {

namespace StaticData {

#define RI(id, article, name, type, actorId)      \
    {                                             \
        id, {                                     \
            id, #id, article, name, type, actorId \
        }                                         \
    }

// clang-format off
std::map<RandoItemId, RandoStaticItem> Items = {
    RI(RI_UNKNOWN,                              "",     "Unknown",                              RITYPE_UNKNOWN,         ACTOR_1_UNKNOWN),
    RI(RI_EMPTY_HONEYCOMB_BUBBLEGLOOP_SWAMP,    "a",    "Empty Honeycomb (Bubblegloop Swamp)",  RITYPE_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB),
    RI(RI_EMPTY_HONEYCOMB_CLANKERS_CAVERN,      "a",    "Empty Honeycomb (Clanker's Cavern)",   RITYPE_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB),
    RI(RI_EMPTY_HONEYCOMB_CLICK_CLOCK_WOOD,     "a",    "Empty Honeycomb (Click Clock Wood)",   RITYPE_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB),
    RI(RI_EMPTY_HONEYCOMB_FREEZEEZY_PEAK,       "a",    "Empty Honeycomb (Freezeezy Peak)",     RITYPE_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB),
    RI(RI_EMPTY_HONEYCOMB_GOBIS_VALLEY,         "a",    "Empty Honeycomb (Gobi's Valley)",      RITYPE_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB),
    RI(RI_EMPTY_HONEYCOMB_GRUNTILDAS_LAIR,      "a",    "Empty Honeycomb (Gruntilda's Lair)",   RITYPE_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB),
    RI(RI_EMPTY_HONEYCOMB_MAD_MONSTER_MANSION,  "a",    "Empty Honeycomb (Mad Monster Mansion)",RITYPE_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB),
    RI(RI_EMPTY_HONEYCOMB_MUMBOS_MOUNTAIN,      "a",    "Empty Honeycomb (Mumbo's Mountain)",   RITYPE_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB),
    RI(RI_EMPTY_HONEYCOMB_RUSTY_BUCKET_BAY,     "a",    "Empty Honeycomb (Rusty Bucket Bay)",   RITYPE_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB),
    RI(RI_EMPTY_HONEYCOMB_SPIRAL_MOUNTAIN,      "a",    "Empty Honeycomb (Spiral Mountain)",    RITYPE_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB),
    RI(RI_EMPTY_HONEYCOMB_TREASURE_TROVE_COVE,  "a",    "Empty Honeycomb (Treasure Trove Cove)",RITYPE_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB),
    RI(RI_JIGGY_BUBBLEGLOOP_SWAMP,              "a",    "Jiggy (Bubblegloop Swamp)",            RITYPE_JIGGY,           ACTOR_46_JIGGY),
    RI(RI_JIGGY_CLANKERS_CAVERN,                "a",    "Jiggy (Clanker's Cavern)",             RITYPE_JIGGY,           ACTOR_46_JIGGY),
    RI(RI_JIGGY_CLICK_CLOCK_WOOD,               "a",    "Jiggy (Click Clock Wood)",             RITYPE_JIGGY,           ACTOR_46_JIGGY),
    RI(RI_JIGGY_FREEZEEZY_PEAK,                 "a",    "Jiggy (Freezeezy Peak)",               RITYPE_JIGGY,           ACTOR_46_JIGGY),
    RI(RI_JIGGY_GOBIS_VALLEY,                   "a",    "Jiggy (Gobi's Valley)",                RITYPE_JIGGY,           ACTOR_46_JIGGY),
    RI(RI_JIGGY_GRUNTILDAS_LAIR,                "a",    "Jiggy (Gruntilda's Lair)",             RITYPE_JIGGY,           ACTOR_46_JIGGY),
    RI(RI_JIGGY_MAD_MONSTER_MANSION,            "a",    "Jiggy (Mad Monster Mansion)",          RITYPE_JIGGY,           ACTOR_46_JIGGY),
    RI(RI_JIGGY_MUMBOS_MOUNTAIN,                "a",    "Jiggy (Mumbo's Mountain)",             RITYPE_JIGGY,           ACTOR_46_JIGGY),
    RI(RI_JIGGY_RUSTY_BUCKET_BAY,               "a",    "Jiggy (Rusty Bucket Bay)",             RITYPE_JIGGY,           ACTOR_46_JIGGY),
    RI(RI_JIGGY_TREASURE_TROVE_COVE,            "a",    "Jiggy (Treasure Trove Cove)",          RITYPE_JIGGY,           ACTOR_46_JIGGY),
    RI(RI_JINJO_BLUE_BUBBLEGLOOP_SWAMP,         "a",    "Blue Jinjo (Bubblegloop Swamp)",       RITYPE_JINJO,           ACTOR_60_JINJO_BLUE),
    RI(RI_JINJO_BLUE_CLANKERS_CAVERN,           "a",    "Blue Jinjo (Clanker's Cavern)",        RITYPE_JINJO,           ACTOR_60_JINJO_BLUE),
    RI(RI_JINJO_BLUE_CLICK_CLOCK_WOOD,          "a",    "Blue Jinjo (Click Clock Wood)",        RITYPE_JINJO,           ACTOR_60_JINJO_BLUE),
    RI(RI_JINJO_BLUE_FREEZEEZY_PEAK,            "a",    "Blue Jinjo (Freezeezy Peak)",          RITYPE_JINJO,           ACTOR_60_JINJO_BLUE),
    RI(RI_JINJO_BLUE_GOBIS_VALLEY,              "a",    "Blue Jinjo (Gobi's Valley)",           RITYPE_JINJO,           ACTOR_60_JINJO_BLUE),
    RI(RI_JINJO_BLUE_MAD_MONSTER_MANSION,       "a",    "Blue Jinjo (Mad Monster Mansion)",     RITYPE_JINJO,           ACTOR_60_JINJO_BLUE),
    RI(RI_JINJO_BLUE_MUMBOS_MOUNTAIN,           "a",    "Blue Jinjo (Mumbo's Mountain)",        RITYPE_JINJO,           ACTOR_60_JINJO_BLUE),
    RI(RI_JINJO_BLUE_RUSTY_BUCKET_BAY,          "a",    "Blue Jinjo (Rusty Bucket Bay)",        RITYPE_JINJO,           ACTOR_60_JINJO_BLUE),
    RI(RI_JINJO_BLUE_TREASURE_TROVE_COVE,       "a",    "Blue Jinjo (Treasure Trove Cove)",     RITYPE_JINJO,           ACTOR_60_JINJO_BLUE),
    RI(RI_JINJO_GREEN_BUBBLEGLOOP_SWAMP,        "a",    "Green Jinjo (Bubblegloop Swamp)",      RITYPE_JINJO,           ACTOR_62_JINJO_GREEN),
    RI(RI_JINJO_GREEN_CLANKERS_CAVERN,          "a",    "Green Jinjo (Clanker's Cavern)",       RITYPE_JINJO,           ACTOR_62_JINJO_GREEN),
    RI(RI_JINJO_GREEN_CLICK_CLOCK_WOOD,         "a",    "Green Jinjo (Click Clock Wood)",       RITYPE_JINJO,           ACTOR_62_JINJO_GREEN),
    RI(RI_JINJO_GREEN_FREEZEEZY_PEAK,           "a",    "Green Jinjo (Freezeezy Peak)",         RITYPE_JINJO,           ACTOR_62_JINJO_GREEN),
    RI(RI_JINJO_GREEN_GOBIS_VALLEY,             "a",    "Green Jinjo (Gobi's Valley)",          RITYPE_JINJO,           ACTOR_62_JINJO_GREEN),
    RI(RI_JINJO_GREEN_MAD_MONSTER_MANSION,      "a",    "Green Jinjo (Mad Monster Mansion)",    RITYPE_JINJO,           ACTOR_62_JINJO_GREEN),
    RI(RI_JINJO_GREEN_MUMBOS_MOUNTAIN,          "a",    "Green Jinjo (Mumbo's Mountain)",       RITYPE_JINJO,           ACTOR_62_JINJO_GREEN),
    RI(RI_JINJO_GREEN_RUSTY_BUCKET_BAY,         "a",    "Green Jinjo (Rusty Bucket Bay)",       RITYPE_JINJO,           ACTOR_62_JINJO_GREEN),
    RI(RI_JINJO_GREEN_TREASURE_TROVE_COVE,      "a",    "Green Jinjo (Treasure Trove Cove)",    RITYPE_JINJO,           ACTOR_62_JINJO_GREEN),
    RI(RI_JINJO_ORANGE_BUBBLEGLOOP_SWAMP,       "a",    "Orange Jinjo (Bubblegloop Swamp)",     RITYPE_JINJO,           ACTOR_5F_JINJO_ORANGE),
    RI(RI_JINJO_ORANGE_CLANKERS_CAVERN,         "a",    "Orange Jinjo (Clanker's Cavern)",      RITYPE_JINJO,           ACTOR_5F_JINJO_ORANGE),
    RI(RI_JINJO_ORANGE_CLICK_CLOCK_WOOD,        "a",    "Orange Jinjo (Click Clock Wood)",      RITYPE_JINJO,           ACTOR_5F_JINJO_ORANGE),
    RI(RI_JINJO_ORANGE_FREEZEEZY_PEAK,          "a",    "Orange Jinjo (Freezeezy Peak)",        RITYPE_JINJO,           ACTOR_5F_JINJO_ORANGE),
    RI(RI_JINJO_ORANGE_GOBIS_VALLEY,            "a",    "Orange Jinjo (Gobi's Valley)",         RITYPE_JINJO,           ACTOR_5F_JINJO_ORANGE),
    RI(RI_JINJO_ORANGE_MAD_MONSTER_MANSION,     "a",    "Orange Jinjo (Mad Monster Mansion)",   RITYPE_JINJO,           ACTOR_5F_JINJO_ORANGE),
    RI(RI_JINJO_ORANGE_MUMBOS_MOUNTAIN,         "a",    "Orange Jinjo (Mumbo's Mountain)",      RITYPE_JINJO,           ACTOR_5F_JINJO_ORANGE),
    RI(RI_JINJO_ORANGE_RUSTY_BUCKET_BAY,        "a",    "Orange Jinjo (Rusty Bucket Bay)",      RITYPE_JINJO,           ACTOR_5F_JINJO_ORANGE),
    RI(RI_JINJO_ORANGE_TREASURE_TROVE_COVE,     "a",    "Orange Jinjo (Treasure Trove Cove)",   RITYPE_JINJO,           ACTOR_5F_JINJO_ORANGE),
    RI(RI_JINJO_PINK_BUBBLEGLOOP_SWAMP,         "a",    "Pink Jinjo (Bubblegloop Swamp)",       RITYPE_JINJO,           ACTOR_61_JINJO_PINK),
    RI(RI_JINJO_PINK_CLANKERS_CAVERN,           "a",    "Pink Jinjo (Clanker's Cavern)",        RITYPE_JINJO,           ACTOR_61_JINJO_PINK),
    RI(RI_JINJO_PINK_CLICK_CLOCK_WOOD,          "a",    "Pink Jinjo (Click Clock Wood)",        RITYPE_JINJO,           ACTOR_61_JINJO_PINK),
    RI(RI_JINJO_PINK_FREEZEEZY_PEAK,            "a",    "Pink Jinjo (Freezeezy Peak)",          RITYPE_JINJO,           ACTOR_61_JINJO_PINK),
    RI(RI_JINJO_PINK_GOBIS_VALLEY,              "a",    "Pink Jinjo (Gobi's Valley)",           RITYPE_JINJO,           ACTOR_61_JINJO_PINK),
    RI(RI_JINJO_PINK_MAD_MONSTER_MANSION,       "a",    "Pink Jinjo (Mad Monster Mansion)",     RITYPE_JINJO,           ACTOR_61_JINJO_PINK),
    RI(RI_JINJO_PINK_MUMBOS_MOUNTAIN,           "a",    "Pink Jinjo (Mumbo's Mountain)",        RITYPE_JINJO,           ACTOR_61_JINJO_PINK),
    RI(RI_JINJO_PINK_RUSTY_BUCKET_BAY,          "a",    "Pink Jinjo (Rusty Bucket Bay)",        RITYPE_JINJO,           ACTOR_61_JINJO_PINK),
    RI(RI_JINJO_PINK_TREASURE_TROVE_COVE,       "a",    "Pink Jinjo (Treasure Trove Cove)",     RITYPE_JINJO,           ACTOR_61_JINJO_PINK),
    RI(RI_JINJO_YELLOW_BUBBLEGLOOP_SWAMP,       "a",    "Yellow Jinjo (Bubblegloop Swamp)",     RITYPE_JINJO,           ACTOR_5E_JINJO_YELLOW),
    RI(RI_JINJO_YELLOW_CLANKERS_CAVERN,         "a",    "Yellow Jinjo (Clanker's Cavern)",      RITYPE_JINJO,           ACTOR_5E_JINJO_YELLOW),
    RI(RI_JINJO_YELLOW_CLICK_CLOCK_WOOD,        "a",    "Yellow Jinjo (Click Clock Wood)",      RITYPE_JINJO,           ACTOR_5E_JINJO_YELLOW),
    RI(RI_JINJO_YELLOW_FREEZEEZY_PEAK,          "a",    "Yellow Jinjo (Freezeezy Peak)",        RITYPE_JINJO,           ACTOR_5E_JINJO_YELLOW),
    RI(RI_JINJO_YELLOW_GOBIS_VALLEY,            "a",    "Yellow Jinjo (Gobi's Valley)",         RITYPE_JINJO,           ACTOR_5E_JINJO_YELLOW),
    RI(RI_JINJO_YELLOW_MAD_MONSTER_MANSION,     "a",    "Yellow Jinjo (Mad Monster Mansion)",   RITYPE_JINJO,           ACTOR_5E_JINJO_YELLOW),
    RI(RI_JINJO_YELLOW_MUMBOS_MOUNTAIN,         "a",    "Yellow Jinjo (Mumbo's Mountain)",      RITYPE_JINJO,           ACTOR_5E_JINJO_YELLOW),
    RI(RI_JINJO_YELLOW_RUSTY_BUCKET_BAY,        "a",    "Yellow Jinjo (Rusty Bucket Bay)",      RITYPE_JINJO,           ACTOR_5E_JINJO_YELLOW),
    RI(RI_JINJO_YELLOW_TREASURE_TROVE_COVE,     "a",    "Yellow Jinjo (Treasure Trove Cove)",   RITYPE_JINJO,           ACTOR_5E_JINJO_YELLOW),
    RI(RI_MOLEHILL_BARGE,                       "",     "Beak Barge",                           RITYPE_MOLEHILL,        ACTOR_12C_MOLEHILL),
    RI(RI_MOLEHILL_BEAK_BOMB,                   "",     "Beak Bomb",                            RITYPE_MOLEHILL,        ACTOR_12C_MOLEHILL),
    RI(RI_MOLEHILL_BEAK_BUSTER,                 "",     "Beak Buster",                          RITYPE_MOLEHILL,        ACTOR_12C_MOLEHILL),
    RI(RI_MOLEHILL_CAMERA_CONTROL,              "",     "Camera Control",                       RITYPE_MOLEHILL,        ACTOR_12C_MOLEHILL),
    RI(RI_MOLEHILL_CLAW_SWIPE,                  "",     "Claw Swipe",                           RITYPE_MOLEHILL,        ACTOR_12C_MOLEHILL),
    RI(RI_MOLEHILL_CLIMB,                       "",     "Climb",                                RITYPE_MOLEHILL,        ACTOR_12C_MOLEHILL),
    RI(RI_MOLEHILL_DIVE,                        "",     "Dive",                                 RITYPE_MOLEHILL,        ACTOR_12C_MOLEHILL),
    RI(RI_MOLEHILL_EGGS,                        "",     "Eggs",                                 RITYPE_MOLEHILL,        ACTOR_12C_MOLEHILL),
    RI(RI_MOLEHILL_FLAP_FLIP,                   "",     "Flap Flip",                            RITYPE_MOLEHILL,        ACTOR_12C_MOLEHILL),
    RI(RI_MOLEHILL_FLIGHT,                      "",     "Flight",                               RITYPE_MOLEHILL,        ACTOR_12C_MOLEHILL),
    RI(RI_MOLEHILL_SHOCK_JUMP,                  "",     "Shock Jump",                           RITYPE_MOLEHILL,        ACTOR_12C_MOLEHILL),
    RI(RI_MOLEHILL_TALON_TROT,                  "",     "Talon Trot",                           RITYPE_MOLEHILL,        ACTOR_12C_MOLEHILL),
    RI(RI_MOLEHILL_TURBO_TALON,                 "",     "Turbo Talon",                          RITYPE_MOLEHILL,        ACTOR_12C_MOLEHILL),
    RI(RI_MOLEHILL_WADING_BOOTS,                "",     "Wading Boots",                         RITYPE_MOLEHILL,        ACTOR_12C_MOLEHILL),
    RI(RI_MOLEHILL_WONDERWING,                  "",     "Wonderwing",                           RITYPE_MOLEHILL,        ACTOR_12C_MOLEHILL),
    RI(RI_MUMBO_TOKEN_BUBBLEGLOOP_SWAMP,        "a",    "Mumbo Token (Bubblegloop Swamp)",      RITYPE_MUMBO_TOKEN,     ACTOR_2D_MUMBO_TOKEN),
    RI(RI_MUMBO_TOKEN_CLANKERS_CAVERN,          "a",    "Mumbo Token (Clanker's Cavern)",       RITYPE_MUMBO_TOKEN,     ACTOR_2D_MUMBO_TOKEN),
    RI(RI_MUMBO_TOKEN_CLICK_CLOCK_WOOD,         "a",    "Mumbo Token (Click Clock Wood)",       RITYPE_MUMBO_TOKEN,     ACTOR_2D_MUMBO_TOKEN),
    RI(RI_MUMBO_TOKEN_FREEZEEZY_PEAK,           "a",    "Mumbo Token (Freezeezy Peak)",         RITYPE_MUMBO_TOKEN,     ACTOR_2D_MUMBO_TOKEN),
    RI(RI_MUMBO_TOKEN_GOBIS_VALLEY,             "a",    "Mumbo Token (Gobi's Valley)",          RITYPE_MUMBO_TOKEN,     ACTOR_2D_MUMBO_TOKEN),
    RI(RI_MUMBO_TOKEN_GRUNTILDAS_LAIR,          "a",    "Mumbo Token (Gruntilda's Lair)",       RITYPE_MUMBO_TOKEN,     ACTOR_2D_MUMBO_TOKEN),
    RI(RI_MUMBO_TOKEN_MAD_MONSTER_MANSION,      "a",    "Mumbo Token (Mad Monster Mansion)",    RITYPE_MUMBO_TOKEN,     ACTOR_2D_MUMBO_TOKEN),
    RI(RI_MUMBO_TOKEN_MUMBOS_MOUNTAIN,          "a",    "Mumbo Token (Click Clock Wood)",       RITYPE_MUMBO_TOKEN,     ACTOR_2D_MUMBO_TOKEN),
    RI(RI_MUMBO_TOKEN_RUSTY_BUCKET_BAY,         "a",    "Mumbo Token (Rusty Bucket Bay)",       RITYPE_MUMBO_TOKEN,     ACTOR_2D_MUMBO_TOKEN),
    RI(RI_MUMBO_TOKEN_TREASURE_TROVE_COVE,      "a",    "Mumbo Token (Treasure Trove Cove)",    RITYPE_MUMBO_TOKEN,     ACTOR_2D_MUMBO_TOKEN),
    RI(RI_MUSIC_NOTE_BUBBLEGLOOP_SWAMP,         "a",    "Note (Bubblegloop Swamp)",             RITYPE_MUSIC_NOTE,      ACTOR_51_MUSIC_NOTE),
    RI(RI_MUSIC_NOTE_CLANKERS_CAVERN,           "a",    "Note (Clanker's Cavern)",              RITYPE_MUSIC_NOTE,      ACTOR_51_MUSIC_NOTE),
    RI(RI_MUSIC_NOTE_CLICK_CLOCK_WOOD,          "a",    "Note (Click Clock Wood)",              RITYPE_MUSIC_NOTE,      ACTOR_51_MUSIC_NOTE),
    RI(RI_MUSIC_NOTE_FREEZEEZY_PEAK,            "a",    "Note (Freezeezy Peak)",                RITYPE_MUSIC_NOTE,      ACTOR_51_MUSIC_NOTE),
    RI(RI_MUSIC_NOTE_GOBIS_VALLEY,              "a",    "Note (Gobi's Valley)",                 RITYPE_MUSIC_NOTE,      ACTOR_51_MUSIC_NOTE),
    RI(RI_MUSIC_NOTE_MAD_MONSTER_MANSION,       "a",    "Note (Mad Monster Mansion)",           RITYPE_MUSIC_NOTE,      ACTOR_51_MUSIC_NOTE),
    RI(RI_MUSIC_NOTE_MUMBOS_MOUNTAIN,           "a",    "Note (Mumbo's Mountain)",              RITYPE_MUSIC_NOTE,      ACTOR_51_MUSIC_NOTE),
    RI(RI_MUSIC_NOTE_RUSTY_BUCKET_BAY,          "a",    "Note (Rusty Bucket Bay)",              RITYPE_MUSIC_NOTE,      ACTOR_51_MUSIC_NOTE),
    RI(RI_MUSIC_NOTE_TREASURE_TROVE_COVE,       "a",    "Note (Treasure Trove Cove)",           RITYPE_MUSIC_NOTE,      ACTOR_51_MUSIC_NOTE),
    RI(RI_STOP_N_SWOP_EGG_BLUE,                 "a",    "Blue Egg",                             RITYPE_SNS_EGG,         ACTOR_25E_SNS_EGG),
    RI(RI_STOP_N_SWOP_EGG_CYAN,                 "a",    "Cyan Egg",                             RITYPE_SNS_EGG,         ACTOR_25E_SNS_EGG),
    RI(RI_STOP_N_SWOP_EGG_GREEN,                "a",    "Green Egg",                            RITYPE_SNS_EGG,         ACTOR_25E_SNS_EGG),
    RI(RI_STOP_N_SWOP_EGG_PINK,                 "a",    "Pink Egg",                             RITYPE_SNS_EGG,         ACTOR_25E_SNS_EGG),
    RI(RI_STOP_N_SWOP_EGG_RED,                  "a",    "Red Egg",                              RITYPE_SNS_EGG,         ACTOR_25E_SNS_EGG),
    RI(RI_STOP_N_SWOP_EGG_YELLOW,               "a",    "Yellow Egg",                           RITYPE_SNS_EGG,         ACTOR_25E_SNS_EGG),
    RI(RI_STOP_N_SWOP_ICE_KEY,                  "an",   "Ice Key",                              RITYPE_SNS_KEY,         ACTOR_25D_ICE_KEY),
};
// clang-format on

RandoItemId GetRandoItemByActorId(actor_e actorId) {
    for (auto& [randoItemId, randoStaticItem] : Items) {
        if (randoStaticItem.actorId == actorId) {
            return randoItemId;
        }
    }
    return RI_UNKNOWN;
}

actor_e GetActorIdByRandoItemId(RandoItemId randoItemId) {
    for (auto& [itemId, randoStaticItem] : Items) {
        if (itemId == randoItemId) {
            return (actor_e)randoStaticItem.actorId;
        }
    }
    return ACTOR_1_UNKNOWN;
}

} // namespace StaticData
} // namespace Rando