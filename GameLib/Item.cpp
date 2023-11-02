/**
 * @file Item.cpp
 * @author rohch
 * @author Jon Price
 */

#include "pch.h"
#include "Game.h"
#include "Item.h"
#include "Declaration.h"

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
 * Constructor for loading context
 * @param declaration Information about the object
 * @param x location x
 * @param y location y
 */
Item::Item(shared_ptr<Declaration> declaration, double x, double y)
{
    mItemImage = make_unique<wxImage>(declaration->GetImage(), wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
    mX = x;
    mY = y;
}

/**
 * Constructor for loading context of an item
 * @param declaration
 * @param node
 */
Item::Item(Declaration * declaration, wxXmlNode * node)
{
    mItemImage = make_unique<wxImage>(declaration->GetImage(), wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
    // Gotta refactor mX and mY to be colomn and row values instead, then draw some other way? maybe.
    node->GetAttribute(L"col", L"0").ToDouble(&mX);
    node->GetAttribute(L"row", L"0").ToDouble(&mY);
    mY++;
    mX*=48;
    mY*=48;
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
                         (mY - hit),
                         wid,
                         hit);
}


/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool Item::HitTest(double x, double y)
{
    double wid = mItemBitmap->GetWidth();
    double hit = mItemBitmap->GetHeight();

    // Make x and y relative to the top-left corner of the bitmap image

    double testX = x - GetX();
    double testY = y - GetY() + hit;

    // if we are out of the image, return false
    return !(testX < 0 || testY < 0 || testX > wid || testY > hit);
}