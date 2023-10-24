/**
 * @file Declaration.h
 * @author Jon Price
 */

#ifndef PROJECT1_DECLARATION_H
#define PROJECT1_DECLARATION_H

class Item;

/**
 * Base class for declarations within XML
 */
class Declaration {
private:
    std::wstring mID;
    double mWidth;
    double mHeight;
    std::wstring mImage;
protected:
    Declaration(wxXmlNode * node, wxString image);
public:
    Declaration(wxXmlNode * node);
    virtual std::shared_ptr<Item> Create(wxXmlNode * node);
    std::wstring GetID() { return mID; };
    double GetWidth() { return mWidth; };
    double GetHeight() { return mHeight; };
    std::wstring GetImage() { return mImage;}
};


#endif //PROJECT1_DECLARATION_H
