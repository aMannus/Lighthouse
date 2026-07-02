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
    RI(RI_EMPTY_HONEYCOMB_BUBBLEGLOOP_SWAMP,    "a",    "Bubblegloop Swamp Empty Honeycomb",    RITYPE_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB),
    RI(RI_EMPTY_HONEYCOMB_CLANKERS_CAVERN,      "a",    "Clanker's Cavern Empty Honeycomb",     RITYPE_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB),
    RI(RI_EMPTY_HONEYCOMB_CLICK_CLOCK_WOOD,     "a",    "Click Clock Wood Empty Honeycomb",     RITYPE_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB),
    RI(RI_EMPTY_HONEYCOMB_FREEZEEZY_PEAK,       "a",    "Freezeezy Peak Empty Honeycomb",       RITYPE_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB),
    RI(RI_EMPTY_HONEYCOMB_GOBIS_VALLEY,         "a",    "Gobi's Valley Empty Honeycomb",        RITYPE_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB),
    RI(RI_EMPTY_HONEYCOMB_GRUNTILDAS_LAIR,      "a",    "Gruntilda's Lair Empty Honeycomb",     RITYPE_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB),
    RI(RI_EMPTY_HONEYCOMB_MAD_MONSTER_MANSION,  "a",    "Mad Monster Mansion Empty Honeycomb",  RITYPE_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB),
    RI(RI_EMPTY_HONEYCOMB_MUMBOS_MOUNTAIN,      "a",    "Mumbo's Mountain Empty Honeycomb",     RITYPE_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB),
    RI(RI_EMPTY_HONEYCOMB_RUSTY_BUCKET_BAY,     "a",    "Rusty Bucket Bay Empty Honeycomb",     RITYPE_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB),
    RI(RI_EMPTY_HONEYCOMB_SPIRAL_MOUNTAIN,      "a",    "Spiral Mountain Empty Honeycomb",      RITYPE_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB),
    RI(RI_EMPTY_HONEYCOMB_TREASURE_TROVE_COVE,  "a",    "Treasure Trove Cove Empty Honeycomb",  RITYPE_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB),
    RI(RI_JIGGY_BUBBLEGLOOP_SWAMP,              "a",    "Bubblegloop Swamp Jiggy",              RITYPE_JIGGY,           ACTOR_46_JIGGY),
    RI(RI_JIGGY_CLANKERS_CAVERN,                "a",    "Clanker's Cavern Jiggy",               RITYPE_JIGGY,           ACTOR_46_JIGGY),
    RI(RI_JIGGY_CLICK_CLOCK_WOOD,               "a",    "Click Clock Wood Jiggy",               RITYPE_JIGGY,           ACTOR_46_JIGGY),
    RI(RI_JIGGY_FREEZEEZY_PEAK,                 "a",    "Freezeezy Peak Jiggy",                 RITYPE_JIGGY,           ACTOR_46_JIGGY),
    RI(RI_JIGGY_GOBIS_VALLEY,                   "a",    "Gobi's Valley Jiggy",                  RITYPE_JIGGY,           ACTOR_46_JIGGY),
    RI(RI_JIGGY_GRUNTILDAS_LAIR,                "a",    "Gruntilda's Lair Jiggy",               RITYPE_JIGGY,           ACTOR_46_JIGGY),
    RI(RI_JIGGY_MAD_MONSTER_MANSION,            "a",    "Mad Monster Mansion Jiggy",            RITYPE_JIGGY,           ACTOR_46_JIGGY),
    RI(RI_JIGGY_MUMBOS_MOUNTAIN,                "a",    "Mumbo's Mountain Jiggy",               RITYPE_JIGGY,           ACTOR_46_JIGGY),
    RI(RI_JIGGY_RUSTY_BUCKET_BAY,               "a",    "Rusty Bucket Bay Jiggy",               RITYPE_JIGGY,           ACTOR_46_JIGGY),
    RI(RI_JIGGY_TREASURE_TROVE_COVE,            "a",    "Treasure Trove Cove Jiggy",            RITYPE_JIGGY,           ACTOR_46_JIGGY),
    RI(RI_JINJO_BLUE_BUBBLEGLOOP_SWAMP,         "a",    "Bubblegloop Swamp Blue Jinjo",         RITYPE_JINJO,           ACTOR_60_JINJO_BLUE),
    RI(RI_JINJO_BLUE_CLANKERS_CAVERN,           "a",    "Clanker's Cavern Blue Jinjo",          RITYPE_JINJO,           ACTOR_60_JINJO_BLUE),
    RI(RI_JINJO_BLUE_CLICK_CLOCK_WOOD,          "a",    "Click Clock Wood Blue Jinjo",          RITYPE_JINJO,           ACTOR_60_JINJO_BLUE),
    RI(RI_JINJO_BLUE_FREEZEEZY_PEAK,            "a",    "Freezeezy Peak Blue Jinjo",            RITYPE_JINJO,           ACTOR_60_JINJO_BLUE),
    RI(RI_JINJO_BLUE_GOBIS_VALLEY,              "a",    "Gobi's Valley Blue Jinjo",             RITYPE_JINJO,           ACTOR_60_JINJO_BLUE),
    RI(RI_JINJO_BLUE_MAD_MONSTER_MANSION,       "a",    "Mad Monster Mansion Blue Jinjo",       RITYPE_JINJO,           ACTOR_60_JINJO_BLUE),
    RI(RI_JINJO_BLUE_MUMBOS_MOUNTAIN,           "a",    "Mumbo's Mountain Blue Jinjo",          RITYPE_JINJO,           ACTOR_60_JINJO_BLUE),
    RI(RI_JINJO_BLUE_RUSTY_BUCKET_BAY,          "a",    "Rusty Bucket Bay Blue Jinjo",          RITYPE_JINJO,           ACTOR_60_JINJO_BLUE),
    RI(RI_JINJO_BLUE_TREASURE_TROVE_COVE,       "a",    "Treasure Trove Cove Blue Jinjo",       RITYPE_JINJO,           ACTOR_60_JINJO_BLUE),
    RI(RI_JINJO_GREEN_BUBBLEGLOOP_SWAMP,        "a",    "Bubblegloop Swamp Green Jinjo",        RITYPE_JINJO,           ACTOR_62_JINJO_GREEN),
    RI(RI_JINJO_GREEN_CLANKERS_CAVERN,          "a",    "Clanker's Cavern Green Jinjo",         RITYPE_JINJO,           ACTOR_62_JINJO_GREEN),
    RI(RI_JINJO_GREEN_CLICK_CLOCK_WOOD,         "a",    "Click Clock Wood Green Jinjo",         RITYPE_JINJO,           ACTOR_62_JINJO_GREEN),
    RI(RI_JINJO_GREEN_FREEZEEZY_PEAK,           "a",    "Freezeezy Peak Green Jinjo",           RITYPE_JINJO,           ACTOR_62_JINJO_GREEN),
    RI(RI_JINJO_GREEN_GOBIS_VALLEY,             "a",    "Gobi's Valley Green Jinjo",            RITYPE_JINJO,           ACTOR_62_JINJO_GREEN),
    RI(RI_JINJO_GREEN_MAD_MONSTER_MANSION,      "a",    "Mad Monster Mansion Green Jinjo",      RITYPE_JINJO,           ACTOR_62_JINJO_GREEN),
    RI(RI_JINJO_GREEN_MUMBOS_MOUNTAIN,          "a",    "Mumbo's Mountain Green Jinjo",         RITYPE_JINJO,           ACTOR_62_JINJO_GREEN),
    RI(RI_JINJO_GREEN_RUSTY_BUCKET_BAY,         "a",    "Rusty Bucket Bay Green Jinjo",         RITYPE_JINJO,           ACTOR_62_JINJO_GREEN),
    RI(RI_JINJO_GREEN_TREASURE_TROVE_COVE,      "a",    "Treasure Trove Cove Green Jinjo",      RITYPE_JINJO,           ACTOR_62_JINJO_GREEN),
    RI(RI_JINJO_ORANGE_BUBBLEGLOOP_SWAMP,       "a",    "Bubblegloop Swamp Orange Jinjo",       RITYPE_JINJO,           ACTOR_5F_JINJO_ORANGE),
    RI(RI_JINJO_ORANGE_CLANKERS_CAVERN,         "a",    "Clanker's Cavern Orange Jinjo",        RITYPE_JINJO,           ACTOR_5F_JINJO_ORANGE),
    RI(RI_JINJO_ORANGE_CLICK_CLOCK_WOOD,        "a",    "Click Clock Wood Orange Jinjo",        RITYPE_JINJO,           ACTOR_5F_JINJO_ORANGE),
    RI(RI_JINJO_ORANGE_FREEZEEZY_PEAK,          "a",    "Freezeezy Peak Orange Jinjo",          RITYPE_JINJO,           ACTOR_5F_JINJO_ORANGE),
    RI(RI_JINJO_ORANGE_GOBIS_VALLEY,            "a",    "Gobi's Valley Orange Jinjo",           RITYPE_JINJO,           ACTOR_5F_JINJO_ORANGE),
    RI(RI_JINJO_ORANGE_MAD_MONSTER_MANSION,     "a",    "Mad Monster Mansion Orange Jinjo",     RITYPE_JINJO,           ACTOR_5F_JINJO_ORANGE),
    RI(RI_JINJO_ORANGE_MUMBOS_MOUNTAIN,         "a",    "Mumbo's Mountain Orange Jinjo",        RITYPE_JINJO,           ACTOR_5F_JINJO_ORANGE),
    RI(RI_JINJO_ORANGE_RUSTY_BUCKET_BAY,        "a",    "Rusty Bucket Bay Orange Jinjo",        RITYPE_JINJO,           ACTOR_5F_JINJO_ORANGE),
    RI(RI_JINJO_ORANGE_TREASURE_TROVE_COVE,     "a",    "Treasure Trove Cove Orange Jinjo",     RITYPE_JINJO,           ACTOR_5F_JINJO_ORANGE),
    RI(RI_JINJO_PINK_BUBBLEGLOOP_SWAMP,         "a",    "Bubblegloop Swamp Pink Jinjo",         RITYPE_JINJO,           ACTOR_61_JINJO_PINK),
    RI(RI_JINJO_PINK_CLANKERS_CAVERN,           "a",    "Clanker's Cavern Pink Jinjo",          RITYPE_JINJO,           ACTOR_61_JINJO_PINK),
    RI(RI_JINJO_PINK_CLICK_CLOCK_WOOD,          "a",    "Click Clock Wood Pink Jinjo",          RITYPE_JINJO,           ACTOR_61_JINJO_PINK),
    RI(RI_JINJO_PINK_FREEZEEZY_PEAK,            "a",    "Freezeezy Peak Pink Jinjo",            RITYPE_JINJO,           ACTOR_61_JINJO_PINK),
    RI(RI_JINJO_PINK_GOBIS_VALLEY,              "a",    "Gobi's Valley Pink Jinjo",             RITYPE_JINJO,           ACTOR_61_JINJO_PINK),
    RI(RI_JINJO_PINK_MAD_MONSTER_MANSION,       "a",    "Mad Monster Mansion Pink Jinjo",       RITYPE_JINJO,           ACTOR_61_JINJO_PINK),
    RI(RI_JINJO_PINK_MUMBOS_MOUNTAIN,           "a",    "Mumbo's Mountain Pink Jinjo",          RITYPE_JINJO,           ACTOR_61_JINJO_PINK),
    RI(RI_JINJO_PINK_RUSTY_BUCKET_BAY,          "a",    "Rusty Bucket Bay Pink Jinjo",          RITYPE_JINJO,           ACTOR_61_JINJO_PINK),
    RI(RI_JINJO_PINK_TREASURE_TROVE_COVE,       "a",    "Treasure Trove Cove Pink Jinjo",       RITYPE_JINJO,           ACTOR_61_JINJO_PINK),
    RI(RI_JINJO_YELLOW_BUBBLEGLOOP_SWAMP,       "a",    "Bubblegloop Swamp Yellow Jinjo",       RITYPE_JINJO,           ACTOR_5E_JINJO_YELLOW),
    RI(RI_JINJO_YELLOW_CLANKERS_CAVERN,         "a",    "Clanker's Cavern Yellow Jinjo",        RITYPE_JINJO,           ACTOR_5E_JINJO_YELLOW),
    RI(RI_JINJO_YELLOW_CLICK_CLOCK_WOOD,        "a",    "Click Clock Wood Yellow Jinjo",        RITYPE_JINJO,           ACTOR_5E_JINJO_YELLOW),
    RI(RI_JINJO_YELLOW_FREEZEEZY_PEAK,          "a",    "Freezeezy Peak Yellow Jinjo",          RITYPE_JINJO,           ACTOR_5E_JINJO_YELLOW),
    RI(RI_JINJO_YELLOW_GOBIS_VALLEY,            "a",    "Gobi's Valley Yellow Jinjo",           RITYPE_JINJO,           ACTOR_5E_JINJO_YELLOW),
    RI(RI_JINJO_YELLOW_MAD_MONSTER_MANSION,     "a",    "Mad Monster Mansion Yellow Jinjo",     RITYPE_JINJO,           ACTOR_5E_JINJO_YELLOW),
    RI(RI_JINJO_YELLOW_MUMBOS_MOUNTAIN,         "a",    "Mumbo's Mountain Yellow Jinjo",        RITYPE_JINJO,           ACTOR_5E_JINJO_YELLOW),
    RI(RI_JINJO_YELLOW_RUSTY_BUCKET_BAY,        "a",    "Rusty Bucket Bay Yellow Jinjo",        RITYPE_JINJO,           ACTOR_5E_JINJO_YELLOW),
    RI(RI_JINJO_YELLOW_TREASURE_TROVE_COVE,     "a",    "Treasure Trove Cove Yellow Jinjo",     RITYPE_JINJO,           ACTOR_5E_JINJO_YELLOW),
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
    RI(RI_MUMBO_TOKEN_BUBBLEGLOOP_SWAMP,        "a",    "Bubblegloop Swamp Mumbo Token",        RITYPE_MUMBO_TOKEN,     ACTOR_2D_MUMBO_TOKEN),
    RI(RI_MUMBO_TOKEN_CLANKERS_CAVERN,          "a",    "Clanker's Cavern Mumbo Token",         RITYPE_MUMBO_TOKEN,     ACTOR_2D_MUMBO_TOKEN),
    RI(RI_MUMBO_TOKEN_CLICK_CLOCK_WOOD,         "a",    "Click Clock Wood Mumbo Token",         RITYPE_MUMBO_TOKEN,     ACTOR_2D_MUMBO_TOKEN),
    RI(RI_MUMBO_TOKEN_FREEZEEZY_PEAK,           "a",    "Freezeezy Peak Mumbo Token",           RITYPE_MUMBO_TOKEN,     ACTOR_2D_MUMBO_TOKEN),
    RI(RI_MUMBO_TOKEN_GOBIS_VALLEY,             "a",    "Gobi's Valley Mumbo Token",            RITYPE_MUMBO_TOKEN,     ACTOR_2D_MUMBO_TOKEN),
    RI(RI_MUMBO_TOKEN_GRUNTILDAS_LAIR,          "a",    "Gruntilda's Lair Mumbo Token",         RITYPE_MUMBO_TOKEN,     ACTOR_2D_MUMBO_TOKEN),
    RI(RI_MUMBO_TOKEN_MAD_MONSTER_MANSION,      "a",    "Mad Monster Mansion Mumbo Token",      RITYPE_MUMBO_TOKEN,     ACTOR_2D_MUMBO_TOKEN),
    RI(RI_MUMBO_TOKEN_MUMBOS_MOUNTAIN,          "a",    "Click Clock Wood Mumbo Token",         RITYPE_MUMBO_TOKEN,     ACTOR_2D_MUMBO_TOKEN),
    RI(RI_MUMBO_TOKEN_RUSTY_BUCKET_BAY,         "a",    "Rusty Bucket Bay Mumbo Token",         RITYPE_MUMBO_TOKEN,     ACTOR_2D_MUMBO_TOKEN),
    RI(RI_MUMBO_TOKEN_TREASURE_TROVE_COVE,      "a",    "Treasure Trove Cove Mumbo Token",      RITYPE_MUMBO_TOKEN,     ACTOR_2D_MUMBO_TOKEN),
    RI(RI_MUSIC_NOTE_BUBBLEGLOOP_SWAMP,         "a",    "Bubblegloop Swamp Note",               RITYPE_MUSIC_NOTE,      ACTOR_51_MUSIC_NOTE),
    RI(RI_MUSIC_NOTE_CLANKERS_CAVERN,           "a",    "Clanker's Cavern Note",                RITYPE_MUSIC_NOTE,      ACTOR_51_MUSIC_NOTE),
    RI(RI_MUSIC_NOTE_CLICK_CLOCK_WOOD,          "a",    "Click Clock Wood Note",                RITYPE_MUSIC_NOTE,      ACTOR_51_MUSIC_NOTE),
    RI(RI_MUSIC_NOTE_FREEZEEZY_PEAK,            "a",    "Freezeezy Peak Note",                  RITYPE_MUSIC_NOTE,      ACTOR_51_MUSIC_NOTE),
    RI(RI_MUSIC_NOTE_GOBIS_VALLEY,              "a",    "Gobi's Valley Note",                   RITYPE_MUSIC_NOTE,      ACTOR_51_MUSIC_NOTE),
    RI(RI_MUSIC_NOTE_MAD_MONSTER_MANSION,       "a",    "Mad Monster Mansion Note",             RITYPE_MUSIC_NOTE,      ACTOR_51_MUSIC_NOTE),
    RI(RI_MUSIC_NOTE_MUMBOS_MOUNTAIN,           "a",    "Mumbo's Mountain Note",                RITYPE_MUSIC_NOTE,      ACTOR_51_MUSIC_NOTE),
    RI(RI_MUSIC_NOTE_RUSTY_BUCKET_BAY,          "a",    "Rusty Bucket Bay Note",                RITYPE_MUSIC_NOTE,      ACTOR_51_MUSIC_NOTE),
    RI(RI_MUSIC_NOTE_TREASURE_TROVE_COVE,       "a",    "Treasure Trove Cove Note",             RITYPE_MUSIC_NOTE,      ACTOR_51_MUSIC_NOTE),
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