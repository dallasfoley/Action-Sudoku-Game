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
 * Base class for items in the Game
 */
class Item
{
private:

    /// The game this item is contained in
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

    /**
     * Set the X location of the item
     * @param x X location in pixels
     */
    void SetX(double x) { mX = x; }

    /**
     * Set the Y location of the item
     * @param y Y location in pixels
     */
    void SetY(double y) { mY = y; }

public:

    /**
     * Set the landing point for the item
     * @param x
     * @param y
     */
    virtual void SetLandingPoint(double x, double y) {};

    /**
     * Consume the item
     */
    virtual void Eat() {};

    /**
     * Headbutt the item
     */
    virtual void Headbutt() {};

    /**
     * Get the value of the item
     * @return 10 (default)
     */
    virtual int GetValue() { return 10;}

    Item(std::shared_ptr<Declaration> d, double x, double y);

    Item(Declaration * declaration, wxXmlNode * node);

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

    /**
     * Handle updates for animation
     * @param elapsed The time since the last update
     */
    virtual void Update(double elapsed) {}

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

    /**
     * Add item to the xray
     * @param item
     */
    virtual void AddItem(std::shared_ptr<Item> item) {};

    /**
     * Regurgitate numbers
     * @param game
     * @param event
     * @param x
     * @param y
     * @param board
     * @return false
     */
    virtual bool Regurgitate(Game * game, wxKeyEvent & event, double x, double y, std::shared_ptr<Board> board) { return false; }

    /**
     * Decrement the count of the item
     */
    virtual void DecrementCount() {};

    /**
     * Get the speed of the item
     * @return 0 (default)
     */
    virtual double GetSpeed() const {return 0;};

    /**
     * Set the speed of the item
     * @param speed
     */
    virtual void SetSpeed(double speed) {};

    /**
     * Change speed of the item
     * @return 0 (default)
     */
    virtual void AffectSparty() {};

    /**
     * Checks if the item has capacity
     * @return false (default)
     */
    virtual bool HasCapacity() { return false; }

    /**
     * Get the count of the item
     * @return 0 (default)
     */
    virtual int GetCount() {return 0;}

    /**
     * Increment the count of the item
     */
    virtual void IncrementCount() {};

    /**
     * Load the item from XML
     * @param node
     */
    virtual void XmlLoad(wxXmlNode *node) {};
};

#endif //PROJECT1_GAMELIB_ITEM_H
