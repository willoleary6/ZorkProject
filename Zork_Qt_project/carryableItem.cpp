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
void carryableItem::setProperties(){
    carryable = true;
    searchable = false;

}

