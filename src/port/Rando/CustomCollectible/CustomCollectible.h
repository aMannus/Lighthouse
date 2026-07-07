#pragma once
#include "prop.h"
#include "port/Rando/Types.h"
#include <functional>

typedef struct {
    uint32_t randoItemId;
} ActorLocal_CustomCollectible;

typedef struct {
    asset_e drawModel;
    std::function<Actor*(ActorMarker* marker, Gfx** gdl, Mtx** mptr, Vtx** arg3)> drawFunction;
} CustomCollecticleDrawData;

void CustomCollectible_Update(Actor* actor);
Actor* CustomCollectible_Draw(ActorMarker* marker, Gfx** gdl, Mtx** mptr, Vtx** arg3);

class CustomCollectible {
private:
    static Actor* AttachLocalStruct(int32_t randoItemId, Actor* customCollectible);
    static void OnCollect(struct actorMarker_s* self, struct actorMarker_s* other);

public:
    static Actor* Spawn(int32_t position[3], RandoItemId randoItemId);
};
