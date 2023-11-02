/**
 * @file FpsDisplay.cpp
 * @author Jon Price
 */
#include "pch.h"
#include "FpsDisplay.h"
#include <sstream>

/**
 * Update the fps display
 * @param elapsed time since last frame
 */
void FpsDisplay::Update(double elapsed)
{
    // convert from time per frame to frames per time
    mFrames = 1/elapsed;
}

/**
 * Draw the FPS display
 * @param graphics context for this object
 */
void FpsDisplay::Draw(std::shared_ptr<wxGraphicsContext> graphics) {
    wxFont font(wxSize(10, 30),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_BOLD);
    graphics->SetFont(font, wxColour(255, 255, 255));
    std::ostringstream os;

    os << "FPS:" << mFrames;

    graphics->DrawText(os.str(), 775, 20);
}
