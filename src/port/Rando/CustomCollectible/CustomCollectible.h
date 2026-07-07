#pragma once
extern "C" {
#include "functions.h"
}

typedef struct {
    u32 randoItemId = 0;
} ActorLocal_CustomCollectible;

class CustomCollectible {
private:
    Actor* AttachLocalStruct(int32_t randoItemId, Actor* customCollectible);
    Actor* Spawn(int32_t position[3], int32_t flags);
    static void OnCollect(struct actorMarker_s* self, struct actorMarker_s* other);
};
