/**
 * @file DeclarationNumber.cpp
 * @author Jon Price
 */

#include "pch.h"
#include "DeclarationNumber.h"
#include "Number.h"

/**
 * Constructor for class DeclarationNumber
 * @param node xmlNode for this declaration
 */
DeclarationNumber::DeclarationNumber(wxXmlNode *node) :Declaration(node)
{
    mGiven = node->GetName() == L"given";
    node->GetAttribute(L"value").ToInt(&mValue);
}

/**
 * Create an object of type Number for the item list
 * @param node Item node for this object
 * @param game Game object
 * @return shared ptr to Number
 */
std::shared_ptr<Item> DeclarationNumber::Create(wxXmlNode * node, Game * game)
{
    if (mGiven)
        game->IncrementGameCount();
    return std::make_shared<Number>(this, node);
}