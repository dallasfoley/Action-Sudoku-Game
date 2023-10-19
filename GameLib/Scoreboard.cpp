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
/// Top left corner of the scoreboard in virtual pixels
const wxPoint ScoreboardTopLeft(10, 10);
const int ScoreboardTopLeftX(10);
const int ScoreboardTopLeftY(10);



/**
 * Handle updates in time of our scoreboard
 *
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
    wxFont font(wxSize(0, 30),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_BOLD);
    graphics->SetFont(font, wxColour(200, 0, 0));
    if (mDuration == 0)
        graphics->DrawText(L"0:00" , ScoreboardTopLeftX, ScoreboardTopLeftY);
    else
    {
        int mins = mDuration / 60;
        int secs = (int)mDuration % 60;
        wstringstream ws;
        ws << mins << " : " << secs;
        graphics->DrawText(ws.str(), ScoreboardTopLeftX, ScoreboardTopLeftY);

    }

}