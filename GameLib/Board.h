/**
 * @file Board.h
 * @author rohch
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
    /*
     * Getter for mX
     * @return mX
     */
    double GetX() const { return mX; }

    /*
     * Getter for mY
     * @return mY
     */
    double GetY() const { return mY; }
    void XmlLoad(wxXmlNode *node);
    bool CheckSolution(Game * game);
    const std::vector<int> &getMSolution() const;
    double getMx() const;
    double getMy() const;

    /**
     * Constructor for Board
     */
    Board(){}

    bool IsOnBoard(double x, double y, Game * game) const;

};

#endif //PROJECT1_GAMELIB_BOARD_H
