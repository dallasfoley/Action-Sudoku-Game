/**
  * @file Number.cpp
  * @author Chirag Solanki
 */

#include "pch.h"
#include "Number.h"

void Number::moveToPosition(int x, int y)
{
    position = {x, y};
}

void Number::eatenBySparty()
{
    isInSpartyStomach = true;
    // Set position to undefined or a special value if required.
}

void Number::regurgitatedBySparty()
{
    isInSpartyStomach = false;
    // Update position or other attributes if required.
}

void Number::placeInContainer()
{
    isInContainer = true;
    // Update position or other attributes if required.
}

void Number::releaseFromContainer()
{
    isInContainer = false;
    // Update position or other attributes if required.
}