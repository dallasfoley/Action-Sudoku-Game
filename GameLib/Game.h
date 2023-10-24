/**
 * @file Game.h
 * @author Jon Price
 */

#ifndef PROJECT1_GAME_H
#define PROJECT1_GAME_H

#include "Item.h"
#include "Scoreboard.h"
#include "Declaration.h"
#include "FpsDisplay.h"

class Sparty;

class XRay;

class Board;


/// class which represents the Game
class Game {
private:
    int mLevel = 1;  ///< Current level
    double mScale; ///< current scaling of the window
    double mXOffset;
    double mYOffset;
    int mPixelHeight;
    int mPixelWidth;
    bool mDisplayFps = false;
    std::unique_ptr<wxBitmap> mBackground; ///< background for the level, for now a placeholder
    std::shared_ptr<XRay> mXRay;    ///< XRay
    Scoreboard mScoreboard;    ///< Scoreboard(timer)
    std::shared_ptr<Board> mBoard;   ///< Board
    std::vector<std::shared_ptr<Item>> mItems;  ///< Items in the game

    FpsDisplay mFpsDisplay;

    std::unordered_map<wxString, std::shared_ptr<Declaration>> mDeclarations;

public:
    void SetDisplayFps() { mDisplayFps = !mDisplayFps; } ///< @param b true when display is going to display

    Game();
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    void DrawMessage(std::shared_ptr<wxGraphicsContext> graphics);
    int GetLevel() const {return mLevel;}
    void XmlItem(wxXmlNode * node);
    void Update(double elapsed);
    void OnLeftDown(wxMouseEvent & event);
    void OnKeyDown(wxKeyEvent & event);
    std::shared_ptr<Item> HitTest(int x, int y);
    std::shared_ptr<Sparty> GetSparty() { return mSparty; }
    void Clear();
    void Restart();
    bool CheckSolved();
    void Load(const wxString &filename);
    int GetMapLength() { return mDeclarations.size(); } ///< returns length of declaration file, used right now for a test
};


#endif //PROJECT1_GAME_H
