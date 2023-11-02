/**
 * @file CheckIsXRayVisitor.cpp
 * @author dalla
 */

#include "pch.h"
#include "CheckIsXRayVisitor.h"

/**
 * Sets the boolean value for is xray to true
 * @param xray the xray we are visiting
 */
void CheckIsXRayVisitor::VisitXRay(XRay *xray)
{
    mIsXray = true;
}
