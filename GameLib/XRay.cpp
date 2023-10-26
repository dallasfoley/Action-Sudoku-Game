/**
 * @file XRay.cpp
 * @author Jon Price
 */


#include "pch.h"
#include "XRay.h"

using namespace std;

const wstring xRayImage = L"images/xray.png";

/**
 * Constructor for XRay
 * @param game
 */
XRay::XRay(Game *game)
{
    mGame=game;
    mImage = make_unique<wxImage>(xRayImage, wxBITMAP_TYPE_ANY);
    mBitmap = make_unique<wxBitmap>(*mImage);
}

/**
 * Destructor for XRay
 */
XRay::~XRay()
{
}

/**
 * Draw the XRay
 * @param graphics The graphics context to draw on
 */
void XRay::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    double wid = mBitmap->GetWidth();
    double hit = mBitmap->GetHeight();
    graphics->DrawBitmap(*mBitmap,
                         (mX),
                         (mY),
                         wid,
                         hit);
}

/**
 * Update the XRay
 * @param elapsed The time since the last update
 *
 */
void XRay::Update(double elapsed)
{
    // to be implemented
}

/**
 * Add an item to the XRay
 * @param item The item to add
 * @return true if the item is added
 */
bool XRay::AddItem(std::shared_ptr<Item> item)
{
    if (GetNumItems() < 7) {
        mNumbers.push_back(item);
        return true;
    }
    return false;
}

/**
 * Remove an item from the XRay
 * @param item The item to remove
 * @return true if the item is removed
 */
bool XRay::RemoveItem(std::shared_ptr<Item> item)
{
    for (int i = 0; i < mNumbers.size(); i++)
    {
        if (mNumbers[i] == item)
        {
            mNumbers.erase(mNumbers.begin() + i);
            return true;
        }
    }
    return false;
}

/**
 * Displays the numbers in the XRay on the screen in a grid pattern
 */
void XRay::DisplayNumbers(){
    double referenceX = mX - 10;
    double referenceY = mY - 20;

    for (int i = 0; i < mNumbers.size() - 1; i++)
    {
        if (i % 3 == 0)
        {
            referenceX = mX - 10;
            referenceY += 20;
        }
        // Place items in a grid pattern
        mNumbers[i]->SetLocation(referenceX, referenceY);
        referenceX += 20;
    }
}

/**
 * Returns the number of items in the XRay
 * @return the number of items in the XRay
 */
int XRay::GetNumItems(){
    return (int)mNumbers.size();
}