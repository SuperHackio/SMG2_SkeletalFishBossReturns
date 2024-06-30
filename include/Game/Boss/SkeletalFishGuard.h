#pragma once

#include "Game/Enemy/AnimScaleController.h"
#include "Game/LiveActor/LiveActor.h"

#include "Game/Util/EffectUtil.h"

class SkeletalFishBoss;

class SkeletalFishGuard : public LiveActor {
public:
    SkeletalFishGuard(SkeletalFishBoss*, const char*);

    virtual ~SkeletalFishGuard();
    virtual void init(const JMapInfoIter&);
    virtual void initAfterPlacement();
    virtual void appear();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void attackSensor(HitSensor*, HitSensor*);
    virtual bool receiveMsgPlayerAttack(u32, HitSensor*, HitSensor*);

    void exeAppear();
    void exeNormal();
    void exeApart();
    void exeFollow();
    void exeStraight();
    void exeKill();
    void exeNumb();

    inline void exeOnEndNumb() {
        MR::deleteEffect(this, "PointerTouchManual");
        mScaleController->startAnim();
    }

    inline void exeWait();

    void appearNaturally();
    void appearForce();
    void killNaturally();
    void waitAttack(s32);
    void initSensor();
    void calcTransAndFront();
    void rotateHorizontal(const TVec3f&, f32);
    void rotateVertical(const TVec3f&, f32);
    bool tryShiftApart();
    bool tryShiftStraight();
    bool tryShiftKill();
    void turn(TVec3f*, const TVec3f&, const TVec3f&, f32);
    void lookToPlayer(f32, f32);
    void calcTarget(TVec3f*, TVec3f*, TVec3f*, s32);
    bool isInScreen() const;
    bool isPlayerInAttackRange() const;
    bool isLineOfSightClear() const;
    bool tryShiftNumb(const Nerve*);

    u32 _8C;
    SkeletalFishBoss* mFishBoss;                    // _90
    TVec3f _94;
    u32 _A0;
    TVec3f _A4;
    f32 _B0;
    f32 _B4;
    f32 _B8;
    f32 _BC;
    s32 mAttackDelay;                               // _C0
    f32 _C4;
    f32 _C8;
    const Nerve* _CC;
    TVec3f _D0;
    TVec3f _DC;
    TVec3f _E8;
    TVec3f _F4;
    TVec3f _100;
    TVec3f _10C;
    AnimScaleController* mScaleController;          // _118
};

namespace {
    NERVE(SkeletalFishGuardNrvWait);
    NERVE(SkeletalFishGuardNrvAppear);
    NERVE(SkeletalFishGuardNrvNormal);
    NERVE(SkeletalFishGuardNrvApart);
    NERVE(SkeletalFishGuardNrvFollow);
    NERVE(SkeletalFishGuardNrvStraight);
    NERVE(SkeletalFishGuardNrvDefence);
    NERVE(SkeletalFishGuardNrvKill);
    ENDABLE_NERVE(SkeletalFishGuardNrvNumb);
};