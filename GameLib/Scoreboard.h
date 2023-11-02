/**
 * @file Scoreboard.h
 * @author dalla
 *
 * Base class for scoreboard in the Game
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_SCOREBOARD_H
#define ACTIONSUDOKU_SUDOKULIB_SCOREBOARD_H

#include "Item.h"

/**
 * Base class for scoreboard in the Game
 */
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

    /**
     * Get the duration of the game
     * @return double The duration of the game
     */
    double GetDuration() const {return mDuration;}

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitScoreboard(this); }

};

#endif //ACTIONSUDOKU_SUDOKULIB_SCOREBOARD_H
