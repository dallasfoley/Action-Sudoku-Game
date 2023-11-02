/**
 * @file Container.h
 * @author Dallas Foley
 *
 * Base class for containers in the game
 */

#ifndef PROJECT1_GAMELIB_CONTAINER_H
#define PROJECT1_GAMELIB_CONTAINER_H
#include "Item.h"
#include "Game.h"
#include "DeclarationContainer.h"

/**
 *
 * Base class for containers in the game
 */
class Container : public Item
{
private:
    /// The underlying item image
    std::unique_ptr<wxImage> mItemFrontImage;

    /// The bitmap we can display for this item
    std::unique_ptr<wxBitmap> mItemFrontBitmap;

    /// Vector of stored Items
    std::vector<std::shared_ptr<Item>> mItems;
public:

    void Release(Game * game) override;
    Container(DeclarationContainer * declaration, wxXmlNode * node, Game * mGame);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitContainer(this); }
};

#endif //PROJECT1_GAMELIB_CONTAINER_H
