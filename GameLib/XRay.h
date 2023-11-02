/**
 * @file XRay.h
 * @author Jon Price
 *
 * Base class for XRay in the Game
 */

#ifndef PROJECT1_XRAY_H
#define PROJECT1_XRAY_H

#include "Item.h"
#include "Game.h"
#include "DeclarationXray.h"
#include <wx/graphics.h>
#include "Number.h"
#include <memory>

/**
 * Base class for Xray in the Game
 */
class XRay : public Item {
private:

    /// Vector of items in the XRay
    std::vector<std::shared_ptr<Item>> mNumbers;

    /// Image for the XRay
    std::unique_ptr<wxImage> mImage;

    /// Bitmap for the XRay
    std::unique_ptr<wxBitmap> mBitmap;

    /// X position of the XRay
    double mX;

    /// Y position of the XRay
    double mY;

    /// Game context
    Game * mGame;

    /// Number of items that can be stored in the XRay
    int mCapacity;

public:
    XRay(DeclarationXray * declaration, wxXmlNode * node, Game * mGame);
    ~XRay();

    void AddItem(std::shared_ptr<Item> item) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    bool Regurgitate(Game * game, wxKeyEvent & event, double x, double y, std::shared_ptr<Board> board) override;
    bool RemoveItem(std::shared_ptr<Item> item);
    void Clear();

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitXRay(this); }

    /**
     * @return the capacity of the xray
     */
    bool HasCapacity() override { return mCapacity > mNumbers.size(); }
};


#endif //PROJECT1_XRAY_H
