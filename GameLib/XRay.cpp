/**
 * @file XRay.cpp
 * @author Jon Price
 */


#include "pch.h"
#include "XRay.h"

using namespace std;

const wstring xRayImage = L"images/xray.png";

/**
 * Constructor for XRay
 * @param game
 */
XRay::XRay(Game *game)
{
    mGame=game;
    mImage = make_unique<wxImage>(xRayImage, wxBITMAP_TYPE_ANY);
    mBitmap = make_unique<wxBitmap>(*mImage);
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
    double wid = mBitmap->GetWidth();
    double hit = mBitmap->GetHeight();
    graphics->DrawBitmap(*mBitmap,
                         (mX),
                         (mY),
                         wid,
                         hit);
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
