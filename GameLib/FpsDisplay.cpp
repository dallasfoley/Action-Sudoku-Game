/**
 * @file FpsDisplay.cpp
 * @author Jon Price
 */
#include "pch.h"
#include "FpsDisplay.h"
#include <sstream>


void FpsDisplay::Update(double elapsed)
{
    mFrames = 1/elapsed;
}


void FpsDisplay::Draw(std::shared_ptr<wxGraphicsContext> graphics) {
    wxFont font(wxSize(10, 60),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_BOLD);
    graphics->SetFont(font, wxColour(200, 0, 0));
    std::ostringstream os;

    os << mFrames;

    graphics->DrawText(os.str(), 200, 20);

}
