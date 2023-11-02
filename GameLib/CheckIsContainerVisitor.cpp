/**
 * @file CheckIsContainerVisitor.cpp
 * @author Dallas Foley
 */

#include "pch.h"
#include "CheckIsContainerVisitor.h"

/**
 * Sets the boolean value for is container to true
 * @param container the container we are visiting
 */
void CheckIsContainerVisitor::VisitContainer(Container *container)
{
    mIsContainer = true;
}