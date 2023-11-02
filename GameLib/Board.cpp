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
    mSolution.clear();
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

/**
 * Checks if board matches solution
 * @param game class game
 * @returns Bool indicating correctness
 */
bool Board::CheckSolution(Game * game)
{
    for(int i = 0; i < 81; i++)
    {
        auto item = game->HitTest(((double)(i%9) + mX) * game->GetTileWidth() + .5*game->GetTileWidth(), ((double)(i/9) + mY) * game->GetTileHit() - .5*game->GetTileHit());
        if(item == nullptr || mSolution.at(i) != item->GetValue())
        {
            return false;
        }
    }
    return true;
}
/**
 * mSolution getter
 */
const vector<int> &Board::getMSolution() const
{
    return mSolution;
}
/**
 * mX getter
 */
double Board::getMx() const
{
    return mX;
}
/**
 * mY getter
 */
double Board::getMy() const
{
    return mY;
}

