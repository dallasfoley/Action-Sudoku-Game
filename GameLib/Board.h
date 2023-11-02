/**
 * @file Board.h
 * @author Joseph Renas
 *
 * Base class for board in the Game
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

    /**
     * getter for mX
     * @return x location
     */
    double GetX() const { return mX; }

    /**
     * getter for mY
     * @return y location
     */
    double GetY() const { return mY; }
    void XmlLoad(wxXmlNode *node);
    bool CheckSolution(Game * game);
    const std::vector<int> &getMSolution() const;
    double getMx() const;
    double getMy() const;
    bool IsOnBoard(double x, double y, Game * game) const;

};

#endif //PROJECT1_GAMELIB_BOARD_H
