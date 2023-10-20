/**
 * @file Container.cpp
 * @author Dallas Foley
 */

#include "pch.h"
#include "Container.h"
using namespace std;

const wstring CauldronImageName = L"images/cauldron.png";
const wstring PumpkinImageName = L"images/pumpkin.png";

Container::Container(Game* game, const wstring &filename) : Item(game, filename), mGame(game)
{
    if (filename == CauldronImageName)
    {
        mIsCauldron = true;
    }
    else
        mIsCauldron = false;
}


void Container::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if (mGame->GetLevel() != 2)
        return;
    if (mIsCauldron)
    {
        SetLocation(320, 560);
        Item::Draw(graphics);
    }
    else
    {
        SetLocation(640, 560);
        Item::Draw(graphics);
    }
}