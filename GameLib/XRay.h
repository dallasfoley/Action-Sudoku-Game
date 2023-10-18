/**
 * @file XRay.h
 * @author Jon Price
 */

#ifndef PROJECT1_XRAY_H
#define PROJECT1_XRAY_H

#include "Item.h"

class XRay {
private:
    std::vector<std::shared_ptr<Item>> mItems;
public:
    /** Adds item to mItems, provided there is room in the vector
     * @param item to add to vector
     * @returns true if the item is added
     */
    bool AddItem(std::shared_ptr<Item> item);



};


#endif //PROJECT1_XRAY_H
