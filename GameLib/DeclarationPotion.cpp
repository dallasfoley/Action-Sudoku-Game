/**
 * @file DeclarationPotion.cpp
 * @author rohch
 */

#include "pch.h"
#include "DeclarationPotion.h"
#include "SpeedPotion.h"

/**
 * Constructor for class DeclarationPotion
 * @param node
 */
DeclarationPotion::DeclarationPotion(wxXmlNode *node) : Declaration(node)
{

}

/**
 * Create an object of type SpeedPotion for the item list
 * @param node Item node for this object
 * @return shared ptr to SpeedPotion
 */
std::shared_ptr<Item> DeclarationPotion::Create(wxXmlNode * node, Game * game)
{
    return std::make_shared<SpeedPotion>(this, node, game);
}

