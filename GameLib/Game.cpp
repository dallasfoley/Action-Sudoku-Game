/**
 * @file Game.cpp
 * @author Jon Price
 */

#include "pch.h"
#include "Game.h"
#include <memory>
#include "Sparty.h"

using namespace std;

/**
 * Constructor for Game class
 */
Game::Game()
{
    mBackground = make_unique<wxBitmap>(
            L"images/background.png", wxBITMAP_TYPE_ANY);
    mSparty = make_shared<Sparty>(this);
}



/**
 * Draw the game
 * @param graphics Graphics device to draw on
 * @param width Width of the window
 * @param height Height of the window
 */
void Game::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    // Determine the size of the playing area in pixels
    // This is up to you...
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
