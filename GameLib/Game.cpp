/**
 * @file Game.cpp
 * @author Jon Price
 */

#include "pch.h"
#include "Game.h"
#include <memory>
#include "Sparty.h"

using namespace std;

const wstring BackgroundImage = L"images/background.png";

/**
 * Constructor
 */
Game::Game()
{
    mBackground = std::make_unique<wxBitmap>(
        BackgroundImage, wxBITMAP_TYPE_PNG);
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

    // Determine the size of the playing area in pixels
    // Subject to change
    int pixelWidth = 960;
    int pixelHeight = 720;

    //
    // Automatic Scaling
    //
    auto scaleX = double(width) / double(pixelWidth);
    auto scaleY = double(height) / double(pixelHeight);
    mScale = std::min(scaleX, scaleY);

    mXOffset = (width - pixelWidth * mScale) / 2.0;
    mYOffset = 0;
    if (height > pixelHeight * mScale)
    {
        mYOffset = (double)((height - pixelHeight * mScale) / 2.0);
    }

    graphics->PushState();

    graphics->Translate(mXOffset, mYOffset);
    graphics->Scale(mScale, mScale);

    //
    // Draw in virtual pixels on the graphics context
    //
    // INSERT YOUR DRAWING CODE HERE

    //
    // Drawing a rectangle that is the playing area size
    //
//    wxBrush background(*wxRED);
//
//    graphics->SetBrush(background);
//    graphics->DrawRectangle(0, 0, pixelWidth, pixelHeight);
//
//    graphics->PopState();

    graphics->DrawBitmap(*mBackground, 0, 0, pixelWidth, pixelHeight);

    mSparty->Draw(graphics);

    graphics->PopState();

}

/**
* Handle a node of type item.
 * @param node XML node
*/
void Game::XmlItem(wxXmlNode * node)
{
    // Implement today probably
}

/**
 * Handles updates for animation
 * @param elapsed time since the last update
 */
void Game::Update(double elapsed)
{
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
