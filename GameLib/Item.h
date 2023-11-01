/**
 * @file Item.h
 * @author rohch
 * @author Jon Price
 * @author Dallas Foley
 * This file contains the declaration of the Item class
 * which represents an item in the game
 */

#ifndef PROJECT1_GAMELIB_ITEM_H
#define PROJECT1_GAMELIB_ITEM_H


#include <memory>
#include "Declaration.h"
#include "DeclarationNumber.h"
#include "ItemVisitor.h"


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

    void SetX(double x) { mX = x; } ///< @param x is new mX
    void SetY(double y) { mY = y; } ///< @param y is new mY

public:

    virtual void SetLandingPoint(double x, double y) {};

    virtual void Eat() {};

    virtual void Headbutt() {};

    virtual int GetValue() { return 10;}

    Item(std::shared_ptr<Declaration> d, double x, double y);

    Item(Declaration * d, wxXmlNode * node);

    /**
     * Set the item location
     * @param x X location in pixels
     * @param y Y location in pixels
     */
    virtual void SetLocation(double x, double y) { mX = x; mY = y; }

    /// Default constructor (disabled)
    Item() = default;

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

    virtual bool HitTest(double x, double y);

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

    /**
     * Accept a visitor
      * @param visitor The visitor we accept
      */
    virtual void Accept(ItemVisitor* visitor) {};

    /**
     * Release numbers
     * @param game pointer to Game
     */
    virtual void Release(Game * game) {};

    virtual void AddItem(std::shared_ptr<Item> item) {};

    virtual void Regurgitate(Game * game, wxKeyEvent & event, double x, double y, std::shared_ptr<Board> board) {};

    virtual int GetCount() {return 0;}

    virtual void IncrementCount() {};

    virtual void DecrementCount() {};
};

#endif //PROJECT1_GAMELIB_ITEM_H
