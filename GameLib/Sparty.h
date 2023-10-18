/**
 * @file Sparty.h
 * @author rohch
 *
 * Class to describe the Sparty character
 */

#ifndef PROJECT1_GAMELIB_SPARTY_H
#define PROJECT1_GAMELIB_SPARTY_H

#include "Game.h"
#include <wx/graphics.h>
#include <memory>

/**
 * Class to describe the Sparty character
 */
class Sparty {
private:
    /// Character speed in pixels per second
    const double mMaxSpeed = 400.00;

    /// The time for an eating cycles in seconds
    const double mEatingTime = 0.5;

    /// The time for a headbutt cycle in seconds
    const double mHeadbuttTime = 0.5;

    /// The Sparty head image
    std::unique_ptr<wxImage> mHead;

    /// The Sparty head bitmap (I couldnt make wxGraphicBitmap work, maybe try again later)
    std::unique_ptr<wxBitmap> mHeadBitmap;

    /// The Sparty mouth image
    std::unique_ptr<wxImage> mMouth;

    /// The Sparty mouth bitmap (I couldnt make wxGraphicBitmap work, maybe try again later)
    std::unique_ptr<wxBitmap> mMouthBitmap;

    /// The launching point for the Sparty
    // to be implemented

    /// Current x position of Sparty
    double mX = 200;

    /// Current y position of Sparty
    double mY = 200;

    /// The destination X coordinate
    double mDestinationX = mX;

    /// The destination Y coordinate
    double mDestinationY = mY;

    /// Value to determine which image to draw first
    int front = 2;

    /// column Sparty is in
    int col = 0;

    /// row Sparty is in
    int row = 0;

    /// mouth pivot point
    wxPoint mMouthPivot = wxPoint(20,60);

    /// mouth pivot angle
    double mMouthAngle = 0;


    ///current game context
    Game * mGame;
public:
    /**
     * Constructor for Sparty
     */
    Sparty(Game *game);

    /**
     * Destructor for Sparty
     */
    ~Sparty();

    double GetX() const {return mX; } ///< @returns X location in pixels
    double GetY() const {return mY; } ///< @returns Y location in pixels

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    /**
     * Update the Sparty character
     * @param elapsed The time elapsed since the last update
     */
    void Update(double elapsed);

    /**
     * Set the Sparty character's launching point
     * @param x The x coordinate of the launching point
     * @param y The y coordinate of the launching point
     */
    void SetLaunchingPoint(double x, double y);


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
};

#endif //PROJECT1_GAMELIB_SPARTY_H
