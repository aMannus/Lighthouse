#pragma once
#include "prop.h"
#include "port/Rando/Types.h"

typedef struct {
    uint16_t randoItemId;
} ActorLocal_CustomCollectible;

enum CustomCollectibleDrawTypes { CCT_VANILLA_MODEL, CCT_VANILLA_SPRITE, CCT_VANILLA_SNS_EGG, CCT_CUSTOM_MODEL };

typedef struct {
    asset_e drawModel;
    CustomCollectibleDrawTypes drawType;
} CustomCollectibleDrawInfo;

void CustomCollectible_Update(Actor* actor);

class CustomCollectible {
private:
    static Actor* AttachCustomVariables(int32_t randoItemId, Actor* customCollectible);
    static void OnCollect(struct actorMarker_s* self, struct actorMarker_s* other);
    static ActorInfo GetActorAndDrawInfo(RandoItemId randoItemId);
    static uint32_t GetSNSEggColor(RandoItemId randoItemId);

public:
    static Actor* Spawn(int32_t position[3], RandoItemId randoItemId);
};
