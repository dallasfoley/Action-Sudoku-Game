/**
 * @file DeclaractionXray.cpp
 * @author Joseph Renas
 */

#include "pch.h"
#include "DeclarationXray.h"
#include "Item.h"

/**
 * Constructor for class DeclarationXray
 * @param node xmlNode for this declaration
 */
DeclarationXray::DeclarationXray(wxXmlNode *node) :Declaration(node)
{
    node->GetAttribute(L"capacity");
}

/**
* create xray Item
*/
std::shared_ptr<Item> DeclarationXray::Create(wxXmlNode *node, Game *game)
{
    return std::make_shared<Item>(this, node);
}