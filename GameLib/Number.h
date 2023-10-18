/**
  * @file Number.h
  * @author Chirag Solanki
  *
  * The Number class represents an individual digit within the Sudoku game.
 */

# ifndef PROJECT1_NUMBER_H
# define PROJECT1_NUMBER_H

#include "pch.h"
#include "Level.h"
#include "Sparty.h"
#include "Board.h"
#include "Item.h"
#include <utility>


class Number
{
private:
    int value;                                   /// The actual digit value ranging from 0 to 8
    bool isGiven;                                /// Indicates if this number is a given
    std::pair<int, int> position;                /// Current position (x, y) of the number.
    bool isInSpartyStomach;                      /// Indicates if this number is inside sparty's stomach
    bool isInContainer;                          /// Indicates if this number is inside a container

public:
    /**
      * Moves the number to a specified position on the board.
      * @param x The x-coordinate.
      * @param y The y-coordinate.
     */
    void moveToPosition(int x, int y);

    /**
      * Marks the number as being inside Sparty's stomach.
     */
    void eatenBySparty();

    /**
      * Removes the number from Sparty's stomach.
     */
    void regurgitatedBySparty();

    /**
      * Marks the number as being inside a container.
     */
    void placeInContainer();

    /**
      * Removes the number from the container.
     */
    void releaseFromContainer();
};

# endif //PROJECT1_NUMBER_H