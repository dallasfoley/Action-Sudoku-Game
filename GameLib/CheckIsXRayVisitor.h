/**
 * @file CheckIsXRayVisitor.h
 * @author dalla
 *
 *
 */

#ifndef PROJECT1_PROJECT1_GAMELIB_CHECKISXRAYVISITOR_H
#define PROJECT1_PROJECT1_GAMELIB_CHECKISXRAYVISITOR_H
#include "ItemVisitor.h"

class CheckIsXRayVisitor : public ItemVisitor
{
private:
    void VisitXRay(XRay *xray) override;
    bool mIsXray = false;

public:
    bool IsXRay() { return mIsXray; }
};

#endif //PROJECT1_PROJECT1_GAMELIB_CHECKISXRAYVISITOR_H
