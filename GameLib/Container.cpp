/**
 * @file Container.cpp
 * @author Dallas Foley
 * @author Jon Price
 */


#include "pch.h"
#include "Container.h"
#include <random>
using namespace std;


/**
 * Draws the container
 * @param graphics the graphics context to draw on
 */
void Container::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    Item::Draw(graphics);
    for(auto item : mItems)
    {
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

/**
 * Creates a container from an xml node
 * @param dec the declaration container
 * @param node the xml node
 * @param mGame the game to update
 */
Container::Container(DeclarationContainer * dec, wxXmlNode * node, Game * mGame) : Item(dec, node)
{
    mItemFrontImage = make_unique<wxImage>(dec->GetFrontImage(), wxBITMAP_TYPE_ANY);
    mItemFrontBitmap = make_unique<wxBitmap>(*mItemFrontImage);
    auto child = node->GetChildren();
    for(; child; child = child->GetNext())
    {
        auto i = mGame->XmlItem(child);
        mItems.push_back(i);
    }
}

/**
 * Releases items from the container
 * @param game the game to update
 */
void Container::Release(Game * game)
{
    std::uniform_real_distribution<> releaseDistribution(0, game->GetTileHit()*4);
    for (auto item: mItems)
    {

        double x = GetX() + releaseDistribution(game->GetRandom());
        double y = GetY() - releaseDistribution(game->GetRandom()) - game->GetTileHit() * 2;
        item->SetLocation(x,y);
        game->AddItem(item);
    }
    mItems.clear();
}