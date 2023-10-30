/**
 * @file CheckIsXRayVisitor.cpp
 * @author dalla
 */

#include "CheckIsXRayVisitor.h"

/**
 * Sets the boolean value for is xray to true
 */
void CheckIsXRayVisitor::VisitXRay(XRay *xray)
{
    mIsXray = true;
}
