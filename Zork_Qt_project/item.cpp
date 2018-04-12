#include "item.h"

/**
 * @brief Item::Item
 * Sets the Items description as the string parameter
 * @param inDescription string to set the items description as.
 */
Item::Item(string inDescription) {
    description = inDescription;
    setProperties();
}

/**
 * @brief Item::Item default constructor setting the item as 'Untitled'
 */
Item::Item() {
    description = "Untitled";
    setProperties();
}

Item::~Item() {
}

/**
 * @brief Item::isCarryable boolean function returning if the item can be carried or not
 * @return
 */
bool Item::isCarryable(){
    return carryable;
}

/**
 * @brief Item::isSearchable boolean function returning if the item can be searched or not
 * @return
 */
bool Item::isSearchable(){
    return searchable;
}

/**
 * @brief Item::getShortDescription returns the description of the item.
 * @return
 */
string Item::getShortDescription(){
    return description;
}

string Item::getLongDescription(){
    return " item(s), " + description + ".\n";
}

/**
 * @brief Item::setProperties sets the if the item is carryable and if its searchable
 */
void Item::setProperties(){
    carryable = false;
    searchable = false;
}
