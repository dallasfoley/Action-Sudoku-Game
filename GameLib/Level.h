/**
  * @file Level.h
  * @author Chirag Solanki
  *
  * The Level class represents a particular stage or level in the Sudoku game,
  * defined by an XML file.
 */

# ifndef PROJECT1_LEVEL_H
# define PROJECT1_LEVEL_H

#include "Item.h"
#include "Number.h"
#include "Sparty.h"
#include "Board.h"
#include "Item.h"
#include <string>
#include <map>
#include <vector>
#include <utility> // This specific one is for std::pair


/**
 * Base class for levels in the Game
 */
class Level
{
private:
    int levelNumber;                                  /// Level's number
    int tileWidth;                                    /// Width of a tile in pixels
    int tileHeight;                                   /// Height of a tile in pixels
    int width;                                        /// Width of the playing area in tiles
    int height;                                       /// Height of the playing area in tiles
    std::map<std::string, Item> declarations;         /// Declarations of all items
    std::vector<Item> items;                          /// Actual items placed on the board
    std::vector<std::vector<int>> gameSolution;       /// Solution of the Sudoku grid
    std::pair<int, int> gameTopLeft;                  /// Top left cell of the Sudoku grid
    bool isCompleted;                                 /// If the current level is completed
    bool isIncorrect;                                 /// If player's solution is incorrect

    std::vector<std::vector<int>> currentSolution;
    std::vector<std::vector<int>> initialSolution;

public:
    /**
      * Parses the XML file specified by the path and loads all configurations, declarations, and items.
      * @param path The path to the XML file.
     */
    void loadFromXML(const std::string& path);

    /**
      * Checks if the current level is completed correctly.
      * @return true if completed correctly, false otherwise.
     */
    bool checkCompletion();

    /**
      * Converts col, row from the XML to the actual pixel mPosition on the screen.
      * @param col The column index.
      * @param row The row index.
      * @return A pair representing the pixel coordinates.
     */
    std::pair<int, int> getItemPositionInPixels(int col, int row);

    /**
      * Resets the level to its initial configuration.
     */
    void restartLevel();

    /**
      * Places digits to their correct positions based on the solution.
     */
    void moveDigitsToCorrectLocations();

};

# endif //PROJECT1_LEVEL_H