/**
 * @file CheckIsPotionVisitor.cpp
 * @author Joseph Renas
 */

#include "pch.h"
#include "CheckIsPotionVisitor.h"

/**
 * Sets the boolean value for is container to true
 * @param potion the potion we are visiting
 */
void CheckIsPotionVisitor::VisitPotion(SpeedPotion *potion)
{
    mIsPotion = true;
}