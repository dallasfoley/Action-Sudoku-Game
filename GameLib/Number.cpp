/**
  * @file Number.cpp
  * @author Chirag Solanki
  * @author Jon Price
 */

#include "pch.h"
#include "Number.h"
#include "DeclarationNumber.h"

using namespace std;

Number::Number(DeclarationNumber * dec, wxXmlNode * node) : Item(dec, node)
{
    mValue = dec->GetValue();
}

void Number::EatenBySparty()
{
    mIsInSpartyStomach = true;
    // Set mPosition to undefined or a special mValue if required.
}

void Number::RegurgitatedBySparty()
{
    mIsInSpartyStomach = false;
    // Update mPosition or other attributes if required.
}

void Number::PlaceInContainer()
{
    mIsInContainer = true;
    // Update mPosition or other attributes if required.
}

void Number::ReleaseFromContainer()
{
    mIsInContainer = false;
    // Update mPosition or other attributes if required.
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