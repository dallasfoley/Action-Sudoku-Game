/**
 * @file Sparty.cpp
 * @author rohch
 * @author Jon Price
 */

#include "pch.h"
#include "Sparty.h"
#include "Item.h"
#include "Game.h"
#include "cmath"
#include "Number.h"
#include "XRay.h"
#include "DeclarationSparty.h"

using namespace std;


// Default Sparty images
const wstring SpartyHead1 = L"images/sparty-1.png";
const wstring SpartyJaw1 = L"images/sparty-2.png";

/// Rotation rate in radians per second
const double RotationRate = 6;

/// The time for a headbutt cycle in seconds
const double HeadbuttTime = 0.5;

/**
 * Constructor for Sparty
 */
Sparty::Sparty(Game *game) : Item(game, SpartyHead1)
{
    mGame = game;

    // Image and bitmap for jaw of Sparty
    mMouth = make_unique<wxImage>(SpartyJaw1, wxBITMAP_TYPE_ANY);
    mMouthBitmap = make_unique<wxBitmap>( *mMouth);
}

Sparty::Sparty(wxXmlNode * node, DeclarationSparty * dec) : Item(dec, node)
{
    mMouth = make_unique<wxImage>(dec->getJawImage());
    mMouthBitmap = make_unique<wxBitmap>(*mMouth);
    mMouthAngle = dec->getMouthPivotAngle();
    mMouthPivot = wxPoint((int)dec->getHeadPivotX(), (int)dec->getHeadPivotY());
    mDestinationX = dec->getTargetX();
    mDestinationY = dec->getTargetY();
    mHeadPivot.x = dec->getHeadPivotX();
    mHeadPivot.y = dec->getHeadPivotY();
    mHeadAngle = dec->getHeadPivotAngle();


}

/**
 * Draw the Sparty character
 * @param graphics The graphics context to draw on
 */
void Sparty::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    graphics->PushState();
    if (mEating)
    {
        // Put correct code here
        mEating = false;
        graphics->Translate(mMouthPivot.x, mMouthPivot.y);
        graphics->Rotate(mMouthAngle);
        graphics->Translate(-mMouthPivot.x, -mMouthPivot.y);
    }
    if (mHeadbuttCurrent > 0)
    {
        auto headbuttTime2 = HeadbuttTime / 2;
        mHeadPivot.x = 30;
        mHeadPivot.y = 86;
        double headAngle{};
        if (mHeadbuttCurrent < headbuttTime2)
        {
            headAngle = .5 / (0.8 * headbuttTime2);
        }
        else
        {
            headAngle = (.5 - mHeadbuttCurrent) / (0.8 * headbuttTime2);
        }

        int headX = GetX() - GetWidth() / 2;
        int headY = GetY() - GetHeight();
        graphics->PushState();
        //graphics->Translate(headX, headY);
        //Item::Draw(graphics);
        //graphics->Translate(-headX, -headY);
        graphics->Translate(mHeadPivot.x, mHeadPivot.y);
        graphics->Rotate(headAngle);
        graphics->Translate(-mHeadPivot.x, -mHeadPivot.y);
    }
    int headX = GetX() - GetWidth() / 2;
    int headY = GetY() - GetHeight();
    graphics->Translate(headX, headY);
    Item::Draw(graphics);
    double wid = mMouthBitmap->GetWidth();
    double hit = mMouthBitmap->GetHeight();
    graphics->DrawBitmap(*mMouthBitmap,
                         (GetX()),
                         (GetY() - hit),
                         wid,
                         hit);
    graphics->PopState();
}


/**
 * Destructor for Sparty
 */
Sparty::~Sparty()
{

}

/**
 * Update the Sparty character
 * @param elapsed The time elapsed since the last update
 */
void Sparty::Update(double elapsed)
{

    if(GetX() != mDestinationX || GetY() != mDestinationY)
    {
        double currentSpeed = mMaxSpeed;

        // some quick vector math, make a vector along the path from Sparty to his destination
        double xComponent = mDestinationX - GetX();
        double yComponent = mDestinationY - GetY();
        // then normalize the vector, so we can cleanly multiply it by the speed
        double mag = sqrt(xComponent*xComponent + yComponent*yComponent);
        xComponent/=mag;
        yComponent/=mag;

        // incorporate the time between frames, so speed isn't dependent on framerate
        auto xIncrement = currentSpeed * xComponent * elapsed;
        auto yIncrement = currentSpeed * yComponent * elapsed;

        // if the step is larger than the distance between Sparty and his destination, put Sparty at his destination
        // otherwise, increment Sparty's location as normal
        if(abs(mDestinationX - GetX()) < abs(xIncrement)) {
            SetX(mDestinationX);
        }
        else {
            SetX(GetX() + xIncrement);
        }
        if(abs(mDestinationY - GetY()) < abs(yIncrement)) {
            SetY(mDestinationY);
        } else {
            SetY(GetY() + yIncrement);
        }

    } else {

        // if Sparty is currently eating, show the mouth open and close around the jaw
        if (mEating)
        {
            // set a destination for the mouth to rotate around relative to Sparty's location
            wxPoint pivotDestination = wxPoint(GetX() - 30, GetY() + 30);

            // set an angle for the mouth to rotate around the pivot point
            mMouthAngle = atan2(pivotDestination.y - mMouthPivot.y, pivotDestination.x - mMouthPivot.x);
        }
        //if Sparty is currently eating, show the mouth open and close around the jaw
        if(mHeadbuttCurrent > 0)
        {
            mHeadbuttCurrent -= elapsed;
            // set a destination for the mouth to rotate around relative to Sparty's location

            if (mHeadbuttCurrent < 0)
                mHeadbuttCurrent = 0;

        }
    }
}

/**
 * Set the Sparty character's landing point
 * @param x The x coordinate of the landing point
 * @param y The y coordinate of the landing point
 */
void Sparty::SetLandingPoint(double x, double y)
{
    mDestinationX = x - 60;
    mDestinationY = y + 25;
}

// /**
//  * if the Sparty character is in motion
//  */
// bool Sparty::InMotion()
// {
//     // to be implemented
// }

/**
 * Implement the Sparty character's eating action
 */
void Sparty::Eat()
{
    mEating = true;
}

// /**
//  * Implement the vomiting action
//  */
// void Sparty::Vomit()
// {
//     // to be implemented
// }

/**
 * Implement the Sparty character's headbutting action
 */
void Sparty::Headbutt()
{
    mHeadbuttCurrent = HeadbuttTime;
}