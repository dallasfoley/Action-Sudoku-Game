/**
 * @file CheckIsContainerVisitor.cpp
 * @author Dallas Foley
 */

#include "CheckIsContainerVisitor.h"

/**
 * Sets the boolean value for is container to true
 */
void CheckIsContainerVisitor::VisitContainer(Container *container)
{
    mIsContainer = true;
}