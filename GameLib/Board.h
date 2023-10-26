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
class Board : public Item
{
private:
    int mSolution;
    double mX = 0;
    double mY = 0;

public:
    void XmlLoad(wxXmlNode *node) override;
    Board(){}

    /**
     * Draw the board
     * @param graphics the graphics context to draw on
     * @param width the width of the window
     * @param height the height of the window
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    /**
     * Assigns numbers to tiles
     */
    void AssignNumbers();

    /**
     * Checks if the board is solved
     */
    bool IsSolved();

    /**
     * Positions the items on the board
     */
    void PositionItems();
};

#endif //PROJECT1_GAMELIB_BOARD_H
