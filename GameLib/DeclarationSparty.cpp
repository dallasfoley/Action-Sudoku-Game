/**
 * @file DeclarationSparty.cpp
 * @author Jon Price
 */

#include "pch.h"
#include "DeclarationSparty.h"

DeclarationSparty::DeclarationSparty(wxXmlNode * node) : Declaration(node)
{
    node->GetAttribute(L"head-pivot-angle", L"0").ToDouble(&mHeadPivotAngle);
    node->GetAttribute(L"head-pivot-x", "0").ToDouble(&mHeadPivotX);
    node->GetAttribute(L"head-pivot-y", "0").ToDouble(&mHeadPivotY);
    node->GetAttribute(L"mouth-pivot-angle", L"0").ToDouble(&mMouthPivotAngle);
    node->GetAttribute(L"mouth-pivot-x", L"0").ToDouble(&mMouthPivotX);
    node->GetAttribute(L"mouth-pivot-y", L"0").ToDouble(&mMouthPivotY);
    node->GetAttribute(L"target-x", L"0").ToDouble(&mTargetX);
    node->GetAttribute(L"target-y", L"0").ToDouble(&mTargetY);
}