/**
 * @file Wildcard.h
 * @author Chirag Solanki
 *
 *
 */


#ifndef PROJECT1_WILDCARD_H
#define PROJECT1_WILDCARD_H

#include "Item.h"
#include <random>

class Game;

class Wildcard : public Item {
private:
    /// The game this Wildcard is a part of
    Game* mGame;

    /// The image file for the wildcard
    std::unique_ptr<wxBitmap> mImage;

    /// Speed modification value
    double mSpeedModifier;

public:
    Wildcard(Game* game);

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    virtual void Update(double elapsed) override;

    /** Function to handle the interaction with Sparty
     * It should be called when Sparty "eats" the Wildcard
     */
    void AffectSparty();

    /** Gets the speed modifier. */
    double GetSpeedModifier() const { return mSpeedModifier; }

    /** Generates a random speed modifier for the wildcard. */
    void GenerateSpeedModifier();
};

#endif //PROJECT1_WILDCARD_H

