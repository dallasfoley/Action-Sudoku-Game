/**
 * @file Sparty.cpp
 * @author rohch
 * @author Jon Price
 */

#include "pch.h"
#include "Sparty.h"
#include "Game.h"
#include "cmath"
#include "Number.h"
#include "XRay.h"

using namespace std;

const wstring SpartyHead1 = L"images/sparty-1.png";
const wstring SpartyJaw1 = L"images/sparty-2.png";

/// Rotation rate in radians per second
const double RotationRate = 6;
/**
 * Constructor for Sparty
 */
Sparty::Sparty(Game *game) : mMaxSpeed(400.00)
{
    mGame = game;

    // Image and bitmap for the head of Sparty
    mHead = make_unique<wxImage>(SpartyHead1, wxBITMAP_TYPE_ANY);
    mHeadBitmap = make_unique<wxBitmap>( *mHead);

    // Image and bitmap for jaw of Sparty
    mMouth = make_unique<wxImage>(SpartyJaw1, wxBITMAP_TYPE_ANY);
    mMouthBitmap = make_unique<wxBitmap>( *mMouth);
}

/**
 * Draw the Sparty character
 * @param graphics The graphics context to draw on
 */
void Sparty::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    double wid = mHeadBitmap->GetWidth();
    double hit = mHeadBitmap->GetHeight();
    graphics->DrawBitmap(*mHeadBitmap,
                         (mX),
                         (mY),
                         wid,
                         hit);
    wid = mMouthBitmap->GetWidth();
    hit = mMouthBitmap->GetHeight();
    graphics->DrawBitmap(*mMouthBitmap,
                         (mX),
                         (mY),
                         wid,
                         hit);
    if (mEating)
    {
        mEating = false;
        graphics->PushState();

        graphics->Translate(mMouthPivot.x, mMouthPivot.y);
        graphics->Rotate(mMouthAngle);
        graphics->Translate(-mMouthPivot.x, -mMouthPivot.y);

        graphics->DrawBitmap(*mMouthBitmap, -wid/2, -hit/2, wid, hit);

        graphics->PopState();
    }
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
    mRotation += RotationRate * elapsed;
    if(mX != mDestinationX || mY != mDestinationY)
    {
        double currentSpeed = mMaxSpeed;

        // some quick vector math, make a vector along the path from Sparty to his destination
        double xComponent = mDestinationX - mX;
        double yComponent = mDestinationY - mY;
        // then normalize the vector, so we can cleanly multiply it by the speed
        double mag = sqrt(xComponent*xComponent + yComponent*yComponent);
        xComponent/=mag;
        yComponent/=mag;

        // incorporate the time between frames, so speed isn't dependent on framerate
        auto xIncrement = currentSpeed * xComponent * elapsed;
        auto yIncrement = currentSpeed * yComponent * elapsed;

        // if the step is larger than the distance between Sparty and his destination, put Sparty at his destination
        // otherwise, increment Sparty's location as normal
        if(abs(mDestinationX - mX) < abs(xIncrement)) {
            mX = mDestinationX;
        } else {
            mX += xIncrement;
        }
        if(abs(mDestinationY - mY) < abs(yIncrement)) {
            mY = mDestinationY;
        } else {
            mY += yIncrement;
        }

    }

    // if Sparty is currently eating, show the mouth open and close around the jaw
    if(mEating)
    {
        // set a destination for the mouth to rotate around relative to Sparty's location
        wxPoint pivotDestination = wxPoint(mX - 30, mY + 30);

        // set an angle for the mouth to rotate around the pivot point
        mMouthAngle = atan2(pivotDestination.y - mMouthPivot.y, pivotDestination.x - mMouthPivot.x);
        

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
    mDestinationY = y - 70;
}

// /**
//  * Set the Sparty character's launching point
//  * @param x The x coordinate of the launching point
//  * @param y The y coordinate of the launching point
//  */
// void Sparty::SetLaunchingPoint(double x, double y)
// {
//
// }

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


void Sparty::Headbutt()
{

}