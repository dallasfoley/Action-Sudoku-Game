/**
 * @file Declaration.cpp
 * @author Jon Price
 */


#include "pch.h"
#include "Declaration.h"
#include "Item.h"
#include "Game.h"


Declaration::Declaration(wxXmlNode * node)
{
    mID = node->GetAttribute(L"id", L"i000");
    node->GetAttribute(L"width").ToDouble(&mWidth);
    node->GetAttribute(L"height").ToDouble(&mHeight);
    mImage = L"images/" + node->GetAttribute(L"image", L"");
}

Declaration::Declaration(wxXmlNode * node, wxString image)
{
    // Declaration for Sparty, who has 2 images which do not have labels consistent with the rest of the declarations.
    mID = node->GetAttribute(L"id", L"i000");
    node->GetAttribute(L"width").ToDouble(&mWidth);
    node->GetAttribute(L"height").ToDouble(&mHeight);
    mImage = image;
}

std::shared_ptr<Item> Declaration::Create(wxXmlNode *node, Game * game)
{
    return std::make_shared<Item>(this, node);
}