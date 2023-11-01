/**
 * @file DeclarationPotion.h
 * @author rohch
 *
 * class for speed potion declarations
 */

#ifndef PROJECT1_GAMELIB_DECLARATIONPOTION_H
#define PROJECT1_GAMELIB_DECLARATIONPOTION_H

#include "Declaration.h"

class Item;

/**
 * class for speed potion declarations
 */
class DeclarationPotion : public Declaration {
private:

public:
    DeclarationPotion(wxXmlNode * node);
    std::shared_ptr<Item> Create(wxXmlNode * node, Game * game) override;
};


#endif //PROJECT1_GAMELIB_DECLARATIONPOTION_H
