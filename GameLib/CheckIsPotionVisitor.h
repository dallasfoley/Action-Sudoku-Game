/**
 * @file CheckIsPotionVisitor.h
 * @author Joseph Renas
 *
 * Visitor class to check if an item is a potion
 */

#ifndef PROJECT1_GAMELIB_CHECKISPOTIONVISITOR_H
#define PROJECT1_GAMELIB_CHECKISPOTIONVISITOR_H
#include "ItemVisitor.h"

/**
 * Visitor class to check if an item is a potion
 */
class CheckIsPotionVisitor : public ItemVisitor
{
private:
    virtual void VisitPotion(SpeedPotion *potion) override;

    /// Boolean value to determine if the item is a potion
    bool mIsPotion = false;

public:

    /**
     * Getter for mIsPotion
     * @return mIsPotion
     */
    bool IsPotion() { return mIsPotion; }
};

#endif //PROJECT1_GAMELIB_CHECKISPOTIONVISITOR_H
