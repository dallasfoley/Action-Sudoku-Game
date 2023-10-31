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
    mCapacity = declaration->GetCapacity();
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
    double referenceX = GetX() + 10;
    double referenceY = GetY() + 20;
    for (int i = 0; i < mNumbers.size(); i++)
    {
        if (i % 3 == 0)
        {
            referenceX = GetX() + 10;
            referenceY -= 35;
        }
        // Place items in a grid pattern
        mNumbers[i]->SetLocation(referenceX, referenceY);
        mNumbers[i]->Draw(graphics);
        referenceX += 35;
    }
}


/**
 * Add an item to the XRay
 * @param item The item to add
 * @return true if the item is added
 */
void XRay::AddItem(std::shared_ptr<Item> item)
{
    mNumbers.push_back(item);
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

/**
* Regurgitate item back to the game
*/
void XRay::Regurgitate(Game * game, wxKeyEvent & event, double x, double y, std::shared_ptr<Board> board)
{
    x+=game->GetTileWidth();
    auto code = event.GetKeyCode();
    code -= 48;
    for(auto item : mNumbers)
    {
        if(item->GetValue() == code)
        {
            //Determine if Sparty is on the Board
            if(!(x < board->GetX() * game->GetTileWidth() || x > (board->GetX() + 9) * game->GetTileWidth() || y < board->GetY() * game->GetTileHit() || y > (board->GetY() + 9) * game->GetTileHit())) {

                // Set x and y to whole tile number
                x/= game->GetTileWidth();
                x = (int)x;
                x*= game->GetTileWidth();

                y/= game->GetTileWidth();
                y = (int)y;
                y*= game->GetTileWidth();

//                auto item2 = game->HitTest(x, y);
//                if(item2->GetValue() < 9)
//                    return;
            }
            item->SetLocation(x, y);
            game->AddItem(item);
            RemoveItem(item);
            return;
        }
    }
}