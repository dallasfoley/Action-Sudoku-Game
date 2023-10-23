/**
 * @file Game.cpp
 * @author Jon Price
 * @author Dallas Foley
 */

#include "pch.h"
#include "Game.h"
#include <memory>
#include "Sparty.h"
#include "Board.h"
#include "Number.h"
#include "XRay.h"
#include "Declaration.h"
#include "DeclarationNumber.h"
#include "FpsDisplay.h"
#include <sstream>
using namespace std;

const wstring BackgroundImage = L"images/background.png";

/**
 * Constructor
 */
Game::Game()
{
    mBackground = std::make_unique<wxBitmap>(
        BackgroundImage, wxBITMAP_TYPE_PNG);
    mSparty = make_shared<Sparty>(this);
    mXRay = make_shared<XRay>(this);
    Load(L"levels/level1.xml");
}

/**
 * Draw the game
 * @param graphics Graphics device to draw on
 * @param width Width of the window
 * @param height Height of the window
 */
void Game::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    // Draw the background image

    //
    // Automatic Scaling
    //
    auto scaleX = double(width) / double(mPixelWidth);
    auto scaleY = double(height) / double(mPixelHeight);
    mScale = std::min(scaleX, scaleY);

    mXOffset = (width - mPixelWidth * mScale) / 2.0;
    mYOffset = 0;
    if (height > mPixelHeight * mScale)
    {
        mYOffset = (double)((height - mPixelHeight * mScale) / 2.0);
    }

    graphics->PushState();

    graphics->Translate(mXOffset, mYOffset);
    graphics->Scale(mScale, mScale);

    //
    // Draw in virtual pixels on the graphics context
    //
    // INSERT YOUR DRAWING CODE HERE

    graphics->DrawBitmap(*mBackground, 0, 0, mPixelWidth, mPixelHeight);

    for (auto item: mItems)
    {
        item->Draw(graphics);
    }

    mScoreboard.Draw(graphics);
    if(mDisplayFps)
        mFpsDisplay.Draw(graphics);
    mSparty->Draw(graphics);
    mXRay->Draw(graphics);
    if (mScoreboard.GetDuration() < 3)
        this->DrawMessage(graphics);
    graphics->PopState();

}

/**
* Handle a node of type item.
 * @param node XML node
*/
void Game::XmlItem(wxXmlNode * node)
{
    /// A pointer for the item we are loading
    shared_ptr<Item> item;

    // We have an item. What type?
    auto type = node->GetAttribute(L"type");
    if (type == L"given")
    {
//        item = make_shared<>(this);
    }
    if (type == L"digit")
    {
//        item = make_shared<>(this);
    }
    if (type == L"background")
    {
//        item = make_shared<>(this);
    }
    if (type == L"sparty")
    {
//        item = make_shared<>(this);
    }
    if (type == L"xray")
    {
//        item = make_shared<>(this);
    }

    if (item != nullptr)
    {

        //Add(item); #needs to be implemented
        item->XmlLoad(node);
    }
}

/**
 * Handles updates for animation
 * @param elapsed time since the last update
 */
void Game::Update(double elapsed)
{
    for (auto item : mItems)
    {
        //item->Update(elapsed);
    }
    if(mDisplayFps)
        mFpsDisplay.Update(elapsed);
    mScoreboard.Update(elapsed);
    mSparty->Update(elapsed);

}

/**
 * Handles click event with respect to Sparty
 * @param event mouse event (click)
 */
void Game::OnLeftDown(wxMouseEvent &event)
{
    double oX = (event.GetX() - mXOffset) / mScale;
    double oY = (event.GetY() - mYOffset) / mScale;
    mSparty->SetLandingPoint(oX, oY);
}

/**
 * Handles key press event for Sparty
 * When space is pressed, Sparty eats a number
 * @param event key press event
 */
void Game::OnKeyDown(wxKeyEvent &event)
{
    if (event.GetKeyCode() == WXK_SPACE)
    {
        mSparty->Eat();
    }
}

/**
* Test an x,y click location to see if it clicked
* on some item in the game.
* @param x X location in pixels
* @param y Y location in pixels
* @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Game::HitTest(int x, int y)
{
    for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
    {
        if ((*i)->HitTest(x, y))
        {
            return *i;
        }
    }

    return nullptr;
}

/**
* Clears the game
*/
void Game::Clear()
{
    //mSparty.reset();
    mDeclarations.clear();
    mItems.clear();
}

/**
* Restarts a level
*/
void Game::Restart()
{
    this->Clear();
    mScoreboard.Reset();
}

/**
 * Checks if the given solution is correct
 * @returns boolean value of correct solution
 */
bool Game::CheckSolved()
{
    return false;
}

/**
 * Load the level from a XML file.
 *
 * Opens the XML file and reads the nodes, creating items as appropriate.
 *
 * @param filename The filename of the file to load the level from.
 */
void Game::Load(const wxString &filename)
{
    wxXmlDocument xmlDoc;
    if(!xmlDoc.Load(filename))
    {
        wxMessageBox(L"Unable to load level file");
        return;
    }

    Clear();

    // Get the XML document root node
    auto root = xmlDoc.GetRoot();

    double tileWid;
    double tileHit;

    root->GetAttribute(L"tilewidth").ToDouble(&tileWid);
    root->GetAttribute(L"tileheight").ToDouble(&tileHit);

    double width;
    double height;

    root->GetAttribute(L"width").ToDouble(&width);
    root->GetAttribute(L"height").ToDouble(&height);

    mPixelWidth = (int)(width * tileWid);
    mPixelHeight = (int)(height * tileHit);

    //
    // Traverse the children of the root
    // node of the XML document in memory!!!!
    //
    auto child = root->GetChildren();
    for( ; child; child=child->GetNext()) {
        auto name = child->GetName();
        auto superChild = child->GetChildren();
        // traverse the children of whatever
        // node of the XML document in memory.
        for (; superChild; superChild = superChild->GetNext()) {
            auto superChildName = superChild->GetName();
            superChild->GetAttribute(L"id");
            // if we are in the declarations part of the XML file
            // then add the declarations to the map
            if (name == L"declarations") {
                // I could definitely use a switch statement here if I knew how to use enum
                if (superChildName == L"given") {
                    mDeclarations.insert({superChild->GetAttribute(L"id"), make_shared<DeclarationNumber>(superChild)});
                } else if (superChildName == L"digit") {
                    mDeclarations.insert({superChild->GetAttribute(L"id"), make_shared<DeclarationNumber>(superChild)});
                }
            } else if (name == L"items") {
                // if we are in the item part of the xml
                // then instantiate the items into the level list
                if (superChildName == L"given" || superChildName == L"digit") {
                    double col;
                    superChild->GetAttribute(L"col").ToDouble(&col);
                    double row;
                    superChild->GetAttribute(L"row").ToDouble(&row);
                    auto dec = mDeclarations[superChild->GetAttribute(L"id")];
                    auto num = make_shared<Item>(dec, col * tileWid, row * tileHit);
                    mItems.push_back(num);
                }
            }
        }
    }
}
void Game::DrawMessage(std::shared_ptr<wxGraphicsContext> graphics)
{
//
    // Draw a filled rectangle
    //
    wxBrush rectBrush(*wxWHITE);
    graphics->SetBrush(rectBrush);
    graphics->SetPen(wxNullGraphicsPen);
    graphics->DrawRectangle(150, 225, 710, 300);
    wxFont font(wxSize(20, 70),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_BOLD);
    graphics->SetFont(font, wxColour(0, 250, 0));
    ostringstream os;
    os << "Level " << mLevel << " Begin";
    graphics->DrawText(os.str(), 250, 235);
    wxFont font1(wxSize(10, 40),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_BOLD);
    graphics->SetFont(font1, wxColour(200, 200, 200));
    ostringstream os1;
    os1 << "space: Eat \n 0-8: Regurgitate \n B: Headbutt";
    graphics->DrawText(os1.str(), 250, 350);
}