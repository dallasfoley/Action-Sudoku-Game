/**
 * @file CheckIsContainerVisitor.h
 * @author Dallas Foley
 *
 * Visitor class to check if an item is a container
 */

#ifndef PROJECT1_PROJECT1_GAMELIB_CHECKISCONTAINERVISITOR_H
#define PROJECT1_PROJECT1_GAMELIB_CHECKISCONTAINERVISITOR_H
#include "ItemVisitor.h"

/**
 * Visitor class to check if an item is a container
 */
class CheckIsContainerVisitor : public ItemVisitor
{
private:
    virtual void VisitContainer(Container *container) override;

    /// Boolean value to determine if the item is a container
    bool mIsContainer = false;


public:

    /**
     * Getter for mIsContainer
     * @return mIsContainer
     */
    bool IsContainer() { return mIsContainer; }
};

#endif //PROJECT1_PROJECT1_GAMELIB_CHECKISCONTAINERVISITOR_H
