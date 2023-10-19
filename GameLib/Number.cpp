/**
  * @file Number.cpp
  * @author Chirag Solanki
  * @author Jon Price
 */

#include "pch.h"
#include "Number.h"

using namespace std;

// Array of potential numbers.
const wstring RedImages[] = {L"images/0r.png", L"images/1r.png", L"images/2r.png", L"images/3r.png", L"images/4r.png", L"images/5r.png", L"images/6r.png", L"images/7r.png", L"images/8r.png"};
const wstring BlueImages[] = {L"images/0b.png", L"images/1b.png", L"images/2b.png", L"images/3b.png", L"images/4b.png", L"images/5b.png", L"images/6b.png", L"images/7b.png", L"images/8b.png"};
void Number::MoveToPosition(int x, int y)
{
    mPosition = {x, y};
}



//  given? BlueImages[num] : RedImages[num]
/**
 * Constructor
 * @param num value of this Number
 */
Number::Number(Game * game, int num, bool given)  : Item(game, given? BlueImages[num] : RedImages[num])
{
    mValue = num;
    mIsGiven = given;
    mIsInContainer = false;

}

void Number::EatenBySparty()
{
    mIsInSpartyStomach = true;
    // Set mPosition to undefined or a special mValue if required.
}

void Number::RegurgitatedBySparty()
{
    mIsInSpartyStomach = false;
    // Update mPosition or other attributes if required.
}

void Number::PlaceInContainer()
{
    mIsInContainer = true;
    // Update mPosition or other attributes if required.
}

void Number::ReleaseFromContainer()
{
    mIsInContainer = false;
    // Update mPosition or other attributes if required.
}