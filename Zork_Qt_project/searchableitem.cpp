#include "searchableitem.h"


searchableItem::searchableItem(){
    setProperties();
}
searchableItem::~searchableItem(){
    for(int i =0; i < storedItems.size(); i++){
        delete storedItems[i];
    }
}
searchableItem::searchableItem(string description){
    this->description = description;
    setProperties();
}
void searchableItem::setProperties(){
    carryable = false;
    searchable = true;
    validRoomCommands = {"search"};
}
void searchableItem::insertItem(carryableItem *item){
    storedItems.push_back(item);
    item = NULL;
}
vector<string> searchableItem:: validRoomCommandsList(){
    return validRoomCommands;
}
vector<string> searchableItem:: validUserCommandsList(){
    return validUserCommands;
}
int searchableItem:: getNumberOfStoredItems(){
    return storedItems.size();
}

void searchableItem::transferItemsToCharacter(Character *user){
    if(storedItems.size() > 0){
      for(int i =0; i < storedItems.size(); i++){
            user->addItem(storedItems[i]);
        }
        storedItems.clear();
    }
}

