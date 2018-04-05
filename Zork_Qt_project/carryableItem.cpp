#include "carryableItem.h"

carryableItem::carryableItem(){
    setProperties();
}
carryableItem::~carryableItem(){
}
carryableItem::carryableItem(string description){
    this->description = description;
    setProperties();
}
vector<string> Item::validRoomCommandsList(){
    return validRoomCommands;
}
vector<string> Item::validUserCommandsList(){
    return validUserCommands;
}
void carryableItem::setProperties(){
    carryable = true;
    searchable = false;
    validRoomCommands = {"take"};
    validUserCommands = {"drop"};
}

