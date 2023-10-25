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
 * @param given whether the number is a given or a digit
 */
DeclarationNumber::DeclarationNumber(wxXmlNode *node) :Declaration(node)
{
    mGiven = node->GetName() == L"given";
    node->GetAttribute(L"value");
}

std::shared_ptr<Item> DeclarationNumber::Create(wxXmlNode * node, Game * game)
{
    return std::make_shared<Number>(this, node);
}