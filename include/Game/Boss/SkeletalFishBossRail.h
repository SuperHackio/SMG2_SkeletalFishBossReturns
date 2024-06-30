#pragma once

#include "Game/LiveActor/LiveActor.h"

class SkeletalFishBossRail : public LiveActor {
public:
    SkeletalFishBossRail(const char*);

    virtual ~SkeletalFishBossRail();
    virtual void init(const JMapInfoIter&);
    virtual void initAfterPlacement();

    bool isFillUpPoint(s32) const;
    s32 getFillUpNamePos(s32) const;
    void createFillUpFlag();
    void createFillUpNamePosID();
    void linkFillUpNamePosID();

    s32 _8C;
    bool* mFillUpFlags;          // _90
    s32* mNamePosIDs;           // _94
    f32 _98;
};