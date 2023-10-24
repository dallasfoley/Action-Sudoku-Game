/**
 * @file DeclaractionXray.cpp
 * @author Joseph Renas
 */

#include "pch.h"
#include "DeclaractionXray.h"

/**
 * Constructor for class DeclarationXray
 * @param node xmlNode for this declaration
 */
DeclarationXray::DeclarationXray(wxXmlNode *node) :Declaration(node)
{
    node->GetAttribute(L"capacity");
}