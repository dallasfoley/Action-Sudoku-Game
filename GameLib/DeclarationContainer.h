/**
 * @file DeclarationContainer.h
 * @author Joseph Renas
 *
 * Declaration class for container
 */

#ifndef PROJECT1_GAMELIB_DECLARATIONCONTAINER_H
#define PROJECT1_GAMELIB_DECLARATIONCONTAINER_H

#include "Declaration.h"
class Game;
class Item;

/**
 * Declaration class for container
 */
class DeclarationContainer : public Declaration {
private:

    /// Front image of the declaration of the corresponding item
    std::wstring mFrontImage;
public:
    DeclarationContainer(wxXmlNode * node);

    /**
     * Create an object of type Container for the item list
     * @param node Item node for this object
     * @return shaerd ptr to Container
     */
    std::wstring GetFrontImage() { return mFrontImage;}
    std::shared_ptr<Item> Create(wxXmlNode * node, Game * game) override;
};

#endif //PROJECT1_GAMELIB_DECLARATIONCONTAINER_H
