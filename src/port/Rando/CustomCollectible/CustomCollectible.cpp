#include "CustomCollectible.h"
#include "actor.h"
#include <unordered_map>

extern "C" {
Actor* actor_new(s32 position[3], s32 yaw, ActorInfo* actorInfo, u32 flags);
Actor* actor_draw(ActorMarker* marker, Gfx** gfx, Mtx** mtx, Vtx** vtx);
Actor* fxTouchSparkle_draw(ActorMarker* marker, Gfx** gfx, Mtx** mtx, Vtx** vtx);
Actor* marker_getActor(ActorMarker* thisx);
void marker_despawn(ActorMarker* marker);
}

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

void CustomCollectible_Update(Actor* actor) {
    ActorLocal_CustomCollectible* customLocal = (ActorLocal_CustomCollectible*)&actor->local;

    if (!actor->initialized) {
        actor->initialized = true;
        actor->marker->collidable = true;

        if (customLocal->randoItemId >= RI_MUSIC_NOTE_BUBBLEGLOOP_SWAMP &&
            customLocal->randoItemId <= RI_MUSIC_NOTE_TREASURE_TROVE_COVE) {
            actor->scale = 0.42857143f;
        }
    }

    actor->yaw += 5.0f;
}

Actor* CustomCollectible_DrawCustom(ActorMarker* marker, Gfx** gdl, Mtx** mptr, Vtx** vtx) {
    Actor* actor = marker_getActor(marker);
    actor = actor_draw(actor->marker, gdl, mptr, vtx);

    return actor;
}

Actor* CustomCollectible::AttachCustomVariables(int32_t randoItemId, Actor* customCollectible) {
    ActorLocal_CustomCollectible* customLocal = (ActorLocal_CustomCollectible*)&customCollectible->local;
    customLocal->randoItemId = randoItemId;

    return customCollectible;
}

Actor* CustomCollectible::Spawn(int32_t position[3], RandoItemId randoItemId) {
    int32_t spawnPosition[3] = { position[0], position[1], position[2] };

    int32_t flags = ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_21;

    ActorInfo collectibleInfo = CustomCollectible::GetActorAndDrawInfo(randoItemId);

    Actor* customCollectible = actor_new(position, 0, &collectibleInfo, flags);
    customCollectible->marker->collisionFunc = CustomCollectible::OnCollect;
    customCollectible = CustomCollectible::AttachCustomVariables(randoItemId, customCollectible);

    return customCollectible;
}

ActorInfo CustomCollectible::GetActorAndDrawInfo(RandoItemId randoItemId) {
    ActorInfo collectibleInfo = customActorInfo;

    // Empty Honeycomb
    if (randoItemId >= RI_EMPTY_HONEYCOMB_BUBBLEGLOOP_SWAMP && randoItemId <= RI_EMPTY_HONEYCOMB_TREASURE_TROVE_COVE) {
        collectibleInfo.modelId = ASSET_363_MODEL_HONEYCOMB;
        collectibleInfo.draw_func = actor_draw;
    }

    // Jiggy
    else if (randoItemId >= RI_JIGGY_BUBBLEGLOOP_SWAMP && randoItemId <= RI_JIGGY_TREASURE_TROVE_COVE) {
        collectibleInfo.modelId = ASSET_35F_MODEL_JIGGY;
        collectibleInfo.draw_func = actor_draw;
    }

    // Jinjo (Blue)
    else if (randoItemId >= RI_JINJO_BLUE_BUBBLEGLOOP_SWAMP && randoItemId <= RI_JINJO_BLUE_TREASURE_TROVE_COVE) {
        collectibleInfo.modelId = ASSET_3C0_MODEL_JINJO_BLUE;
        collectibleInfo.draw_func = actor_draw;
    }

    // Jinjo (Green)
    else if (randoItemId >= RI_JINJO_GREEN_BUBBLEGLOOP_SWAMP && randoItemId <= RI_JINJO_GREEN_TREASURE_TROVE_COVE) {
        collectibleInfo.modelId = ASSET_3C2_MODEL_JINJO_GREEN;
        collectibleInfo.draw_func = actor_draw;
    }

    // Jinjo (Orange)
    else if (randoItemId >= RI_JINJO_ORANGE_BUBBLEGLOOP_SWAMP && randoItemId <= RI_JINJO_ORANGE_TREASURE_TROVE_COVE) {
        collectibleInfo.modelId = ASSET_3BC_MODEL_JINJO_ORANGE;
        collectibleInfo.draw_func = actor_draw;
    }

    // Jinjo (Pink)
    else if (randoItemId >= RI_JINJO_PINK_BUBBLEGLOOP_SWAMP && randoItemId <= RI_JINJO_PINK_TREASURE_TROVE_COVE) {
        collectibleInfo.modelId = ASSET_3C1_MODEL_JINJO_PINK;
        collectibleInfo.draw_func = actor_draw;
    }

    // Jinjo (Yellow)
    else if (randoItemId >= RI_JINJO_YELLOW_BUBBLEGLOOP_SWAMP && randoItemId <= RI_JINJO_YELLOW_TREASURE_TROVE_COVE) {
        collectibleInfo.modelId = ASSET_3BB_MODEL_JINJO_YELLOW;
        collectibleInfo.draw_func = actor_draw;
    }

    // Molehill
    else if (randoItemId >= RI_MOLEHILL_BARGE && randoItemId <= RI_MOLEHILL_WONDERWING) {
        collectibleInfo.modelId = ASSET_388_MODEL_MOLEHILL;
        collectibleInfo.draw_func = actor_draw;
    }

    // Mumbo Token
    else if (randoItemId >= RI_MUMBO_TOKEN_BUBBLEGLOOP_SWAMP && randoItemId <= RI_MUMBO_TOKEN_TREASURE_TROVE_COVE) {
        collectibleInfo.modelId = ASSET_41A_SPRITE_MUMBO_TOKEN;
        collectibleInfo.draw_func = fxTouchSparkle_draw;
    }

    // Music Note
    else if (randoItemId >= RI_MUSIC_NOTE_BUBBLEGLOOP_SWAMP && randoItemId <= RI_MUSIC_NOTE_TREASURE_TROVE_COVE) {
        collectibleInfo.modelId = ASSET_6D6_SPRITE_MUSIC_NOTE;
        collectibleInfo.draw_func = fxTouchSparkle_draw;
    }

    // StopNSwop Egg (Blue)
    else if (randoItemId == RI_STOP_N_SWOP_EGG_BLUE) {
        collectibleInfo.modelId = ASSET_36D_SPRITE_BLUE_EGG;
        collectibleInfo.draw_func = fxTouchSparkle_draw;
    }

    // StopNSwop Egg (Cyan)
    else if (randoItemId == RI_STOP_N_SWOP_EGG_CYAN) {
        collectibleInfo.modelId = ASSET_36D_SPRITE_BLUE_EGG;
        collectibleInfo.draw_func = fxTouchSparkle_draw;
    }

    // StopNSwop Egg (Green)
    else if (randoItemId == RI_STOP_N_SWOP_EGG_GREEN) {
        collectibleInfo.modelId = ASSET_36D_SPRITE_BLUE_EGG;
        collectibleInfo.draw_func = fxTouchSparkle_draw;
    }

    // StopNSwop Egg (Pink)
    else if (randoItemId == RI_STOP_N_SWOP_EGG_PINK) {
        collectibleInfo.modelId = ASSET_36D_SPRITE_BLUE_EGG;
        collectibleInfo.draw_func = fxTouchSparkle_draw;
    }

    // StopNSwop Egg (Red)
    else if (randoItemId == RI_STOP_N_SWOP_EGG_RED) {
        collectibleInfo.modelId = ASSET_36D_SPRITE_BLUE_EGG;
        collectibleInfo.draw_func = fxTouchSparkle_draw;
    }

    // StopNSwop Egg (Yellow)
    else if (randoItemId == RI_STOP_N_SWOP_EGG_YELLOW) {
        collectibleInfo.modelId = ASSET_36D_SPRITE_BLUE_EGG;
        collectibleInfo.draw_func = fxTouchSparkle_draw;
    }

    // StopNSwop Ice Key
    else if (randoItemId == RI_STOP_N_SWOP_ICE_KEY) {
        collectibleInfo.modelId = ASSET_36D_SPRITE_BLUE_EGG;
        collectibleInfo.draw_func = fxTouchSparkle_draw;
    }

    return collectibleInfo;
}

void CustomCollectible::OnCollect(struct actorMarker_s* self, struct actorMarker_s* other) {
    marker_despawn(self);
}
