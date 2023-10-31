/**
 * @file CheckIsPotionVisitor.cpp
 * @author Joseph Renas
 */

#include "CheckIsPotionVisitor.h"

/**
 * Sets the boolean value for is container to true
 */
void CheckIsPotionVisitor::VisitPotion(SpeedPotion *potion)
{
    mIsPotion = true;
}