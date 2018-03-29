#include "Room.h"
Room::Room(string description, int IDNumber, int floorId) {
    this->description = description;
    this->name = description;
    this->IDnumber = IDNumber;
    this->floorId = floorId;
    locked = false;
    exits["north"] = NULL;
    exits["east"] = NULL;
    exits["south"] = NULL;
    exits["west"] = NULL;
    exits["upstairs"] = NULL;
    exits["downstairs"] = NULL;
}
Room::Room(int IDNumber,int floorId) {
    this->description = to_string(IDNumber);
    this->name = to_string(IDNumber);
    this->IDnumber = IDNumber;
    this->floorId = floorId;
    locked = false;
    exits["north"] = NULL;
    exits["east"] = NULL;
    exits["south"] = NULL;
    exits["west"] = NULL;
    exits["upstairs"] = NULL;
    exits["downstairs"] = NULL;
}
int Room::getIdNumber(){
    return IDnumber;
}
int Room::getFloorID(){
    return floorId;
}
key* Room::lockRoom(){
    locked = true;
    KeyForRoom =  key(description,IDnumber,floorId);
    name += "[L]";
    return &KeyForRoom;
}
bool Room::isLocked(){
    return locked;

}
void Room::unlockRoom(){
    locked = false;
    name.erase(name.find("[L]"),3);
}
key* Room::getKey(){
    return &KeyForRoom;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
    if (north != NULL){
        exits["north"] = north;
    }
    if (east != NULL){
        exits["east"] = east;
    }
    if (south != NULL){
        exits["south"] = south;
    }
    if (west != NULL){
        exits["west"] = west;
    }
}
void Room::setNorthExit(Room *north){
    exits["north"] = north;
}
void Room::setUpstairsExit(Room *upstairs){
    exits["upstairs"] = upstairs;
    name += "[^]";
}
void Room::setDownstairsExit(Room *downstairs){
    exits["downstairs"] = downstairs;
    name += "[v]";
}

void Room::setEastExit(Room *east){
    exits["east"] = east;
}

void Room::setSouthExit(Room *south){
    exits["south"] = south;
}

void Room::setWestExit(Room *west){
    exits["west"] = west;
}

string Room::shortDescription() {
    return description;
}
string Room::roomName(){
   return name;
}

string Room::longDescription() {
    return "room = " + description + ".\n" + displayItem() + exitString();
}

string Room::exitString() {
    string returnString = "\nexits =";
    if (exits["north"] != NULL){
        returnString += " north";
    }
    if (exits["east"] != NULL){
        returnString += " east";
    }
    if (exits["south"] != NULL){
        returnString += " south";
    }
    if (exits["west"] != NULL){
        returnString += " west";
    }
    if(exits["upstairs"] != NULL){
        returnString += " upstairs";
    }
    if(exits["downstairs"] != NULL){
        returnString += " downstairs";
    }
    return returnString;
}

Room* Room::nextRoom(string direction) {
    map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
        return NULL; // if exits.end() was returned, there's no room in that direction.
    return next->second; // If there is a room, remove the "second" (Room*)
                // part of the "pair" (<string, Room*>) and return it.
}

void Room::addItem(Item *inItem) {
    itemsInRoom.push_back(inItem);
}


string Room::displayItem() {
    string tempString = "items in room = ";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "no items in room";
    }
    else if (itemsInRoom.size() > 0) {
        int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + itemsInRoom[x]->getShortDescription() + "  " ;
            x++;
        }
    }
    return tempString;
}

int Room::numberOfItems() {
    return itemsInRoom.size();
}

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

Item* Room::removeItem(int itemIndex){
    Item* Temp = itemsInRoom.at(itemIndex);
    itemsInRoom.erase(itemsInRoom.begin() + itemIndex);
    return Temp;
}
Item* Room::getItem(int itemIndex){
    return itemsInRoom.at(itemIndex);
}
map<string, Room*> Room::getExits(){
    return exits;
}
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
    return count;
}

