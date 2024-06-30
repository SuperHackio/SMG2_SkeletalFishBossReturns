#include "Game/Boss/SkeletalFishBossFunc.h"
#include "Game/Util.h"

namespace {
    static const char* sNamePosName = "�K�[�h�o���|�C���g";
};

s32 SkeletalFishBossFunc::getNearestGuardPosID(const TVec3f& rVec) {
    f32 closest = 100000.0;
    s32 posID = -1;

    for (int i = 0; i < 16; i++) {
        TVec3f pos;
        if (copyGuardPos(&pos, i)) {
            f32 dist = PSVECDistance((const Vec*)rVec, (const Vec*)pos);

            if (dist < closest) {
                closest = dist;
                posID = i;
            }
        }
    }

    return posID;
}

bool SkeletalFishBossFunc::copyGuardPos(TVec3f* pOut, s32 idx) {
    char buf[0x80];
    snprintf(buf, sizeof(buf), "%s%d", ::sNamePosName, idx);
    return MR::tryFindNamePos(buf, pOut, NULL);
}