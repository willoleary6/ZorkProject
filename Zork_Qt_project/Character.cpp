#include "Character.h"

Character::Character(){
    this->description = "Player";
}

Character::Character(string description) {
	this->description = description;
}


void Character::addItem(Item item) {
    itemsInCharacter.push_back(item);
}

string Character::shortDescription(){
    return  this->description;
}

Item Character::removeItem(int itemIndex){
    Item Temp = itemsInCharacter.at(itemIndex);
    itemsInCharacter.erase(itemsInCharacter.begin() + itemIndex);
    return Temp;
}

string Character::longDescription(){
    string ret = this->description;
    ret += "\n Item list:\n";
    for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++){
        ret += "\t"+ (*i).getLongDescription() + "\n";
    }
    return ret;
}

int Character::isItemOnCharacter(string inString){
    int sizeItems = (itemsInCharacter.size());
    if (itemsInCharacter.size() < 1) {
        return false;
    }else if (itemsInCharacter.size() > 0) {
        int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInCharacter[x].getShortDescription());
            if (tempFlag == 0) {
                return x;
            }
            x++;
        }
    }
    return -1;
}



