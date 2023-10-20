/**
 * @file DeclarationSparty.h
 * @author Jon Price
 */

#ifndef PROJECT1_DECLARATIONSPARTY_H
#define PROJECT1_DECLARATIONSPARTY_H

#include "Declaration.h"

/**
 * Decleration class for sparty
 */
class DeclarationSparty : public Declaration {
private:
    std::wstring mHeadImage;
    std::wstring mJawImage;
    double mHeadPivotAngle;
    double mHeadPivotX;
    double mHeadPivotY;
    double mMouthPivotAngle;
    double mMouthPivotX;
    double mMouthPivotY;
    double mTargetX;
    double mTargetY;
public:
    DeclarationSparty(wxXmlNode * node);
};


#endif //PROJECT1_DECLARATIONSPARTY_H
