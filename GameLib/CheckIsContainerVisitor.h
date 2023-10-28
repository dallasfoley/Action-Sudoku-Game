/**
 * @file CheckIsContainerVisitor.h
 * @author Dallas Foley
 *
 *
 */

#ifndef PROJECT1_PROJECT1_GAMELIB_CHECKISCONTAINERVISITOR_H
#define PROJECT1_PROJECT1_GAMELIB_CHECKISCONTAINERVISITOR_H
#include "ItemVisitor.h"

class CheckIsContainerVisitor : public ItemVisitor
{
private:
    virtual void VisitContainer(Container *container) override;
    bool mIsContainer = false;


public:

    bool IsContainer() { return mIsContainer; }
};

#endif //PROJECT1_PROJECT1_GAMELIB_CHECKISCONTAINERVISITOR_H
