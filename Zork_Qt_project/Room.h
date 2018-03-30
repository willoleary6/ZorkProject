#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
#include "carryableItem.h"
#include "searchableitem.h"
#include "Command.h"
#include "key.h"

using namespace std;

class Room{

private:
    string name;
    string description;
    map<string, Room*> exits;
    string exitString();
    vector <Item*> itemsInRoom;
    int IDnumber;
    int numberOfItems();
    int lowerFloorIndex;
    int upperFloorIndex;
    int upperFloor;
    int lowerFloor;
    int floorId;
    bool locked;
    key KeyForRoom;

public:
    key* lockRoom();
    key* getKey();
    void unlockRoom();
    int getFloorID();
    bool isLocked();
    string roomName();
    Room(string description, int IDnumber, int floorId);
    Room(int IDnumber,int floorId);
    void setExits(Room *north, Room *east, Room *south, Room *west);
    void setNorthExit(Room *north);
    void setEastExit(Room *east);
    void setSouthExit(Room *south);
    void setWestExit(Room *west);
    void setUpstairsExit(Room *upstairs);
    void setDownstairsExit(Room *downstairs);
    string shortDescription();
    string longDescription();
    Room* nextRoom(string direction);
    void addItem(Item *item);
    string displayItem();
    int isItemInRoom(string inString);
    Item* removeItem(int itemIndex);
    Item* getItem(int itemIndex);
    map<string, Room*> getExits();
    int getNoOfExits();
    int getIdNumber();

};

#endif
