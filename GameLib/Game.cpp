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
#include "DeclarationSparty.h"
#include <sstream>
#include "DeclarationXray.h"
#include "DeclarationContainer.h"
#include "CheckIsContainerVisitor.h"
#include "CheckIsNumberVisitor.h"


using namespace std;


/**
 * Constructor
 */
Game::Game()
{
    mBoard = make_shared<Board>();
    Load(L"levels/level1.xml");
    if (mLevel == 1)
        mCount = 28;
    if (mLevel == 2)
        mCount = 34;
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
    if(height > mPixelHeight * mScale)
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
    for(auto item : mItems)
    {
        item->Draw(graphics);
    }

    mScoreboard.Draw(graphics);
    if(mDisplayFps)
        mFpsDisplay.Draw(graphics);
    if(mScoreboard.GetDuration() < 1.5)
        this->DrawMessage(graphics);
    if (mCount == 81)
    {
        wxFont font(wxSize(20, 70),
                    wxFONTFAMILY_SWISS,
                    wxFONTSTYLE_NORMAL,
                    wxFONTWEIGHT_BOLD);
        graphics->SetFont(font, wxColour(0, 250, 0));
        if(this->CheckSolved())
        {
            ostringstream os;
            os << "Level " << mLevel << " Complete!";
            double const currentTime = mScoreboard.GetDuration();
            if(mScoreboard.GetDuration() - 3 < currentTime)
                graphics->DrawText(os.str(), 225, 235);
            NextLevel();
        }
        else
        {
            double const currentTime = mScoreboard.GetDuration();
            if(mScoreboard.GetDuration() - 3 < currentTime)
                graphics->DrawText(L"Incorrect Solution Bozo!", 80, 235);
            Restart();
        }
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
        item->Update(elapsed);
    }
    if(mDisplayFps)
        mFpsDisplay.Update(elapsed);
    mScoreboard.Update(elapsed);
    mSolved = CheckSolved();
}

/**
 * Handles click event with respect to Sparty
 * @param event mouse event (click)
 */
void Game::OnLeftDown(wxMouseEvent &event)
{
    double oX = (event.GetX() - mXOffset) / mScale;
    double oY = (event.GetY() - mYOffset) / mScale;

    mItems.back()->SetLandingPoint(oX, oY);
}

/**
 * Handles key press event for Sparty
 * When space is pressed, Sparty eats a number
 * @param event key press event
 */
bool Game::OnKeyDown(wxKeyEvent &event)
{
    vector<int> digits = {0,1,2,3,4,5,6,7,8,9};
    if (event.GetKeyCode() == WXK_SPACE)
    {
        mItems.back()->Eat();
        for(auto item : mItems)
        {
            if(item == mItems.back())
            {
                continue;
            }

            if(item->HitTest((int)mItems.back()->GetX() + 40, (int)mItems.back()->GetY()) &&
               item != nullptr)
            {

                CheckIsNumberVisitor visitor;
                item->Accept(&visitor);
                auto loc = find(mItems.begin(), mItems.end(), item);
                if(visitor.IsNumber())
                {
                    mItems.erase(loc);
                }
                // mXRay->AddItem(item);
                int x = 10;
                return true;
            }
        }
    }
    if (event.GetKeyCode() == 'B' || event.GetKeyCode() == 'b')
    {
        mItems.back()->Headbutt();

        for(auto item : mItems)
        {
            if(item->HitTest((int)mItems.back()->GetX() + 40, (int)mItems.back()->GetY()) && item != nullptr)
            {
                CheckIsContainerVisitor visitor;
                item->Accept(&visitor);
                if(visitor.IsContainer())
                {
                    item->Release();
                }
            }
        }
        return true;

    }


    return false;
}

/**
* Test an x,y click location to see if it clicked
* on some item in the game.
* @param x X location in pixels
* @param y Y location in pixels
* @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Game::HitTest(double x, double y)
{
    for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
    {
        if ((*i)->HitTest(x - mXOffset/mScale, y - mYOffset/mScale))
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
    mDeclarations.clear();
    mItems.clear();
    mScoreboard.Reset();
}

/**
* Restarts a level
*/
void Game::Restart()
{
    this->Clear();
    if(mLevel == 1)
        Load(L"levels/level1.xml");
    if(mLevel == 2)
        Load(L"levels/level2.xml");
    if(mLevel == 3)
        Load(L"levels/level3.xml");
}

void Game::NextLevel()
{
    this->Clear();
    if(mLevel == 1)
    {
        Load(L"levels/level2.xml");
    }
    if(mLevel == 2)
        Load(L"levels/level3.xml");
    mLevel += 1;
}

/**
 * Checks if the given solution is correct
 * @returns boolean value of correct solution
 */
bool Game::CheckSolved()
{
    return mBoard->CheckSolution(this);
}

/**
* Handle a node of type item.
 * @param node XML node
*/
shared_ptr<Item> Game::XmlItem(wxXmlNode * node) {
    // if we are in the item part of the xml
    // then instantiate the items into the level list
    auto item = mDeclarations[node->GetAttribute(L"id")]->Create(node, this);
    return item;
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

    root->GetAttribute(L"tilewidth").ToDouble(&mTileWidth);
    root->GetAttribute(L"tileheight").ToDouble(&mTileHit);

    double width;
    double height;

    root->GetAttribute(L"width").ToDouble(&width);
    root->GetAttribute(L"height").ToDouble(&height);

    mPixelWidth = (int)(width * mTileWidth);
    mPixelHeight = (int)(height * mTileHit);

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
                if (superChildName == L"given" || superChildName == L"digit") {
                    mDeclarations.insert({superChild->GetAttribute(L"id"), make_shared<DeclarationNumber>(superChild)});
                } else if (superChildName == L"sparty") {
                    mDeclarations.insert({superChild->GetAttribute(L"id"), make_shared<DeclarationSparty>(superChild)});
                } else if (superChildName == L"background") {
                    mDeclarations.insert({superChild->GetAttribute(L"id"), make_shared<Declaration>(superChild)});
                } else if(superChildName == L"xray") {
                    mDeclarations.insert({superChild->GetAttribute(L"id"), make_shared<DeclarationXray>(superChild)});
                } else if(superChildName == L"container") {
                    mDeclarations.insert({superChild->GetAttribute(L"id"), make_shared<DeclarationContainer>(superChild)});
                }
            } else if (name == L"items") {
                mItems.push_back(XmlItem(superChild));
            }
            else if (name == L"game") {
                mBoard->XmlLoad(child);
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
    graphics->SetFont(font1, wxColour(0, 0, 0));
    ostringstream os1;
    os1 << "space: Eat \n 0-8: Regurgitate \n B: Headbutt";
    graphics->DrawText(os1.str(), 250, 350);
}

/**
 * Accept a visitor for the collection
 * @param visitor The visitor for the collection
 */
void Game::Accept(ItemVisitor* visitor)
{
    for (auto item : mItems)
    {
        item->Accept(visitor);
    }
}