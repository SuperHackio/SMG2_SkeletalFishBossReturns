#pragma once

#include "Game/LiveActor/LiveActor.h"

class ModelObj;

class SubmarineVolcanoBigColumn : public LiveActor {
public:
    SubmarineVolcanoBigColumn(const char*);

    virtual ~SubmarineVolcanoBigColumn();
    virtual void init(const JMapInfoIter&);
    virtual void kill();
    virtual bool receiveMsgEnemyAttack(u32, HitSensor*, HitSensor*);

    void exeWait();
    void exeBreak();
    void pauseOff();
    void initBreakModel(const char*);

    ModelObj* mBreakModel;          // _8C
    bool mIsSmallColumn;            // _90
};

namespace NrvSubmarineVolcanoBigColumn {
    NERVE(SubmarineVolcanoBigColumnNrvWait);
    NERVE(SubmarineVolcanoBigColumnNrvBreak);
};