/**
 * @file DeclarationContainer.cpp
 * @author Joseph Renas
 */

#include "pch.h"
#include "DeclarationContainer.h"
#include "Container.h"
#include "Game.h"

/**
 * Constructor for class DeclarationContainer
 * @param node xmlNode for this declaration
 */
DeclarationContainer::DeclarationContainer(wxXmlNode * node) : Declaration(node)
{
    mFrontImage = L"images/" + node->GetAttribute(L"front", L"");
}

/**
 * Create an object of type Container for the item list
 * @param node Item node for this object
 * @return shaerd ptr to Container
 */
std::shared_ptr<Item> DeclarationContainer::Create(wxXmlNode * node, Game * game)
{
    return std::make_shared<Container>(this, node, game);
}