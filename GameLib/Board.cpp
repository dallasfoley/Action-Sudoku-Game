/**
 * @file Board.cpp
 * @author rohch
 */

#include "pch.h"
#include "Board.h"
#include "Game.h"
#include "Item.h"

using namespace std;

/**
 * Load the number from xml file
 * @param node
 */
void Board::XmlLoad(wxXmlNode * node)
{
    node->GetAttribute(L"col").ToDouble(&mX);
    node->GetAttribute(L"row").ToDouble(&mY);
    mY++;
    auto tempList = node->GetNodeContent();

    for(auto c:tempList)
    {
        int i = int(c)-48;
        if(i == -16)
        {
            continue;
        }
        mSolution.push_back(i);
    }
}

bool Board::CheckSolution(Game * game)
{
    for(int i = 0; i < 81; i++)
    {
        auto item = game->HitTest(((double)(i%9) + mX) * game->GetTileWidth() + .5*game->GetTileWidth(), ((double)(i/9) + mY - .5) * game->GetTileHit() - .5*game->GetTileHit());
        if(item == nullptr || mSolution.at(i) != item->GetValue())
        {
            return false;
        }
    }
    return true;
}

