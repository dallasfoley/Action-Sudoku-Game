/**
 * @file Scoreboard.h
 * @author dalla
 *
 *
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_SCOREBOARD_H
#define ACTIONSUDOKU_SUDOKULIB_SCOREBOARD_H
#include "Item.h"

class Scoreboard : public Item
{
private:
    ///total time
    double mDuration = 0;
public:
    /**
     * Constructor
     */
    Scoreboard() = default;

    /**
     * Destructor
     */
    ~Scoreboard() = default;

    void Update(double elapsed);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    void Reset();
    double GetDuration() const {return mDuration;}

};

#endif //ACTIONSUDOKU_SUDOKULIB_SCOREBOARD_H
