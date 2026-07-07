#include "CustomCollectible.h"
#include "actor.h"
#include <unordered_map>

extern "C" {
Actor* actor_new(s32 position[3], s32 yaw, ActorInfo* actorInfo, u32 flags);
Actor* actor_draw(ActorMarker* marker, Gfx** gfx, Mtx** mtx, Vtx** vtx);
Actor* marker_getActor(ActorMarker* thisx);
void marker_despawn(ActorMarker* marker);
}

using DrawFunc = Actor* (*)(ActorMarker*, Gfx**, Mtx**, Vtx**);

std::unordered_map<RandoItemId, CustomCollecticleDrawData> customCollectibleDrawList = {
    { RI_EMPTY_HONEYCOMB_BUBBLEGLOOP_SWAMP, { ASSET_35F_MODEL_JIGGY, CustomCollectible_Draw } },
};

ActorInfo customActorInfo = { MARKER_300_CUSTOM_COLLECTIBLE,
                              ACTOR_3CD_CUSTOM_COLLECTIBLE,
                              ASSET_0_NONE,
                              1,
                              NULL,
                              NULL,
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
    }

    actor->yaw += 5.0f;
}

Actor* CustomCollectible_Draw(ActorMarker* marker, Gfx** gdl, Mtx** mptr, Vtx** arg3) {
    Actor* actor = marker_getActor(marker);
    actor = actor_draw(actor->marker, gdl, mptr, arg3);
    return actor;
}

Actor* CustomCollectible::AttachLocalStruct(int32_t randoItemId, Actor* customCollectible) {
    ActorLocal_CustomCollectible* customLocal = (ActorLocal_CustomCollectible*)&customCollectible->local;

    customLocal->randoItemId = randoItemId;

    return customCollectible;
}

Actor* CustomCollectible::Spawn(int32_t position[3], RandoItemId randoItemId) {
    int32_t spawnPosition[3] = { position[0], position[1], position[2] };

    int32_t flags = ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_21;

    auto drawData = customCollectibleDrawList.find(randoItemId);
    ActorInfo collectibleInfo = customActorInfo;
    collectibleInfo.modelId = drawData->second.drawModel;
    collectibleInfo.draw_func = drawData->second.drawFunction;

    Actor* customCollectible = actor_new(position, 0, &customActorInfo, flags);
    customCollectible->marker->collisionFunc = CustomCollectible::OnCollect;
    customCollectible = CustomCollectible::AttachLocalStruct(randoItemId, customCollectible);

    return customCollectible;
}

void CustomCollectible::OnCollect(struct actorMarker_s* self, struct actorMarker_s* other) {
    marker_despawn(self);
}
