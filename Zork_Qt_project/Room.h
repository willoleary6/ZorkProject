#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
#include "Command.h"
using namespace std;

class Room {

private:
	string description;
    map<string, Room*> exits;
	string exitString();
    vector <Item> itemsInRoom;
    int IDnumber;
    int numberOfItems();
    int lowerFloorIndex;
    int upperFloorIndex;
    int upperFloor;
    int lowerFloor;

public:

    Room(string description, int IDnumber);
    Room(int IDnumber);
	void setExits(Room *north, Room *east, Room *south, Room *west);
    void setNorthExit(Room *north);
    void setEastExit(Room *east);
    void setSouthExit(Room *south);
    void setWestExit(Room *west);
    void setUpStairsExit(Room *upStairs);
    void setDownStairsExit(Room *downStairs);
	string shortDescription();
	string longDescription();
	Room* nextRoom(string direction);
    void addItem(Item *inItem);
    void addItem(Item &item);
    void addItem(Item item);
    string displayItem();
    int isItemInRoom(string inString);
    Item removeItem(int itemIndex);
    map<string, Room*> getExits();
    int getNoOfExits();
    int getIdNumber();

};

#endif
