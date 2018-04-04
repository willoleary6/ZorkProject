#ifndef FLOOR_H
#define FLOOR_H
#include <vector>
#include <Room.h>

using namespace std;

class floor {

    private:
        int floorId;
        vector <Room *> rooms;

        void generateRandomFloorPlan();
        void pushNULLsToEnd(Room* rooms[]);
        void addMapIndex(int x_position, int y_position, vector<vector<string>> *mapDisplay, Room* currentRoom);

        int getNumberOfValidRooms(Room* rooms[]);
        int getLargestIndex(vector<vector<string>> mapDisplay, int j);

        bool findMapCoordinates(Room* rooms,int *x_position, int *y_position, vector<vector<string>> mapDisplay);

        vector<string> fillEmptySlots(int x_position, bool invisible);
        vector<vector<string>> traverseExits(int x_position, int y_position,
                                   vector<vector<string>> mapString,map<string,Room*> currentRoomExits,
                                   vector<string> temp,Room* currentRoom);


    public:
        floor();
        ~floor();
        floor(int basement);
        vector <Room *> getRooms();
        string printMap();
};

#endif // FLOOR_H
