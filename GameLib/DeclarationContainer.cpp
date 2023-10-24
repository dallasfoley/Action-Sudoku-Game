/**
 * @file DeclarationContainer.cpp
 * @author Joseph Renas
 */

#include "pch.h"
#include "DeclarationContainer.h"

/**
 * Constructor for class DeclarationContainer
 * @param node xmlNode for this declaration
 */
DeclarationContainer::DeclarationContainer(wxXmlNode * node) : Declaration(node)
{
    mFrontImage = L"images/" + node->GetAttribute(L"front", L"");
}