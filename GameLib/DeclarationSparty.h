/**
 * @file DeclarationSparty.h
 * @author Jon Price
 */

#ifndef PROJECT1_DECLARATIONSPARTY_H
#define PROJECT1_DECLARATIONSPARTY_H

#include "Declaration.h"
#include "Sparty.h"

/**
 * Decleration class for sparty
 */
class DeclarationSparty : public Declaration {
private:
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

    const std::wstring &getJawImage() const { return mJawImage;}

    double getHeadPivotAngle() const {return mHeadPivotAngle;}

    double getHeadPivotX() const {return mHeadPivotX;}

    double getHeadPivotY() const {return mHeadPivotY;}

    double getMouthPivotAngle() const {return mMouthPivotAngle;}

    double getMouthPivotX() const {return mMouthPivotX;}

    double getMouthPivotY() const {return mMouthPivotY;}

    double getTargetX() const {return mTargetX;}

    double getTargetY() const {return mTargetY;}

    DeclarationSparty(wxXmlNode * node);
    std::shared_ptr<Item> Create(wxXmlNode * node, Game * game) override;
};


#endif //PROJECT1_DECLARATIONSPARTY_H
