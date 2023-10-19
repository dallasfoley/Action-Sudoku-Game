/**
  * @file Level.cpp
  * @author Chirag Solanki
 */

#include "pch.h"
#include "Level.h"
#include <iostream>

void Level::loadFromXML(const std::string& path){
    // This is for implementation for parsing XML and loading configurations
    // Pretty sure this requires integrating with an XML parsing library
}


bool Level::checkCompletion()
{


    return currentSolution == gameSolution;
}

std::pair<int, int> Level::getItemPositionInPixels(int col, int row) {
    int x = col * tileWidth;
    // The y coordinate is calculated differently because the origin is at the top left corner, and we're given the bottom-left corner
    int y = (height - row - 1) * tileHeight; // for this im assuming height is the height of the game area in tiles, not pixels
    return {x, y};
}


void Level::restartLevel() {
    // Reset the player's solution
    currentSolution = initialSolution;  // or use clear(), assign()

    // Reset item positions if they're supposed to move during the game (i dont know how to implement)


    // Reset any other game state (i dont know how to implement)

}


void Level::moveDigitsToCorrectLocations() {
    // This is for implementation for moving the digits to their correct locations

    for (int row = 0; row < gameSolution.size(); ++row) {
        for (int col = 0; col < gameSolution[row].size(); ++col) {
            // Set the mPosition of the digit at (row, col) to match the solution
            // The specifics depend on how you're storing the digits and their positions
        }
    }
}
