/**
 * @file CheckIsNumberVisitor.cpp
 * @author dalla
 */

#include "CheckIsNumberVisitor.h"

/**
 * Sets the boolean value for is container to true
 */
void CheckIsNumberVisitor::VisitNumber(Number *number)
{
    mIsNumber = true;
}
