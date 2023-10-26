/**
 * @file XRay.h
 * @author Jon Price
 */

#ifndef PROJECT1_XRAY_H
#define PROJECT1_XRAY_H

#include "Item.h"
#include "Game.h"
#include <wx/graphics.h>
#include "Number.h"
#include <memory>

/**
 * Base class for Xray in the Game
 */
class XRay {
private:

    /// Vector of items in the XRay
    std::vector<std::shared_ptr<Item>> mNumbers;

    /// Image for the XRay
    std::unique_ptr<wxImage> mImage;

    /// Bitmap for the XRay
    std::unique_ptr<wxBitmap> mBitmap;

    /// X position of the XRay
    double mX = 20;

    /// Y position of the XRay
    double mY = 560;

    /// Game context
    Game * mGame;

public:
    XRay(Game *game);
    ~XRay();

    /** Adds item to mItems, provided there is room in the vector
     * @param item to add to vector
     * @returns true if the item is added
     */
    bool AddItem(std::shared_ptr<Item> item);

    void Update(double elapsed);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    int GetNumItems();
    void DisplayNumbers();
    bool RemoveItem(std::shared_ptr<Item> item);
};


#endif //PROJECT1_XRAY_H
