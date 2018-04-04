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
    ~searchableItem();
    searchableItem(string description);
    void insertItem(carryableItem *item);
    void transferItemsToCharacter(Character *user);
    vector<string> validRoomCommandsList();

private:

    void setProperties();
    vector <Item*> storedItems;
};

#endif // SEARCHABLEITEM_H
