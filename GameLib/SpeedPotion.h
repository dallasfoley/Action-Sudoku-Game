/**
 * @file SpeedPotion.h
 * @author Chirag Solanki
 *
 *
 */


#ifndef PROJECT1_SPEEDPOTION_H
#define PROJECT1_SPEEDPOTION_H

#include "Item.h"
#include <random>
#include <memory>

class Game;

class SpeedPotion : public Item {
private:

    /// Vector of items in the XRay
    std::vector<std::shared_ptr<Item>> mItems;

    /// Image for the XRay
    std::unique_ptr<wxImage> mImage;

    /// Bitmap for the SpeedPotion
    std::unique_ptr<wxBitmap> mBitmap;

    /// X position of the SpeedPotion
    double mX = 20;

    /// Y position of the SpeedPotion
    double mY = 560;

    /// Game context
    Game * mGame;

    double mSpeedModifier;  // Speed modification value

    // Random number generator
    static std::mt19937 mRNG;

    void GenerateSpeedModifier();

public:
    SpeedPotion(Game* game);
    ~SpeedPotion();

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void Update(double elapsed) override;

    // Function to handle the interaction with Sparty
    void AffectSparty();

    virtual void OnConsume(); // Function called when Sparty consumes the potion.
};

#endif //PROJECT1_SPEEDPOTION_H



