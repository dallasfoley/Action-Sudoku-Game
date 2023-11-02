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
#include "DeclarationPotion.h"
#include "CheckIsContainerVisitor.h"
#include "CheckIsNumberVisitor.h"
#include "CheckIsXRayVisitor.h"
#include "SpeedPotion.h"
#include "CheckIsPotionVisitor.h"


using namespace std;


/**
 * Constructor
 */
Game::Game()
{
    // seed random number generator
    random_device rd;
    mRandom.seed(rd());

    mBoard = make_shared<Board>();
    Load(L"levels/level1.xml");
    mCount = 28;
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
    if (mType == Type::Start)
    {
        this->DrawMessage(graphics);
    }
    else if (mType == Type::Correct)
    {
        wxFont font(wxSize(20, 70),
                    wxFONTFAMILY_SWISS,
                    wxFONTSTYLE_NORMAL,
                    wxFONTWEIGHT_BOLD);
        graphics->SetFont(font, wxColour(0, 250, 0));
        ostringstream os;
        os << "Level " << mLevel << " Complete!";
        graphics->DrawText(os.str(), 225, 235);
    }
    else if (mType == Type::Full)
    {
        this->DrawImFull(graphics);
    }
    else if (mType == Type::Incorrect)
    {
        wxFont font(wxSize(20, 70),
                    wxFONTFAMILY_SWISS,
                    wxFONTSTYLE_NORMAL,
                    wxFONTWEIGHT_BOLD);
        graphics->SetFont(font, wxColour(0, 250, 0));

            graphics->DrawText(L"Incorrect Solution Bozo!", 80, 235);
    }
}

/**
 * Handles updates for animation
 * @param elapsed time since the last update
 */
void Game::Update(double elapsed)
{
    CheckSolved();
    for (auto item : mItems)
    {
        item->Update(elapsed);
    }
    if(mDisplayFps)
        mFpsDisplay.Update(elapsed);
    if (mType == Type::Start)
    {
        if (mGameTimer > 3)
        {
            mType = Type::Playing;
        }
    }
    else if (mType == Type::Playing)
    {
        mScoreboard.Update(elapsed);
        if (mCount == 81 && !(this->CheckSolved()))
        {
            mType = Type::Incorrect;
        }
        if (mCount == 81 && (this->CheckSolved()))
        {
            mType = Type::Correct;
        }
    }
    else if (mType == Type::Correct)
    {
        if (mGameTimer - mScoreboard.GetDuration() > 6)
            NextLevel();
    }
    else if (mType == Type::Incorrect)
    {
        if (mGameTimer - mScoreboard.GetDuration() > 6)
            Restart();
    }
    else if (mType == Type::Full)
    {
        mScoreboard.Update(elapsed);
        mMessageAmount += 250 * elapsed;
        if (mMessageAmount >= mPixelHeight + 50)
        {
            mMessageAmount = 0;
            mType = Type::Playing;
        }
    }
    mGameTimer += elapsed;
}

/**
 * Handlles mouse click event for Sparty
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
 * When B is pressed, Sparty headbutts a container
 * When 0-8 is pressed, Sparty regurgitates a number of that value
 * @param event key press event
 */
void Game::OnKeyDown(wxKeyEvent &event)
{
    // eat
    if (event.GetKeyCode() == WXK_SPACE)
    {
        mItems.back()->Eat();

        auto item = HitTest(mItems.back()->GetX(), mItems.back()->GetY());

        if(item == nullptr)
            return;
        CheckIsNumberVisitor numberVisitor;
        CheckIsXRayVisitor xrayVisitor;
        CheckIsPotionVisitor potionVisitor;
        item->Accept(&numberVisitor);
        item->Accept(&potionVisitor);
        auto xray = mItems.begin();
        for(;xray != mItems.end(); xray++) {
            (*xray)->Accept(&xrayVisitor);
            if(xrayVisitor.IsXRay())
                break;
        }
        if(!(*xray)->HasCapacity()) {
            mType = Type::Full;
            return;
        }
        auto loc = find(mItems.begin(), mItems.end(), item);
        if(numberVisitor.IsNumber())
        {
            if(mBoard->IsOnBoard(item->GetX(), item->GetY(), this))
            {
                mCount--;
            }
            (*xray)->AddItem(item);
            mItems.erase(find(mItems.begin(), mItems.end(), item));
        } else if(potionVisitor.IsPotion())
        {
            item->AffectSparty();
            mItems.erase(find(mItems.begin(), mItems.end(), item));
        }
        // Headbutt on B press
    } else if (event.GetKeyCode() == 'B' || event.GetKeyCode() == 'b') {

        mItems.back()->Headbutt();
        auto item = HitTest((int)mItems.back()->GetX(), (int)mItems.back()->GetY());

        // if there is no item at the location, return
        if(item == nullptr)
            return;

        CheckIsContainerVisitor containerVisitor;
        item->Accept(&containerVisitor);
        if(containerVisitor.IsContainer())
        {
            item->Release(this);
        }

        // otherwise regurgitate the key hit. essentially
    }
    for (int i = 0; i < 10; i++)
    {
        if (i == event.GetKeyCode() - '0')
        {
            CheckIsXRayVisitor xRayVisitor;
            for (auto item2: mItems)
            {
                item2->Accept(&xRayVisitor);
                if (xRayVisitor.IsXRay() && item2->Regurgitate(this, event, mItems.back()->GetX(), mItems.back()->GetY(), mBoard))
                {
                    mItems.back()->DecrementCount();
                    mItems.back()->Eat();
                }
            }
        }
    }
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
        if ((*i)->HitTest(x,y))
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
    mGameTimer = 0;
}

/// Level 1 givens count;
int Level1Givens0 = 28;
/// Level 2 givens count;
int Level2Givens0 = 34;
/// Level 3 givens count;
int Level3Givens0 = 46;


/**
* Restarts a level
*/
void Game::Restart()
{
    mType = Type::Start;
    this->Clear();

    if(mLevel == 1)
    {
        mCount = Level1Givens0;
        Load(L"levels/level1.xml");
    }
    if(mLevel == 2)
    {
        mCount = Level2Givens0;
        Load(L"levels/level2.xml");
    }
    if(mLevel == 3)
    {
        mCount = Level3Givens0;
        Load(L"levels/level3.xml");
    }

}

/**
 * Moves to the next level
 */
void Game::NextLevel()
{
    if (mLevel != 3)
        mLevel += 1;
    Restart();
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
 * Solves the current level by placing the numbers in the correct location
 */
void Game::Solve()
{
    for(int i = 0; i < 81; i++)
    {
        double tempX = mBoard->getMx();
        double tempY = mBoard->getMy();
        auto hitItem = HitTest(((double)(i%9) + tempX) * mTileWidth + .5*mTileWidth, ((double)(i/9) + tempY) * mTileHit - .5*mTileHit);
        if(hitItem == nullptr || hitItem->GetValue() > 8)
        {
            CheckIsNumberVisitor visitor;
            for(auto item: mItems)
            {
                item->Accept(&visitor);
                if(visitor.IsNumber() && item->GetValue() == mBoard->getMSolution().at(i) && !mBoard->IsOnBoard(item->GetX(), item->GetY(), this))
                {
                        item->SetLocation(((double)(i%9) + mBoard->getMx()) * mTileWidth, ((double)(i/9) + mBoard->getMy()) * mTileHit);
                        item->Update(0);
                        mCount++;
                        break;
                }
            }
        }
    }
}

/**
 * Handle a node of type item.
 * @param node XML node
 * @returns Pointer to item created
 */
shared_ptr<Item> Game::XmlItem(wxXmlNode * node) {
    // if we are in the item part of the xml
    // then instantiate the items into the level list
    auto item = mDeclarations[node->GetAttribute(L"id")]->Create(node, this);
    return item;
}

/**
 * Load the level from a XML file.
 * Opens the XML file and reads the nodes, creating items as appropriate.
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
                } else if (superChildName == L"speedpotion") {
                    mDeclarations.insert({superChild->GetAttribute(L"id"), make_shared<DeclarationPotion>(superChild)});
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

/**
 * Draw the message for the start of the level
 * @param graphics
 */
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
* Add Item to mItems
 * @param item Item to be added
*/
void Game::AddItem(std::shared_ptr<Item> item)
{
    auto sparty = mItems.back();
    mItems.pop_back();
    mItems.push_back(item);
    mItems.push_back(sparty);
}

/**
    * Draw "I'm Full" message
    * @param graphics the graphics context to draw into
    */
void Game::DrawImFull(std::shared_ptr<wxGraphicsContext> graphics)
{
    wxBrush rectBrush(*wxWHITE);
    graphics->SetBrush(rectBrush);
    graphics->SetPen(wxNullGraphicsPen);
    graphics->DrawRectangle(mPixelWidth / 3, mPixelHeight - mMessageAmount, 400, 150);
    wxFont font(wxSize(20, 70),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_BOLD);
    graphics->SetFont(font, wxColour(255, 0, 0));
    graphics->DrawText(L"I'M FULL", mPixelWidth / 3 + 50, mPixelHeight - mMessageAmount + 25);
}