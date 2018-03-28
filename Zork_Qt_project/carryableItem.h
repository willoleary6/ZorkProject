#ifndef CARRYABLEITEM_H
#define CARRYABLEITEM_H
#include "item.h"

class carryableItem: public Item
{
public:
    //testing
    carryableItem();
    carryableItem(string description);
protected:
    void setProperties();

};

#endif // CARRYABLEITEM_H
