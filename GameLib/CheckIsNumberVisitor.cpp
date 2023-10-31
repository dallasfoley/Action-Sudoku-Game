/**
 * @file CheckIsNumberVisitor.cpp
 * @author dalla
 */

#include "CheckIsNumberVisitor.h"
#include "Number.h"

/**
 * Sets the boolean value for is container to true
 */
void CheckIsNumberVisitor::VisitNumber(Number *number)
{
    if (!number->GetGiven())
        mIsNumber = true;
}
