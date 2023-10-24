/**
 * @file DeclarationContainer.h
 * @author Joseph Renas
 *
 *
 */

#ifndef PROJECT1_GAMELIB_DECLARATIONCONTAINER_H
#define PROJECT1_GAMELIB_DECLARATIONCONTAINER_H

#include "Declaration.h"

/**
 * Decleration class for container
 */
class DeclarationContainer : public Declaration {
private:
    std::wstring mFrontImage;
protected:
    DeclarationContainer(wxXmlNode * node);
public:
    std::wstring GetImage() { return mFrontImage;}
};

#endif //PROJECT1_GAMELIB_DECLARATIONCONTAINER_H
