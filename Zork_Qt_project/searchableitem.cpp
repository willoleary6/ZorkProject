#include "searchableitem.h"


searchableItem::searchableItem(){
    setProperties();
}
searchableItem::searchableItem(string description){
    this->description = description;
    setProperties();
}
void searchableItem::setProperties(){
    carryable = false;
    searchable = true;
}
void searchableItem::insertItem(carryableItem *item){
    storedItems.push_back(item);
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

