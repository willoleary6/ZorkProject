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
    void nullifyExits();
    string exitString();

    int numberOfItems();

    string name;
    string description;
    map<string, Room*> exits;

    vector <Item*> itemsInRoom;

    int IDnumber;
    int lowerFloorIndex;
    int upperFloorIndex;
    int upperFloor;
    int lowerFloor;
    int floorId;
    bool locked;

    key KeyForRoom;

public:
    Room(string description, int IDnumber, int floorId);
    Room(int IDnumber,int floorId);
    ~Room();

    key* lockRoom();
    key* getKey();

    int getFloorID();
    int getNoOfExits();
    int getIdNumber();
    int isItemInRoom(string inString);

    bool isLocked();

    string roomName();
    string shortDescription();
    string longDescription();
    string displayItem();

    Item* removeItem(int itemIndex);
    Item* getItem(int itemIndex);

    void unlockRoom();
    void setExits(Room *north, Room *east, Room *south, Room *west);
    void setNorthExit(Room *north);
    void setEastExit(Room *east);
    void setSouthExit(Room *south);
    void setWestExit(Room *west);
    void setUpstairsExit(Room *upstairs);
    void setDownstairsExit(Room *downstairs);
    void addItem(Item *item);

    Room* nextRoom(string direction);

    map<string, Room*> getExits();
};

#endif
