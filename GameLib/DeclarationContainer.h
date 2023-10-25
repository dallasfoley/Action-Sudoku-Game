/**
 * @file DeclarationContainer.h
 * @author Joseph Renas
 *
 *
 */

#ifndef PROJECT1_GAMELIB_DECLARATIONCONTAINER_H
#define PROJECT1_GAMELIB_DECLARATIONCONTAINER_H

#include "Declaration.h"
class Game;
class Item;
/**
 * Decleration class for container
 */
class DeclarationContainer : public Declaration {
private:
    std::wstring mFrontImage;
public:
    DeclarationContainer(wxXmlNode * node);
    std::wstring GetFrontImage() { return mFrontImage;}
    std::shared_ptr<Item> Create(wxXmlNode * node, Game * game) override;
};

#endif //PROJECT1_GAMELIB_DECLARATIONCONTAINER_H
