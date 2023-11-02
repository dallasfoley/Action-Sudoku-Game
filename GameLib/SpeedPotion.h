/**
 * @file SpeedPotion.h
 * @author Chirag Solanki
 *
 * Base class for speed potion in lvl 3 of the Game
 */


#ifndef PROJECT1_SPEEDPOTION_H
#define PROJECT1_SPEEDPOTION_H

#include "Item.h"
#include "DeclarationPotion.h"
#include <random>
#include <memory>

class Game;


/**
 * Base class for speed potion in lvl 3 of the Game
 */
class SpeedPotion : public Item {
private:

    /// Vector of items in the XRay
    std::vector<std::shared_ptr<Item>> mItems;

    /// Image for the XRay
    std::unique_ptr<wxImage> mImage;

    /// Bitmap for the SpeedPotion
    std::unique_ptr<wxBitmap> mBitmap;

    /// X position of the SpeedPotion
    double mX;

    /// Y position of the SpeedPotion
    double mY;

    /// Game context
    Game * mGame;

    /// Speed modifier
    double mSpeedModifier;

    // Random number generator
    std::mt19937 mRNG;

    void GenerateSpeedModifier();

public:
    SpeedPotion(DeclarationPotion * declaration, wxXmlNode * node, Game * game);
    ~SpeedPotion();

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void Update(double elapsed) override;

    void XmlLoad(wxXmlNode *node) override;

    // Function to handle the interaction with Sparty
    void AffectSparty() override;

    virtual void OnConsume(); // Function called when Sparty consumes the potion.

    void Accept(ItemVisitor* visitor) override;

};

#endif //PROJECT1_SPEEDPOTION_H



