/**
 * @file Item.cpp
 * @author rohch
 * @author Jon Price
 */

#include "pch.h"
#include "Item.h"

using namespace std;

/**
 * Constructor for Item class
 * @param game context for this item
 * @param filename image filename
 */
Item::Item(Game * game, const std::wstring &filename) : mGame(game)
{
    mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}


/**
* Draw function for the item
 * @param graphics the graphics context we are drawing into
*/
void Item::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    double wid = mItemBitmap->GetWidth();
    double hit = mItemBitmap->GetHeight();
    graphics->DrawBitmap(*mItemBitmap,
                         (mX),
                         (mY),
                         wid,
                         hit);
}