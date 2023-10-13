/**
 * @file Board.h
 * @author rohch
 *
 *
 */

#ifndef PROJECT1_GAMELIB_BOARD_H
#define PROJECT1_GAMELIB_BOARD_H

#include "Item.h"


class Board
{
private:
    /// vector of items on the board
    std::vector<Item> mItems;

    /// image of the board
    std::unique_ptr<wxImage> mBoardImage;

    /// bitmap of the board
    std::unique_ptr<wxGraphicsBitmap> mBoardBitmap;


public:
    /**
     * Constructor
     */
    Board();

    /**
     * Destructor
     */
    ~Board();

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
