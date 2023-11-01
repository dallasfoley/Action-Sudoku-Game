/**
 * @file DeclarationPotion.cpp
 * @author rohch
 */

#include "pch.h"
#include "DeclarationPotion.h"
#include "SpeedPotion.h"

/**
 * Constructor for class DeclarationPotion
 * @param node xmlNode for this declaration
 */
DeclarationPotion::DeclarationPotion(wxXmlNode *node) : Declaration(node)
{

}

std::shared_ptr<Item> DeclarationPotion::Create(wxXmlNode * node, Game * game)
{
    return std::make_shared<SpeedPotion>(this, node, game);
}