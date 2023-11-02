/**
 * @file CheckIsXRayVisitor.h
 * @author dalla
 *
 * Visitor class to check if an item is an xray
 */

#ifndef PROJECT1_PROJECT1_GAMELIB_CHECKISXRAYVISITOR_H
#define PROJECT1_PROJECT1_GAMELIB_CHECKISXRAYVISITOR_H
#include "ItemVisitor.h"

/**
 * Visitor class to check if an item is an xray
 */
class CheckIsXRayVisitor : public ItemVisitor
{
private:
    void VisitXRay(XRay *xray) override;

    /// Boolean value to determine if the item is an xray
    bool mIsXray = false;

public:

    /**
     * Getter for mIsXray
     * @return mIsXray
     */
    bool IsXRay() { return mIsXray; }
};

#endif //PROJECT1_PROJECT1_GAMELIB_CHECKISXRAYVISITOR_H
