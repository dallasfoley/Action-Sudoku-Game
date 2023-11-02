/**
 * @file GameView.h
 * @author Jon Price
 *
 * View class for the game
 */
#ifndef PROJECT1_GAMEVIEW_H
#define PROJECT1_GAMEVIEW_H

#include "Game.h"

/**
 * View class for the game
 */
class GameView : public wxWindow{
private:
    void OnPaint(wxPaintEvent& event);

    /// object that describes our game
    Game mGame;

    /// Timer allowing for animation
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// the last stopwatch time
    long mTime = 0;
public:
    void Initialize(wxFrame* parent);
    void OnFpsDisplay(wxCommandEvent& event);
    void OnLoadSolve(wxCommandEvent& event);
    void OnLoadLvl1(wxCommandEvent& event);
    void OnLoadLvl2(wxCommandEvent& event);
    void OnLoadLvl3(wxCommandEvent& event);
    void OnTimer(wxTimerEvent & event);
    void OnMouseMove(wxMouseEvent &event);
    void OnLeftDown(wxMouseEvent & event);
    void Stop();
    void OnKeyDown(wxKeyEvent & event);
};


#endif //PROJECT1_GAMEVIEW_H
