/**
 * @file DeclarationNumber.cpp
 * @author Jon Price
 */

#include "pch.h"
#include "DeclarationNumber.h"
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