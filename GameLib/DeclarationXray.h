/**
 * @file DeclarationXray.h
 * @author Joseph Renas
 *
 * Declaration class for xray
 */

#ifndef PROJECT1_GAMELIB_DECLARACTIONXRAY_H
#define PROJECT1_GAMELIB_DECLARACTIONXRAY_H

#include "Declaration.h"

class Game;
class Item;

/**
 * Declaration class for xray
 */
class DeclarationXray : public Declaration {
private:

    /// Capacity of the xray
    int mCapacity;

    /// Image of the xray
    std::wstring mImage;
public:
    std::shared_ptr<Item> Create(wxXmlNode *node, Game *game);
    DeclarationXray(wxXmlNode * node);

    /**
     * Get the image of the xray
     * @return mImage
     */
    std::wstring GetImage() { return mImage; } ///< @returns mImage

    /**
     * Capacity of the xray
     * @return mCapacity
     */
    int GetCapacity() { return mCapacity; }
};

#endif //PROJECT1_GAMELIB_DECLARACTIONXRAY_H
