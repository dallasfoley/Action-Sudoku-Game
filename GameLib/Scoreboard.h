/**
 * @file Scoreboard.h
 * @author dalla
 *
 *
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_SCOREBOARD_H
#define ACTIONSUDOKU_SUDOKULIB_SCOREBOARD_H
#include "Item.h"

class Scoreboard
{
private:
    double mDuration;
public:
    Scoreboard();
    ~Scoreboard();
    void Update(double elapsed);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    void Reset();
};

#endif //ACTIONSUDOKU_SUDOKULIB_SCOREBOARD_H
