/**
 * @file Game.h
 * @author Jon Price
 */

#ifndef PROJECT1_GAME_H
#define PROJECT1_GAME_H

#include "Item.h"


class Sparty;
class Scoreboard;
class Board;


/// class which represents the Game
class Game {
private:
    double mScale; ///< current scaling of the window
    double mXOffset;
    double mYOffset;
    std::unique_ptr<wxBitmap> mBackground; ///< background for the level, for now a placeholder
    std::shared_ptr<Sparty> mSparty;    ///< Sparty
    /// Scoreboard
    std::shared_ptr<Scoreboard> mScoreboard;
    /// Game board
    std::shared_ptr<Board> mBoard;

    std::vector<std::shared_ptr<Item>> mItems;  ///< Items in the game

public:
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    Game();
    void XmlItem(wxXmlNode * node);
    void Update(double elapsed);
    void OnLeftDown(wxMouseEvent & event);
    std::shared_ptr<Item> HitTest(int x, int y);
    void Clear();
    void Restart();
    bool CheckSolved();
};


#endif //PROJECT1_GAME_H
