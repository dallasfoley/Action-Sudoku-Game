/**
 * @file Declaration.cpp
 * @author Jon Price
 */


#include "pch.h"
#include "Declaration.h"


Declaration::Declaration(wxXmlNode * node)
{
    mID = node->GetAttribute(L"id", L"i000");
    node->GetAttribute(L"width").ToDouble(&mWidth);
    node->GetAttribute(L"height").ToDouble(&mHeight);
    mImage = L"images/" + node->GetAttribute(L"image", L"");
}