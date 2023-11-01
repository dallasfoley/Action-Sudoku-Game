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
#include <Random>

class Sparty;

class XRay;

class Board;

class ItemVisitor;


/// class which represents the Game
class Game {
private:
    /// Enumerating class
    enum class Type {Start, Playing, Incorrect, Correct};
    /// Member variable mType
    Type mType = Type::Start;
    /// Current level member variable
    int mLevel = 1;
    /// Count of numbers on the board
    int mCount = 0;
    /// Window scaling member variable
    double mScale;
    /// X offset member variable
    double mXOffset;
    /// Y offset member variable
    double mYOffset;
    /// Board tile width member variable
    double mTileWidth;
    /// Board tile height member variable
    double mTileHit;
    /// Pixel height member variable
    int mPixelHeight;
    /// Pixel width member variable
    int mPixelWidth;
    /// FPS display
    bool mDisplayFps = false;
    /// The scoreboard or timer
    Scoreboard mScoreboard;
    /// The playing board
    std::shared_ptr<Board> mBoard;
    /// Game items
    std::vector<std::shared_ptr<Item>> mItems;
    /// FPS display boolean
    FpsDisplay mFpsDisplay;
    /// Map for declarations
    std::unordered_map<wxString, std::shared_ptr<Declaration>> mDeclarations;
    /// Tracks game time
    double mGameTimer;

    std::mt19937 mRandom;

public:
    void SetDisplayFps() {mDisplayFps = !mDisplayFps;} ///< @param b true when display is going to display
    Game();
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    void Update(double elapsed);
    void DrawMessage(std::shared_ptr<wxGraphicsContext> graphics);
    int GetLevel() const {return mLevel;}
    std::shared_ptr<Item> XmlItem(wxXmlNode * node);
    void OnLeftDown(wxMouseEvent & event);
    void OnKeyDown(wxKeyEvent & event);
    std::shared_ptr<Item> HitTest(double x, double y);
    void Clear();
    void Restart();
    void NextLevel();
    bool CheckSolved();
    void Load(const wxString &filename);
    int GetMapLength() { return mDeclarations.size(); } ///< returns length of declaration file, used right now for a test
    double GetTileWidth() const {return mTileWidth;}
    double GetTileHit() const {return mTileHit;}
    void Accept(ItemVisitor* visitor);
    void AddItem(std::shared_ptr<Item> item);
    void Solve();
    void IncrementGameCount() {mCount++;}

    /**
     * Get teh random number generator
     * @retunr pointer to the random number generator
     */
     std::mt19937 &GetRandom() {return mRandom;}
};


#endif //PROJECT1_GAME_H
