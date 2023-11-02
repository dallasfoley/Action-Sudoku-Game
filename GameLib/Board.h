/**
 * @file Board.h
 * @author rohch
 *
 *
 */

#ifndef PROJECT1_GAMELIB_BOARD_H
#define PROJECT1_GAMELIB_BOARD_H

#include "Item.h"

/**
 * Base class for board in the Game
 */
class Board
{
private:
    /// Solution for sudoku
    std::vector<int> mSolution;
    /// X location member variable
    double mX = 0;
    /// Y location member variable
    double mY = 0;

public:
    double GetX() const { return mX; }
    double GetY() const { return mY; }
    void XmlLoad(wxXmlNode *node);
    bool CheckSolution(Game * game);
    const std::vector<int> &getMSolution() const;
    double getMx() const;
    double getMy() const;
    Board(){}

    /**
     * Draw the board
     * @param graphics the graphics context to draw on
     * @param width the width of the window
     * @param height the height of the window
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
};

#endif //PROJECT1_GAMELIB_BOARD_H
