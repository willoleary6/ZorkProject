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
    validRoomCommands = {"Search"};
}
void searchableItem::insertItem(carryableItem *item){
    storedItems.push_back(item);
    item = NULL;
}
vector<string> searchableItem:: validRoomCommandsList(){
    return validRoomCommands;
}

void searchableItem::transferItemsToCharacter(Character *user){
    if(storedItems.size() > 0){
        cout << "You found ";
        for(int i =0; i < storedItems.size(); i++){
            cout << storedItems[i]->getShortDescription()<<", ";
            user->addItem(storedItems[i]);
        }
        storedItems.clear();
        cout << endl;
    }else{
        cout << description << " is empty." << endl;
    }
}

