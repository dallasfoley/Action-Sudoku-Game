/**
 * @file Container.cpp
 * @author Dallas Foley
 * @author Jon Price
 */

#include "pch.h"
#include "Container.h"
using namespace std;


void Container::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    Item::Draw(graphics);
    for(auto item : mItems) {
        item->Draw(graphics);
    }
    double wid = mItemFrontBitmap->GetWidth();
    double hit = mItemFrontBitmap->GetHeight();
    graphics->DrawBitmap(*mItemFrontBitmap,
                         (GetX()),
                         (GetY() - hit),
                         wid,
                         hit);
}

Container::Container(DeclarationContainer * dec, wxXmlNode * node, Game * mGame) : Item(dec, node)
{
    mItemFrontImage = make_unique<wxImage>(dec->GetImage(), wxBITMAP_TYPE_ANY);
    mItemFrontBitmap = make_unique<wxBitmap>(*mItemFrontImage);
    auto child = node->GetChildren();
    for(; child; child = child->GetNext())
    {
        auto i = mGame->XmlItem(child);
        mItems.push_back(i);
    }
}