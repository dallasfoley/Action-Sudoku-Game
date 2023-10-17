/**
 * @file Sparty.h
 * @author rohch
 *
 * Class to describe the Sparty character
 */

#ifndef PROJECT1_GAMELIB_SPARTY_H
#define PROJECT1_GAMELIB_SPARTY_H

#include "Item.h"
#include <wx/graphics.h>
#include <memory>

/**
 * Class to describe the Sparty character
 */
class Sparty : public Item
{
private:
    /// Character speed in pixels per second
    const double MaxSpeed = 400.00;

    /// The time for an eating cycles in seconds
    const double EatingTime = 0.5;

    /// The time for a headbutt cycle in seconds
    const double HeadbuttTime = 0.5;

    /// The Sparty head image
    std::unique_ptr<wxImage> mHead;

    /// The Sparty head bitmap
    std::unique_ptr<wxGraphicsBitmap> mHeadBitmap;

    /// The Sparty mouth image
    std::unique_ptr<wxImage> mMouth;

    /// The Sparty mouth bitmap
    std::unique_ptr<wxGraphicsBitmap> mMouthBitmap;

    /// The launching point for the Sparty
    // to be implemented

    /// The landing point for the Sparty
    // to be implemented

    /// Value to determine which image to draw first
    int front = 2;

    /// column Sparty is in
    int col = 0;

    /// row Sparty is in
    int row = 0;

    /// mouth pivot point
    wxPoint mMouthPivot;

    /// mouth pivot angle
    double mMouthAngle = 0;

public:
    /**
     * Constructor for Sparty
     */
    Sparty();

    /**
     * Destructor for Sparty
     */
    ~Sparty();


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

    /**
     * Set the Sparty character's landing point
     * @param x The x coordinate of the landing point
     * @param y The y coordinate of the landing point
     */
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
