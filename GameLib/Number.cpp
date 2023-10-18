/**
  * @file Number.cpp
  * @author Chirag Solanki
 */

#include "pch.h"
#include "Number.h"
#include <string>

//const std::string[9] images = {L"0r.png", L"1r.png", L"2r.png", L"3r.png", L"4r.png", L"5r.png", L"6r.png", L"7r.png", L"8r.png"};

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