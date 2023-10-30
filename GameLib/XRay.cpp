/**
 * @file XRay.cpp
 * @author Jon Price
 */


#include "pch.h"
#include "XRay.h"
#include "Item.h"

using namespace std;

const wstring xRayImage = L"images/xray.png";

/**
 * Constructor for XRay
 * @param declaration The declaration for the XRay
 * @param node The node for the XRay
 * @param mGame The game the XRay is in
 */
XRay::XRay(DeclarationXray *declaration, wxXmlNode *node, Game *mGame) : Item(declaration, node)
{
    mImage = make_unique<wxImage>(xRayImage, wxBITMAP_TYPE_ANY);
    mBitmap = make_unique<wxBitmap>(*mImage);
    auto child = node->GetChildren();
    for (; child; child = child->GetNext())
    {
        auto i = mGame->XmlItem(child);
        mNumbers.push_back(i);
    }
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
    Item::Draw(graphics);
    double wid = mBitmap->GetWidth();
    double hit = mBitmap->GetHeight();
    graphics->DrawBitmap(*mBitmap,
                         (mX),
                         (mY),
                         wid,
                         hit);
    int count = 0;
    for (auto number : mNumbers)
    {
        number->SetLocation(GetX() + 16 * count, GetY() - 16 * count);
        number->Draw(graphics);
        count++;
    }
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
void XRay::AddItem(std::shared_ptr<Item> item)
{
    if (GetNumItems() < 7)
    {
        mNumbers.push_back(item);
        DisplayNumbers();
        //return true;
    }
    //return false;
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
    double referenceX = mX + 10;
    double referenceY = mY + 20;

    for (int i = 0; i < mNumbers.size(); i++)
    {
        if (i % 3 == 0)
        {
            referenceX = mX + 10;
            referenceY += 35;
        }
        // Place items in a grid pattern
        mNumbers[i]->SetLocation(referenceX, referenceY);
        referenceX += 35;
    }
}

/**
 * Returns the number of items in the XRay
 * @return the number of items in the XRay
 */
int XRay::GetNumItems(){
    return (int)mNumbers.size();
}

/**
 * Clears the XRay
 *
 */
void XRay::Clear()
{
    mNumbers.clear();
}