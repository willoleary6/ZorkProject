#include "carryableItem.h"

// Constructors
carryableItem::carryableItem(){
    setProperties();
}
carryableItem::~carryableItem(){
}
carryableItem::carryableItem(string description){
    this->description = description;
    setProperties();
}
// Using the virtual functions
vector<string> Item::validRoomCommandsList(){
    return validRoomCommands;
}
vector<string> Item::validUserCommandsList(){
    return validUserCommands;
}
// Polymorphism
void carryableItem::setProperties(){
    carryable = true;
    searchable = false;
    validRoomCommands = {"take"};
    validUserCommands = {"drop"};
}

