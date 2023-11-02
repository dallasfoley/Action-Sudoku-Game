/**
 * @file CheckIsNumberVisitor.h
 * @author dalla
 *
 * Visitor class to check if an item is a number
 */

#ifndef PROJECT1_PROJECT1_GAMELIB_CHECKISNUMBERVISITOR_H
#define PROJECT1_PROJECT1_GAMELIB_CHECKISNUMBERVISITOR_H
#include "ItemVisitor.h"

/**
 * Visitor class to check if an item is a number
 */
class CheckIsNumberVisitor : public ItemVisitor
{
private:
    virtual void VisitNumber(Number *number) override;

    /// Boolean value to determine if the item is a number
    bool mIsNumber = false;
public:

    /**
     * Getter for mIsNumber
     * @return mIsNumber
     */
    bool IsNumber() { return mIsNumber; }
};

#endif //PROJECT1_PROJECT1_GAMELIB_CHECKISNUMBERVISITOR_H
