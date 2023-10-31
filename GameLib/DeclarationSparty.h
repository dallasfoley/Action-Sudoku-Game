/**
 * @file DeclarationSparty.h
 * @author Jon Price
 */

#ifndef PROJECT1_DECLARATIONSPARTY_H
#define PROJECT1_DECLARATIONSPARTY_H

#include "Declaration.h"
#include "Sparty.h"

/**
 * Declaration class for sparty
 */
class DeclarationSparty : public Declaration {
private:
    /// Sparty head image
    std::wstring mHeadImage;
    /// Sparty jaw image
    std::wstring mJawImage;
    /// Head pivot angle
    double mHeadPivotAngle;
    /// Head pivotX
    double mHeadPivotX;
    /// Head pivotY
    double mHeadPivotY;
    /// Mouth pivot angle
    double mMouthPivotAngle;
    /// Mouth pivotX
    double mMouthPivotX;
    /// Mouth pivotY
    double mMouthPivotY;
    /// TargetX
    double mTargetX;
    /// TargetY
    double mTargetY;
public:
    /**
     * Sparty head image.
     * @return mHeadImage.
     */
    const std::wstring &getHeadImage() const { return mHeadImage;}
    /**
     * Sparty jaw image.
     * @return mJawImage.
     */
    const std::wstring &getJawImage() const { return mJawImage;}
    /**
     * Head pivot angle.
     * @return mHeadPivotAngle.
     */
    double getHeadPivotAngle() const {return mHeadPivotAngle;}
    /**
     * Head pivotX.
     * @return mHeadPivotX.
     */
    double getHeadPivotX() const {return mHeadPivotX;}
    /**
     * Head pivotY.
     * @return mHeadPivotY.
     */
    double getHeadPivotY() const {return mHeadPivotY;}
    /**
     * Mouth pivot angle.
     * @return mMouthPivotAngle.
     */
    double getMouthPivotAngle() const {return mMouthPivotAngle;}
    /**
     * Mouth pivotX.
     * @return mMouthPivotX.
     */
    double getMouthPivotX() const {return mMouthPivotX;}
    /**
     * Mouth pivotY.
     * @return mMouthPivotY.
     */
    double getMouthPivotY() const {return mMouthPivotY;}
    /**
     * TargetX.
     * @return mTargetX.
     */
    double getTargetX() const {return mTargetX;}
    /**
     * TargetY.
     * @return mTargetY.
     */
    double getTargetY() const {return mTargetY;}

    DeclarationSparty(wxXmlNode * node);
    std::shared_ptr<Item> Create(wxXmlNode * node, Game * game) override;
};


#endif //PROJECT1_DECLARATIONSPARTY_H
