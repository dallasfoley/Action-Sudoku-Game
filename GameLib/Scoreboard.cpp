/**
 * @file Scoreboard.cpp
 * @author dalla
 */

#include "pch.h"
#include "Scoreboard.h"
#include <sstream>

using namespace std;

/// Frame duration in milliseconds
const int FrameDuration = 30;
/// Size of the scoreboard text in virtual pixels
const int ScoreboardTextSize = 64;

/**
 * Top left corner of the scoreboard in virtual pixels.
 * @return int.
 */
const wxPoint ScoreboardTopLeft(10, 10);


/**
 * Handle updates in time of our scoreboard
 * @param elapsed Time elapsed since the class call
 */
void Scoreboard::Update(double elapsed)
{
    mDuration += elapsed;
}

/**
 * Resets scoreboard to 0:00
 */
void Scoreboard::Reset()
{
    mDuration = 0;
}

/**
 * Draw the scoreboard
 * @param graphics The graphics context to draw on
 */
void Scoreboard::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    wxFont font(wxSize(10, 60),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_BOLD);
    graphics->SetFont(font, wxColour(255, 255, 255));
    if (mDuration == 0)
        graphics->DrawText(L"0:00" , ScoreboardTopLeft.x, ScoreboardTopLeft.y);
    else
    {
        int mins = (int)mDuration / 60;
        int secs = (int)mDuration % 60;
        ostringstream os;
        os << mins << ":";
        if (secs < 10)
            os << '0' << secs;
        else
            os << secs;
        graphics->DrawText(os.str(), ScoreboardTopLeft.x, ScoreboardTopLeft.y);

    }

}

