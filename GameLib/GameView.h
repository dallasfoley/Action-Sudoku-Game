/**
 * @file GameView.h
 * @author Jon Price
 */
#ifndef PROJECT1_GAMEVIEW_H
#define PROJECT1_GAMEVIEW_H

#include "Game.h"

/// View class for the game
class GameView : public wxWindow{
private:
    void OnPaint(wxPaintEvent& event);
    Game mGame; ///< object that describes our game
    wxTimer mTimer; ///< Timer allowing for animation
    wxStopWatch mStopWatch; ///< Stopwatch used to measure elapsed time
    long mTime = 0; ///< the last stopwatch time
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
