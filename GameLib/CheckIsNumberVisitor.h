/**
 * @file CheckIsNumberVisitor.h
 * @author dalla
 *
 *
 */

#ifndef PROJECT1_PROJECT1_GAMELIB_CHECKISNUMBERVISITOR_H
#define PROJECT1_PROJECT1_GAMELIB_CHECKISNUMBERVISITOR_H
#include "ItemVisitor.h"

class CheckIsNumberVisitor : public ItemVisitor
{
private:
    virtual void VisitNumber(Number *number) override;
    bool mIsNumber = false;
public:
    bool IsNumber() { return mIsNumber; }
};

#endif //PROJECT1_PROJECT1_GAMELIB_CHECKISNUMBERVISITOR_H
