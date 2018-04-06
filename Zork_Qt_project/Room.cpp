#include "Room.h"

/**
 * @brief Room::Room
 * @param description
 * @param IDNumber
 * @param floorId
 * Constructor that is used most often specifing the name of the room,
 * its Id number and the Id number of the floor its on.
 */
Room::Room(string description, int IDNumber, int floorId) {
    this->description = description;
    this->name = description;
    this->IDnumber = IDNumber;
    this->floorId = floorId;
    locked = false;
    //initially we set all exits to null
    nullifyExits();
}

/**
 * @brief Room::Room
 * @param IDNumber
 * @param floorId
 * Barebones contructer that sets its description to that of its ID number
 */
Room::Room(int IDNumber,int floorId) {
    this->description = to_string(IDNumber);
    this->name = to_string(IDNumber);
    this->IDnumber = IDNumber;
    this->floorId = floorId;
    locked = false;
    nullifyExits();
}
/**
 * @brief Room::~Room
 */
Room::~Room(){
    KeyForRoom = NULL;
    for(int i = 0; i < itemsInRoom.size(); i++){
        delete itemsInRoom[i];
    }
}
vector <Item*> Room::getItemsInRoom(){
    return itemsInRoom;
}

/**
 * @brief Room::nullifyExits
 * Initialises exits map
 */
void Room::nullifyExits(){
    exits["north"] = NULL;
    exits["east"] = NULL;
    exits["south"] = NULL;
    exits["west"] = NULL;
    exits["upstairs"] = NULL;
    exits["downstairs"] = NULL;
}

/**
 * @brief Room::getIdNumber
 * @return returns the ID number of the room
 */
int Room::getIdNumber(){
    return IDnumber;
}

/**
 * @brief Room::getFloorID
 * @return Returns the id number of the floor the room is on
 */
int Room::getFloorID(){
    return floorId;
}

/**
 * @brief Room::lockRoom
 * @return
 * Function locks the room and returns the key to the object that called it so it can be unlocked later.
 * Also modifies how the room appears on the map.
 */
key* Room::lockRoom(){
    locked = true;
    KeyForRoom = new key(name,IDnumber,floorId);
    name += "[L]";
    return KeyForRoom;
}

/**
 * @brief Room::isLocked
 * @return boolean status of whether the room is locked or not
 */
bool Room::isLocked(){
    return locked;
}
void Room::setAsCurrentRoom(Room *oldCurrent){
    oldCurrent->ReinitialiseName();
    name = "<"+name+">";
}
void Room::ReinitialiseName(){
    name = description;
    if(this->isLocked()){
        name+="[L]";
    }
    if(exits["upstairs"] != NULL){
        name += "[^]";
    }
    if(exits["downstairs"] != NULL){
        name += "[v]";
    }
}

/**
 * @brief Room::unlockRoom
 * sets the rooms locked status to false and updates how the room appears on the map to reflects this status
 */
void Room::unlockRoom(){
    locked = false;
    name.erase(name.find("[L]"),3);
}

/**
 * @brief Room::getKey
 * @return returns a pointer to the key that matches to this room
 */
key* Room::getKey(){
    return KeyForRoom;
}

/**
 * @brief Room::setExits
 * @param north
 * @param east
 * @param south
 * @param west
 * set the main exits of the room.
 */
void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
    setNorthExit(north);
    setEastExit(east);
    setWestExit(west);
    setSouthExit(south);
}

/**
 * @brief Room::setNorthExit
 * @param north
 */
void Room::setNorthExit(Room *north){
    exits["north"] = north;
}

/**
 * @brief Room::setUpstairsExit
 * @param upstairs
 * adds a stair system to the room allowing the user to go up a floor
 */
void Room::setUpstairsExit(Room *upstairs){
    exits["upstairs"] = upstairs;
    name += "[^]";
}

/**
 * @brief Room::setDownstairsExit
 * @param downstairs
 * adds a stair system to the room allowing the user to go down a floor.
 */
void Room::setDownstairsExit(Room *downstairs){
    exits["downstairs"] = downstairs;
    name += "[v]";
}

/**
 * @brief Room::setEastExit
 * @param east
 */
void Room::setEastExit(Room *east){
    exits["east"] = east;
}

/**
 * @brief Room::setSouthExit
 * @param south
 */
void Room::setSouthExit(Room *south){
    exits["south"] = south;
}

/**
 * @brief Room::setWestExit
 * @param west
 */
void Room::setWestExit(Room *west){
    exits["west"] = west;
}

/**
 * @brief Room::shortDescription
 * @return returns a the description of the room
 */
string Room::shortDescription() {
    return description;
}

/**
 * @brief Room::roomName
 * @return returns the name of the room
 */
string Room::roomName(){
   return name;
}

/**
 * @brief Room::longDescription
 * @return returns the description of the room, all the items stored in it and all the valid exits.
 */
string Room::longDescription() {
    return "room : " + description + ".\n" + displayItem() + exitString()+"\n";
}

/**
 * @brief Room::exitString
 * @return returns all the valid exits of the room.
 */
string Room::exitString() {
    string returnString = "exits: ";
    if (exits["north"] != NULL){
        returnString += " north,";
    }
    if (exits["east"] != NULL){
        returnString += " east,";
    }
    if (exits["south"] != NULL){
        returnString += " south,";
    }
    if (exits["west"] != NULL){
        returnString += " west,";
    }
    if(exits["upstairs"] != NULL){
        returnString += " upstairs,";
    }
    if(exits["downstairs"] != NULL){
        returnString += " downstairs,";
    }
    return returnString+"\n";
}

/**
 * @brief Room::nextRoom
 * @param direction
 * @return returns the room in the direction the user specified.
 */
Room* Room::nextRoom(string direction) {
    map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
        return NULL; // if exits.end() was returned, there's no room in that direction.
    return next->second; // If there is a room, remove the "second" (Room*)
                // part of the "pair" (<string, Room*>) and return it.
}

/**
 * @brief Room::addItem
 * @param inItem
 * adds an item to the itemsInRoom vector.
 */
void Room::addItem(Item *inItem) {
    itemsInRoom.push_back(inItem);
    inItem = NULL;
}

/**
 * @brief Room::displayItem
 * @return returns the descriptions of every item in the room.
 */
string Room::displayItem() {
    string tempString;

    int sizeItems = (itemsInRoom.size());
    int x = (0);
    for (int n = sizeItems; n > 0; n--) {
        tempString = tempString + itemsInRoom[x]->getShortDescription() + "," ;
        x++;
    }
    if(itemsInRoom.size()>0){
        tempString= "items in room : "+tempString+"\n";
    }
    return tempString;
}

/**
 * @brief Room::numberOfItems
 * @return returns the number of items in the room.
 */
int Room::numberOfItems() {
    return itemsInRoom.size();
}

/**
 * @brief Room::isItemInRoom
 * @param inString
 * @return returns the index of a item on the itemsInRoom
 * vector but if the item isnt on the vector the function returns -1.
 */
int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
    }else if (itemsInRoom.size() > 0) {
        int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x]->getShortDescription());
            if (tempFlag == 0) {
                return x;
            }
            x++;
        }
    }
    return -1;
}

/**
 * @brief Room::removeItem
 * @param itemIndex
 * @return
 * removes the item from room and passes it back to the object that called it.
 */
Item* Room::removeItem(int itemIndex){
    Item* Temp = itemsInRoom.at(itemIndex);
    itemsInRoom.erase(itemsInRoom.begin() + itemIndex);
    return Temp;
}

/**
 * @brief Room::getItem
 * @param itemIndex
 * @return returns the pointer of an item on the vector.
 */
Item* Room::getItem(int itemIndex){
    return itemsInRoom.at(itemIndex);
}

/**
 * @brief Room::getExits
 * @return returns a map of all the exits of this room.
 */
map<string, Room*> Room::getExits(){
    return exits;
}

/**
 * @brief Room::getNoOfExits
 * @return returns the number of valid exits in the room
 */
int Room::getNoOfExits(){
    int count = 0;
    if (exits["north"] != NULL){
         count++;
    }
    if (exits["east"] != NULL){
        count++;
    }
    if (exits["south"] != NULL){
         count++;
    }
    if (exits["west"] != NULL){
         count++;
    }
    if (exits["upstairs"] != NULL){
         count++;
    }
    if (exits["downstairs"] != NULL){
         count++;
    }
    return count;
}

