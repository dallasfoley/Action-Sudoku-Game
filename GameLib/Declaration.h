/**
 * @file Declaration.h
 * @author Jon Price
 */

#ifndef PROJECT1_DECLARATION_H
#define PROJECT1_DECLARATION_H

class Item;
class Game;
/**
 * Base class for declarations within XML
 */
class Declaration {
private:
    /// ID of the declaration
    std::wstring mID;
    /// Width of the declaration
    double mWidth;
    /// Height of the declaration
    double mHeight;
    /// PNG of the declaration
    std::wstring mImage;
protected:
    Declaration(wxXmlNode * node, wxString image);
public:
    Declaration(wxXmlNode * node);
    virtual std::shared_ptr<Item> Create(wxXmlNode * node, Game * game);
    /**
     * ID of the declaration.
     * @return mID.
     */
    std::wstring GetID() { return mID; };
    /**
     * Width of the declaration.
     * @return mWidth.
     */
    double GetWidth() const { return mWidth; };
    /**
     * Height of the declaration.
     * @return mHeight.
     */
    double GetHeight() const { return mHeight; };
    /**
     * PNG of the declaration.
     * @return mImage.
     */
    std::wstring GetImage() { return mImage;}
};


#endif //PROJECT1_DECLARATION_H
