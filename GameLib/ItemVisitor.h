/**
 * @file ItemVisitor.h
 * @author Dallas Foley
 *
 *
 */

#ifndef PROJECT1_PROJECT1_GAMELIB_ITEMVISITOR_H
#define PROJECT1_PROJECT1_GAMELIB_ITEMVISITOR_H
class Container;
class Number;
class Board;
class XRay;
class Scoreboard;
class Sparty;
class SpeedPotion;
class Item;

class ItemVisitor
{
private:

protected:
    ItemVisitor() {}
public:
    virtual ~ItemVisitor() {}

    /**
     * Visit a Container object
     * @param container Container object we are visiting
     */
    virtual void VisitContainer(Container* container) {}

    /**
     * Visit a Number object
     * @param number Number object we are visiting
     */
    virtual void VisitNumber(Number* number) {}

    /**
     * Visit a Number object
     * @param number Number object we are visiting
     */
    virtual void VisitBoard(Board* board) {}

    /**
     * Visit a Number object
     * @param number Number object we are visiting
     */
    virtual void VisitXRay(XRay* xray) {}

    /**
     * Visit a Number object
     * @param number Number object we are visiting
     */
    virtual void VisitScoreboard(Scoreboard* scoreboard) {}

    /**
     * Visit a Number object
     * @param number Number object we are visiting
     */
    virtual void VisitSparty(Sparty* sparty) {}

    /**
     * Visit a Number object
     * @param number Number object we are visiting
     */
    virtual void VisitPotion(SpeedPotion* potion) {}

};

#endif //PROJECT1_PROJECT1_GAMELIB_ITEMVISITOR_H
