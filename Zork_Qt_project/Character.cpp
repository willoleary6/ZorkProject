#include "Character.h"

/**
 * @brief Character::Character
 * Default contructor that sets the users description as player
 */
Character::Character(){
    this->description = "Player";
}

/**
 * @brief Character::Character
 * @param description string parameter setting the users description
 */
Character::Character(string description) {
	this->description = description;
}

/**
 * @brief Character::~Character
 * Destructor that clears the items stored on the user.
 */
Character::~Character() {
    for(int i =0; i < itemsInCharacter.size(); i++){
        delete itemsInCharacter[i];
    }
}

/**
 * @brief Character::addItem adds a item to the users inventory
 * @param item
 */
void Character::addItem(Item* item) {
    itemsInCharacter.push_back(item);
}

/**
 * @brief Character::shortDescription
 * @return returns a string of the users description
 */
string Character::shortDescription(){
    return  this->description;
}

/**
 * @brief Character::removeItem
 * @param itemIndex index of the item we are taking on the inventory vector
 * @return returns an item from the user, used when droping an item or using it
 */
Item* Character::removeItem(int itemIndex){
    //take the item from the users inventory and return it
    Item *Temp = itemsInCharacter.at(itemIndex);
    itemsInCharacter.erase(itemsInCharacter.begin() + itemIndex);
    return Temp;
}

/**
 * @brief Character::getItemList
 * @return returns the vector of items stored in the users inventory
 */
vector <Item*> Character::getItemList(){
    //return the vector containing
    return itemsInCharacter;
 }

/**
 * @brief Character::longDescription
 * @return returns a string containing the users inventory and a list of the items on the user.
 */
string Character::longDescription(){
    string ret = this->description;
    ret += "\n Item list:\n";
    for (vector<Item*>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++){
        ret += "\t"+ (*i)->getLongDescription() + "\n";
    }
    return ret;
}

/**
 * @brief Character::isItemOnCharacter
 * @param inString string containing the name of the item we are searching for
 * @return returns the index of the item if it is on the user, if not it returns -1
 */
int Character::isItemOnCharacter(string inString){
    int sizeItems = (itemsInCharacter.size());
    if (itemsInCharacter.size() < 1) {
        return -1;
    }else if (itemsInCharacter.size() > 0) {
        int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInCharacter[x]->getShortDescription());
            if (tempFlag == 0) {
                return x;
            }
            x++;
        }
    }
    return -1;
}
