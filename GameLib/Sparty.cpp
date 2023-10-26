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


Sparty::Sparty(wxXmlNode * node, DeclarationSparty * dec) : Item(dec, node)
{
    mMouth = make_unique<wxImage>(dec->getJawImage());
    mMouthBitmap = make_unique<wxBitmap>(*mMouth);
    mMouthAngle = dec->getMouthPivotAngle();
    mMouthPivot = wxPoint((int)dec->getHeadPivotX(), (int)dec->getHeadPivotY());

    Sparty::SetLandingPoint(GetX(), GetY());

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

    graphics->Translate(mHeadPivot.x + GetX(), mHeadPivot.y + GetY());
    graphics->Rotate(mHeadAngleCurrent);
    graphics->Translate(-mHeadPivot.x - GetX(), -mHeadPivot.y - GetY());

    Item::Draw(graphics);

    if (mEating)
    {
        // Put correct code here
        mEating = false;
        graphics->Translate(mMouthPivot.x + GetX(), mMouthPivot.y  + GetY());
        graphics->Rotate(mMouthAngle);
        graphics->Translate(-mMouthPivot.x - GetX(), -mMouthPivot.y - GetY());
    }

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

    }
    {
        // if Sparty is currently eating, show the mouth open and close around the jaw
        if (mEating)
        {
            // set a destination for the mouth to rotate around relative to Sparty's location
            wxPoint pivotDestination = wxPoint(GetX() - 30, GetY() + 30);

            // set an angle for the mouth to rotate around the pivot point
            mMouthAngle = atan2(pivotDestination.y - mMouthPivot.y, pivotDestination.x - mMouthPivot.x);
        }
        //if Sparty is currently eating, show the mouth open and close around the jaw
        if(mHeadbutting)
        {
            double increment = mHeadAngle/mHeadButtTime;

            mHeadAngleCurrent += increment*elapsed/mHeadButtTime;

            if(mHeadAngleCurrent > mHeadAngle)
                mHeadAngleCurrent = mHeadAngle;

            mHeadbutting = mHeadAngle != mHeadAngleCurrent;
        } else if (mHeadAngleCurrent != 0) {
            double increment = -mHeadAngle/mHeadButtTime;
            mHeadAngleCurrent += increment*elapsed/mHeadButtTime;

            if(mHeadAngleCurrent < 0)
                mHeadAngleCurrent = 0;
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
    mHeadbutting = true;
}