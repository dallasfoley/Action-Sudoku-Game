/**
  * @file Number.h
  * @author Chirag Solanki
  * @author Jon Price
  *
  * The Number class represents an individual digit within the Sudoku game.
 */

# ifndef PROJECT1_NUMBER_H
# define PROJECT1_NUMBER_H

#include "Sparty.h"
#include "Board.h"
#include "Item.h"
#include "DeclarationNumber.h"
#include <utility>

/**
 * Base class for numbers in the Game
 */
class Number : public Item
{
private:

    /// The actual digit mValue ranging from 0 to 8
    int mValue;

    /// Indicates if this number is a given
    bool mIsGiven;

public:

    Number(DeclarationNumber * dec, wxXmlNode * node);

    void XmlLoad(wxXmlNode *node) override;

    /**
     * Get the value of the number
     * @return mValue
     */
    int GetValue() override { return mValue; }

    /**
     * Get the type of the number
     * @return mIsGiven
     */
    bool GetGiven() { return mIsGiven; }

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitNumber(this); }
};

# endif //PROJECT1_NUMBER_H