/**
 * @file Sparty.h
 * @author rohch
 *
 * Class to describe the Sparty character
 */

#ifndef PROJECT1_GAMELIB_SPARTY_H
#define PROJECT1_GAMELIB_SPARTY_H

#include "Game.h"
#include "Item.h"
#include <wx/graphics.h>
#include <memory>

/**
 * Class to describe the Sparty character
 */
class Sparty : public Item {
private:
    /// Character speed in pixels per second
    const double mMaxSpeed = 400.00;

    /// The time for an eating cycles in seconds
    const double mEatingTime = 0.5;

    /// The time for a headbutt cycle in seconds
    const double mHeadbuttTime = 0.5;

    /// The Sparty mouth image
    std::unique_ptr<wxImage> mMouth;

    /// The Sparty mouth bitmap (I couldnt make wxGraphicBitmap work, maybe try again later)
    std::unique_ptr<wxBitmap> mMouthBitmap;

    /// Rotation angle
    double mRotation = 0;

    /// The destination X coordinate
    double mDestinationX = GetX();

    /// The destination Y coordinate
    double mDestinationY = GetY();

    /// Value to determine which image to draw first
    int front = 2;

    /// mouth pivot point
    wxPoint mMouthPivot = wxPoint((int)GetX(),(int)GetY());

    /// mouth pivot angle
    double mMouthAngle = 5;

    /// boolean to determine if Sparty is currently eating
    bool mEating = false;


    ///current game context
    Game * mGame;
public:
    /**
     * Constructor for Sparty
     */
    explicit Sparty(Game *game);

    /**
     * Destructor for Sparty
     */
    ~Sparty();

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    /**
     * Update the Sparty character
     * @param elapsed The time elapsed since the last update
     */
    void Update(double elapsed) override;

    void SetLandingPoint(double x, double y);

    /**
     * if the Sparty character is in motion
     */
    bool InMotion();

    /**
     * Implement the Sparty character's eating action
     */
    void Eat();

    /**
     * Implement the vomiting action
     */
    void Vomit();

    /**
     * Implement the headbutt action
     */
    void Headbutt();
};

#endif //PROJECT1_GAMELIB_SPARTY_H
