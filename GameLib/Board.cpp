/**
 * @file Board.cpp
 * @author rohch
 */

#include "pch.h"
#include "Board.h"

using namespace std;

const wstring BoardImage = L"images/sudoku.png";
/**
 * Constructor
 */
Board::Board()
{
    // to be implemented
}

/**
 * Destructor
 */
Board::~Board()
{
    // to be implemented
}

/**
 * Draw the board
 * @param graphics the graphics context to draw on
 * @param width the width of the window
 * @param height the height of the window
 */
void Board::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    // to be implemented
}

/**
 * Assigns numbers to tiles
 */
void Board::AssignNumbers()
{
    // to be implemented
}

/**
 * Checks if the board is solved
 */
bool Board::IsSolved()
{
    // to be implemented
    return false;
}

/**
 * Positions the items on the board
 */
void Board::PositionItems()
{
    // to be implemented
}
