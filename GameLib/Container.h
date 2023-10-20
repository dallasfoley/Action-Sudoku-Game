/**
 * @file Container.h
 * @author Dallas Foley
 *
 *
 */

#ifndef PROJECT1_GAMELIB_CONTAINER_H
#define PROJECT1_GAMELIB_CONTAINER_H
#include "Item.h"
#include "Game.h"

/**
 *
 * Base class for containers in the game
 */
class Container : public Item
{
private:
    /// The game associated with this container
    Game* mGame;

    /// Boolean value denote if object is a cauldron or pumpkin
    bool mIsCauldron;
public:
    Container(Game* game, const std::wstring &filename);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
};

#endif //PROJECT1_GAMELIB_CONTAINER_H
