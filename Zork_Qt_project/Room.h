#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
using namespace std;
using std::vector;

class Room {

private:
	string description;
    map<string, Room*> exits;
	string exitString();
    vector <Item> itemsInRoom;


public:
    int numberOfItems();
	Room(string description);
	void setExits(Room *north, Room *east, Room *south, Room *west);
    void setNorthExit(Room *north);
    void setEastExit(Room *east);
    void setSouthExit(Room *south);
    void setWestExit(Room *west);
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

};

#endif
