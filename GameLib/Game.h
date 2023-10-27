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
    double mTileWidth;
    double mTileHit;
    int mPixelHeight;
    int mPixelWidth;
    bool mIsFilled = false;
    bool mDisplayFps = false;
    std::unique_ptr<wxBitmap> mBackground; ///< background for the level, for now a placeholder
    Scoreboard mScoreboard;    ///< Scoreboard(timer)
    std::shared_ptr<Board> mBoard;   ///< Board
    std::vector<std::shared_ptr<Item>> mItems;  ///< Items in the game

    FpsDisplay mFpsDisplay;

    std::unordered_map<wxString, std::shared_ptr<Declaration>> mDeclarations;

public:
    void SetDisplayFps() { mDisplayFps = !mDisplayFps; } ///< @param b true when display is going to display
    Game();
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    void Update(double elapsed);
    void DrawMessage(std::shared_ptr<wxGraphicsContext> graphics);
    int GetLevel() const {return mLevel;}
    std::shared_ptr<Item> XmlItem(wxXmlNode * node);
    void OnLeftDown(wxMouseEvent & event);
    bool OnKeyDown(wxKeyEvent & event);
    std::shared_ptr<Item> HitTest(int x, int y);
    void Clear();
    void Restart();
    bool CheckSolved();
    void Load(const wxString &filename);
    int GetMapLength() { return mDeclarations.size(); } ///< returns length of declaration file, used right now for a test
    double GetTileWidth() const {return mTileWidth;}
    double GetTileHit() const {return mTileHit;}
};


#endif //PROJECT1_GAME_H
