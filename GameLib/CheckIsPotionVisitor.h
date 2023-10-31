/**
 * @file CheckIsPotionVisitor.h
 * @author Joseph Renas
 *
 *
 */

#ifndef PROJECT1_GAMELIB_CHECKISPOTIONVISITOR_H
#define PROJECT1_GAMELIB_CHECKISPOTIONVISITOR_H
#include "ItemVisitor.h"

class CheckIsPotionVisitor : public ItemVisitor
{
private:
    virtual void VisitPotion(SpeedPotion *potion) override;
    bool mIsPotion = false;


public:

    bool IsPotion() { return mIsPotion; }
};

#endif //PROJECT1_GAMELIB_CHECKISPOTIONVISITOR_H
