/**
 * @file GameView.cpp
 * @author Jon Price
 */

#include "pch.h"
#include "GameView.h"
#include <wx/dcbuffer.h>

/// Frame duration in milliseconds
const int FrameDuration = 30;

void GameView::OnPaint(wxPaintEvent& event)
{
    // Create a double-buffered display context
    wxAutoBufferedPaintDC dc(this);

    // Clear the image to black
    wxBrush background(*wxBLACK);
    dc.SetBackground(background);
    dc.Clear();

    // Create a graphics context
    auto gc =
            std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));

    // Tell the game class to draw
    wxRect rect = GetRect();
    mGame.OnDraw(gc, rect.GetWidth(), rect.GetHeight());
}

/**
 * Event handler for wxEVT_TIMER
 * @param event
 */
void GameView::OnTimer(wxTimerEvent& event)
{
    Refresh();
}
/**
 * Handle the mouse move event
 * @param event
 */
void GameView::OnMouseMove(wxMouseEvent &event)
{
    /*
     * Implement clicking functionality here (in part)
     */
    Refresh();
}


/**
* initialize the Game view class
 * @param parent the parent window for this class
*/
void GameView::Initialize(wxFrame *parent)
{
    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);

    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &GameView::OnPaint, this);
    Bind(wxEVT_TIMER, &GameView::OnTimer, this);
    Bind(wxEVT_MOTION, &GameView::OnMouseMove, this);

    mStopWatch.Start();

}