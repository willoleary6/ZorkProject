#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "item.h"

#include <string>
#include <vector>
using namespace std;

using std::vector;


class Character {
private:
	string description;
    vector <Item*> itemsInCharacter;
public:
    vector <Item*> getItemList();
    void addItem(Item* item);
    Character(string description);
    Character();
    string shortDescription();
	string longDescription();
    Item* removeItem(int itemIndex);
    int isItemOnCharacter(string inString);

};

#endif
