#ifndef SEARCHABLEITEM_H
#define SEARCHABLEITEM_H
#include "item.h"
#include "carryableItem.h"
#include "Character.h"
#include <unistd.h>
#include <vector>

class searchableItem: public Item
{
public:
    searchableItem();
    searchableItem(string description);
    void insertItem(carryableItem item);
    void search(Character *user);
private:
    void transferItemsToCharacter(Character *user);
    void setProperties();
    vector <Item> storedItems;
};

#endif // SEARCHABLEITEM_H
