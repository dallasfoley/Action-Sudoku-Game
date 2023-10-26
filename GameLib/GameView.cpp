/**
 * @file GameView.cpp
 * @author Jon Price
 */

#include "pch.h"
#include "ids.h"
#include "GameView.h"
#include <wx/dcbuffer.h>

/// Frame duration in milliseconds
const int FrameDuration = 30;

void GameView::OnPaint(wxPaintEvent& event)
{

    // Calc (short for calculate) the time that has elapsed
    // since the last call to OnPaint
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;

    mGame.Update(elapsed);


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
 * toggle the fps display
 */
void GameView::OnFpsDisplay(wxCommandEvent& event)
{
    mGame.SetDisplayFps();
}


/**
* initialize the Game view class
 * @param parent the parent window for this class
*/
void GameView::Initialize(wxFrame *parent)
{
    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);

    Create(parent, wxID_ANY,
           wxDefaultPosition, wxDefaultSize,
           wxFULL_REPAINT_ON_RESIZE);

    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &GameView::OnPaint, this);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLoadSolve, this, IDM_SOLVE);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLoadLvl1, this, IDM_ADDLVL1);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLoadLvl2, this, IDM_ADDLVL2);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLoadLvl3, this, IDM_ADDLVL3);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnFpsDisplay, this, IDM_FPS);

    Bind(wxEVT_TIMER, &GameView::OnTimer, this);
    Bind(wxEVT_MOTION, &GameView::OnMouseMove, this);
    Bind(wxEVT_LEFT_DOWN, &GameView::OnLeftDown, this);
    Bind(wxEVT_KEY_DOWN, &GameView::OnKeyDown, this);

    mStopWatch.Start();

}




/**
 * Handles click event globally
 * @param event mouse event (click)
 */
void GameView::OnLeftDown(wxMouseEvent & event) {
    mGame.OnLeftDown(event);
}

/**
  * Stop the timer so the window can close
  */
void GameView::Stop() { mTimer.Stop(); }

/**
 * File>Solve menu handler
 * @param event Menu event
 */
void GameView::OnLoadSolve(wxCommandEvent& event)
{
    mGame.Load(L"levels/level1.xml");
}

/**
 * Level>Level 1 menu handler
 * @param event Menu event
 */
void GameView::OnLoadLvl1(wxCommandEvent& event)
{
    mGame.Restart();
    mGame.Load(L"levels/level1.xml");
    Refresh();
}

/**
 * Level>Level 2 menu handler
 * @param event Menu event
 */
void GameView::OnLoadLvl2(wxCommandEvent& event)
{
    mGame.Restart();
    mGame.Load(L"levels/level2.xml");
    Refresh();
}

/**
 * Level>Level 3 menu handler
 * @param event Menu event
 */
void GameView::OnLoadLvl3(wxCommandEvent& event)
{
    mGame.Restart();
    mGame.Load(L"levels/level3.xml");
    Refresh();
}

/**
 * Handles key down event globally
 * @param event key event (key down)
 */
void GameView::OnKeyDown(wxKeyEvent & event) {
    mGame.OnKeyDown(event);
}