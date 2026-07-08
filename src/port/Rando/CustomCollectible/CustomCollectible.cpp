#include "CustomCollectible.h"
#include "CustomCollectibleDrawCustom.h"
#include "actor.h"
#include <unordered_map>
#include "port/Rando/Rando.h"
#include <print>

extern "C" {
#include "core1/sns.h"
Actor* actor_new(s32 position[3], s32 yaw, ActorInfo* actorInfo, u32 flags);
Actor* actor_draw(ActorMarker* marker, Gfx** gfx, Mtx** mtx, Vtx** vtx);
Actor* fxTouchSparkle_draw(ActorMarker* marker, Gfx** gfx, Mtx** mtx, Vtx** vtx);
Actor* marker_getActor(ActorMarker* thisx);
void marker_despawn(ActorMarker* marker);
Actor* func_802D41C4(ActorMarker* marker, Gfx** gfx, Mtx** mtx, Vtx** vtx);
}

std::unordered_map<actor_e, CustomCollectibleDrawInfo> customCollectibleDrawInfo = { 
    { ACTOR_47_EMPTY_HONEYCOMB, { ASSET_361_MODEL_EMPTY_HONEYCOMB, CCT_VANILLA_MODEL } },
    { ACTOR_46_JIGGY, { ASSET_35F_MODEL_JIGGY, CCT_VANILLA_MODEL } },
    { ACTOR_60_JINJO_BLUE, { ASSET_3C0_MODEL_JINJO_BLUE, CCT_VANILLA_MODEL } },
    { ACTOR_62_JINJO_GREEN, { ASSET_3C2_MODEL_JINJO_GREEN, CCT_VANILLA_MODEL } },
    { ACTOR_5F_JINJO_ORANGE, { ASSET_3BC_MODEL_JINJO_ORANGE, CCT_VANILLA_MODEL } },
    { ACTOR_61_JINJO_PINK, { ASSET_3C1_MODEL_JINJO_PINK, CCT_VANILLA_MODEL } },
    { ACTOR_5E_JINJO_YELLOW, { ASSET_3BB_MODEL_JINJO_YELLOW, CCT_VANILLA_MODEL } },
    { ACTOR_12C_MOLEHILL, { ASSET_388_MODEL_MOLEHILL, CCT_VANILLA_MODEL } },
    { ACTOR_2D_MUMBO_TOKEN, { ASSET_41A_SPRITE_MUMBO_TOKEN, CCT_VANILLA_SPRITE } },
    { ACTOR_51_MUSIC_NOTE, { ASSET_6D6_SPRITE_MUSIC_NOTE, CCT_VANILLA_SPRITE } },
    { ACTOR_25E_SNS_EGG, { ASSET_50D_MODEL_SNS_EGG, CCT_VANILLA_SNS_EGG } },
    { ACTOR_25D_ICE_KEY, { ASSET_0_NONE, CCT_CUSTOM_MODEL } },
};

ActorInfo customActorInfo = { MARKER_300_CUSTOM_COLLECTIBLE,
                              ACTOR_3CD_CUSTOM_COLLECTIBLE,
                              ASSET_0_NONE,
                              1,
                              NULL,
                              CustomCollectible_Update,
                              NULL,
                              NULL,
                              0,
                              0,
                              0.9f,
                              0 };

void Update(Actor* actor) {
    ActorLocal_CustomCollectible* customLocal = (ActorLocal_CustomCollectible*)&actor->local;

    if (!actor->initialized) {
        actor->initialized = true;
        actor->marker->collidable = true;

        if (customLocal->randoItemId >= RI_MUSIC_NOTE_BUBBLEGLOOP_SWAMP &&
            customLocal->randoItemId <= RI_MUSIC_NOTE_TREASURE_TROVE_COVE) {
            actor->scale = 0.4f;
        } else if (customLocal->randoItemId >= RI_STOP_N_SWOP_EGG_BLUE &&
                   customLocal->randoItemId <= RI_STOP_N_SWOP_EGG_YELLOW) {
            actor->scale = 0.4f;
        }
    }

    actor->yaw += 5.0f;
}

void CustomCollectible_Update(Actor* actor) {
    Update(actor);
}

Actor* CustomCollectible::AttachCustomVariables(int32_t randoItemId, Actor* customCollectible) {
    ActorLocal_CustomCollectible* customLocal = (ActorLocal_CustomCollectible*)&customCollectible->local;
    customLocal->randoItemId = randoItemId;

    return customCollectible;
}

Actor* CustomCollectible::Spawn(int32_t position[3], RandoItemId randoItemId) {
    int32_t spawnPosition[3] = { position[0], position[1], position[2] };

    int32_t flags = ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_21;

    // Custom models exported for OoT are centered instead of offset to the marker, so they appear underground otherwise
    actor_e actorId = (actor_e)Rando::StaticData::Items.find(randoItemId)->second.actorId;
    auto drawInfo = customCollectibleDrawInfo.find(actorId);
    if (drawInfo->second.drawType == CCT_CUSTOM_MODEL) {
        position[1] += 50;
    }

    ActorInfo collectibleInfo = CustomCollectible::GetActorAndDrawInfo(randoItemId);

    Actor* customCollectible = actor_new(position, 0, &collectibleInfo, flags);
    if (Rando::StaticData::Items.find(randoItemId)->second.randoItemType == RITYPE_SNS_EGG) {
        customCollectible->actorTypeSpecificField = CustomCollectible::GetSNSEggColor(randoItemId);
    }
    customCollectible->marker->collisionFunc = CustomCollectible::OnCollect;
    customCollectible = CustomCollectible::AttachCustomVariables(randoItemId, customCollectible);

    return customCollectible;
}

uint32_t CustomCollectible::GetSNSEggColor(RandoItemId randoItemId) {
    switch (randoItemId) { 
        case RI_STOP_N_SWOP_EGG_BLUE:
            return (uint32_t)SNS_ITEM_EGG_BLUE;
        case RI_STOP_N_SWOP_EGG_CYAN:
            return (uint32_t)SNS_ITEM_EGG_CYAN;
        case RI_STOP_N_SWOP_EGG_GREEN:
            return (uint32_t)SNS_ITEM_EGG_GREEN;
        case RI_STOP_N_SWOP_EGG_PINK:
            return (uint32_t)SNS_ITEM_EGG_PINK;
        case RI_STOP_N_SWOP_EGG_RED:
            return (uint32_t)SNS_ITEM_EGG_RED;
        case RI_STOP_N_SWOP_EGG_YELLOW:
            return (uint32_t)SNS_ITEM_EGG_YELLOW;
        default:
            return (uint32_t)SNS_ITEM_EGG_CYAN;
    }
}

ActorInfo CustomCollectible::GetActorAndDrawInfo(RandoItemId randoItemId) {
    ActorInfo collectibleInfo = customActorInfo;

    actor_e actorId = (actor_e)Rando::StaticData::Items.find(randoItemId)->second.actorId;
    auto drawInfo = customCollectibleDrawInfo.find(actorId);

    collectibleInfo.modelId = drawInfo->second.drawModel;

    switch (drawInfo->second.drawType) { 
        case CCT_VANILLA_MODEL:
            collectibleInfo.draw_func = actor_draw;
            break;
        case CCT_VANILLA_SPRITE:
            collectibleInfo.draw_func = fxTouchSparkle_draw;
            break;
        case CCT_VANILLA_SNS_EGG:
            collectibleInfo.draw_func = func_802D41C4;
            break;
        case CCT_CUSTOM_MODEL:
            collectibleInfo.draw_func = CustomCollectible_DrawCustomModel;
            break;
        default:
            break;
    }

    return collectibleInfo;
}

void CustomCollectible::OnCollect(struct actorMarker_s* self, struct actorMarker_s* other) {
    marker_despawn(self);
}
