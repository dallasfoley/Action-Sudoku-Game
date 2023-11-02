/**
 * @file CheckIsNumberVisitor.cpp
 * @author dalla
 */

#include "pch.h"
#include "CheckIsNumberVisitor.h"
#include "Number.h"

/**
 * Sets the boolean value for is container to true
 * @param number the number we are visiting
 */
void CheckIsNumberVisitor::VisitNumber(Number *number)
{
    if (!number->GetGiven())
        mIsNumber = true;
}
