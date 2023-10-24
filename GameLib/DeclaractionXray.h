/**
 * @file DeclaractionXray.h
 * @author Joseph Renas
 *
 *
 */

#ifndef PROJECT1_GAMELIB_DECLARACTIONXRAY_H
#define PROJECT1_GAMELIB_DECLARACTIONXRAY_H

#include "Declaration.h"

/**
 * Decleration class for xray
 */
class DeclarationXray : public Declaration {
private:
    int mCapacity;
public:
    DeclarationXray(wxXmlNode * node);
    int GetCapacity() { return mCapacity; } ///< @returns mCapacity
};

#endif //PROJECT1_GAMELIB_DECLARACTIONXRAY_H
