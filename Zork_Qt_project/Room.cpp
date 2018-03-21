#include "Room.h"
Room::Room(string description, int IDNumber ) {
    this->description = description;
    this->IDnumber = IDNumber;
    exits["north"] = NULL;
    exits["east"] = NULL;
    exits["south"] = NULL;
    exits["west"] = NULL;
}
Room::Room(int IDNumber) {
    this->description = to_string(IDNumber);
    this->IDnumber = IDNumber;
    exits["north"] = NULL;
    exits["east"] = NULL;
    exits["south"] = NULL;
    exits["west"] = NULL;
}
int Room::getIdNumber(){
    return IDnumber;
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

string Room::longDescription() {
	return "room = " + description + ".\n" + displayItem() + exitString();
}

string Room::exitString() {
	string returnString = "\nexits =";
    if (exits["north"] != NULL){
        returnString += "  North";
    }
    if (exits["east"] != NULL){
        returnString += "  East";
    }
    if (exits["south"] != NULL){
        returnString += "  South";
    }
    if (exits["west"] != NULL){
        returnString += "  West";
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
    itemsInRoom.push_back(*inItem);
}

void Room::addItem(Item &item) {
    itemsInRoom.push_back(item);
}

void Room::addItem(Item item) {
    itemsInRoom.push_back(item);
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
            tempString = tempString + itemsInRoom[x].getShortDescription() + "  " ;
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
            int tempFlag = inString.compare( itemsInRoom[x].getShortDescription());
            if (tempFlag == 0) {
                return x;
            }
            x++;
        }
    }
    return -1;
}

Item Room::removeItem(int itemIndex){
    Item Temp = itemsInRoom.at(itemIndex);
    itemsInRoom.erase(itemsInRoom.begin() + itemIndex);
    return Temp;
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

