/**
  * @file Number.cpp
  * @author Chirag Solanki
  * @author Jon Price
 */

#include "pch.h"
#include "Number.h"
#include "DeclarationNumber.h"

using namespace std;

/**
 * Constructor for Number class
 * @param dec
 * @param node
 */
Number::Number(DeclarationNumber * dec, wxXmlNode * node) : Item(dec, node)
{
    mValue = dec->GetValue();
    mIsGiven = dec->GetGiven();
}

/**
 * Load the number from xml file
 * @param node
 */
void Number::XmlLoad(wxXmlNode *node)
{
    double x;
    node->GetAttribute(L"col").ToDouble(&x);
    double y;
    node->GetAttribute(L"row").ToDouble(&y);
    SetLocation(x, y);
}