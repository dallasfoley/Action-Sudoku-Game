/**
 * @file DeclarationXray.h
 * @author Joseph Renas
 *
 *
 */

#ifndef PROJECT1_GAMELIB_DECLARACTIONXRAY_H
#define PROJECT1_GAMELIB_DECLARACTIONXRAY_H

#include "Declaration.h"

class Game;
class Item;

/**
 * Decleration class for xray
 */
class DeclarationXray : public Declaration {
private:
    int mCapacity;
    std::wstring mImage;
public:
    std::shared_ptr<Item> Create(wxXmlNode *node, Game *game);
    DeclarationXray(wxXmlNode * node);
    std::wstring GetImage() { return mImage; } ///< @returns mImage
    int GetCapacity() { return mCapacity; } ///< @returns mCapacity
};

#endif //PROJECT1_GAMELIB_DECLARACTIONXRAY_H
