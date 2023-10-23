/**
 * @file Item.h
 * @author rohch
 * @author Jon Price
 * This file contains the declaration of the Item class
 * which represents an item in the game
 */

#ifndef PROJECT1_GAMELIB_ITEM_H
#define PROJECT1_GAMELIB_ITEM_H


#include <memory>
#include "Declaration.h"


class Game;

/**
 *
 * Base class for items in the Game
 */
class Item
{
private:

    Game *mGame;

    // Item location in the game;

    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item

    /// The underlying item image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap we can display for this item
    std::unique_ptr<wxBitmap> mItemBitmap;
protected:
    Item(Game* game, const std::wstring &filename);



public:

    Item(std::shared_ptr<Declaration>, double x, double y);

    /**
     * Set the item location
     * @param x X location in pixels
     * @param y Y location in pixels
     */
    virtual void SetLocation(double x, double y) { mX = x; mY = y; }

    /// Default constructor (disabled)
    Item() = delete;

    /// Copy constructor (disabled)
    Item(const Item &) = delete;

//    ~Item();

    /**
     * The X location of the item
     * @returns X location in pixels
     */
    double GetX() const { return mX; }

    /**
     * The Y location of the item
     * @returns Y location in pixels
     */
    double GetY() const { return mY; }



    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    virtual bool HitTest(int x, int y);

//    virtual wxXmlNode *XmlSave(wxXmlNode *node);

    /**
     * Get the pointer to the Game object
     * @return Pointer to Game object
     */
    Game *GetGame() { return mGame;  }

    virtual void XmlLoad(wxXmlNode *node) {};

    /**
     * Handle updates for animation
     * @param elapsed The time since the last update
     */
    virtual void Update(double elapsed) {}


    /**
     * Get the width of the bitmap image
     * @return Bitmap width in pixels
     */
    int GetWidth() const { return mItemImage->GetWidth(); }

    /**
     * Get the height of the bitmap image
     * @return Bitmap height in pixels
     */
    int GetHeight() const { return mItemImage->GetHeight(); }

};

#endif //PROJECT1_GAMELIB_ITEM_H
