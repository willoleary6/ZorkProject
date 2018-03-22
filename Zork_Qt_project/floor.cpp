#include "floor.h"

floor::floor(){
     generateRandomFloorPlan();
}
floor::floor(int basement){
    rooms.push_back(new Room("Basement",0));
    //rooms.push_back();
}
vector<Room *> floor::getRooms(){
    return rooms;
}
void floor::generateRandomFloorPlan(){
    //This function generates a random floor plan of the map.
    Room* floorPlan[4][4];
     /*Room* floorPlan[4][4] = {{NULL,new Room(1),new Room(2),new Room(3)},
                              {new Room(4),NULL,new Room(5),new Room(6)},
                              {NULL,new Room(7),NULL,NULL},
                              {new Room(8),new Room(9),NULL,NULL}};*/
     int rows = sizeof floorPlan/sizeof floorPlan[0];
     int cols = sizeof floorPlan[0]/sizeof(Room*);
     int count = 0;
     int randomValue =0;
     /* TODO: ok we need to sort the randomly generated arrays so that the NULLs are all together in one side to avoid problems
      *
      */
     /*Basic idea of the floor plan is a matt of 4X4 NULLs
      * and we change some of them to actual rooms depending on a random value.
      */
     for(int i =0; i < rows; i++){
         for(int j = 0; j < cols; j++){
             //generating random value
             randomValue = rand() % 9;
             //about a 60% chance that each index will be populated with a room.
             if(randomValue > 5){
                 floorPlan[i][j] = NULL;
             }else{
                 count++;
                 //create a new room and set its ID number to that of the count.
                 floorPlan[i][j] = new Room(count);
             }
         }
     }
     //sorting this row so nulls are all to the right
     for(int row = 0; row < rows;row++){
         pushNULLsToEnd(floorPlan[row]);
     }
     map<string, Room*> roomExits;
     //Linking each room together so a player can traverse the map.
     for(int i = 0; i < rows;i++){
         for(int j=0; j < cols;j++){
             if(floorPlan[i][j] != NULL){
                 //get the exits currently set.
                 roomExits = floorPlan[i][j]->getExits();
                 //range horizontal right populating the eastern exit possibly
                 //making sure there is actually space to move right
                 if(j < cols-1 && roomExits["east"] == NULL){
                     //this block adds a link to all rooms horizontally
                     for(int rangeRight = j+1; rangeRight < rows; rangeRight++){
                         if(floorPlan[i][rangeRight] != NULL && floorPlan[i][rangeRight] != floorPlan[i][j]){
                            //linking each room
                            floorPlan[i][j]->setEastExit(floorPlan[i][rangeRight]);
                            floorPlan[i][rangeRight]->setWestExit(floorPlan[i][j]);
                            goto upWard;
                         }
                     }
                 }
                 upWard:
                 if(i > 0 && j ==0 && roomExits["north"] == NULL){
                     //This block adds a vertical link to one of the rooms on this row(Chosen Randomly)
                     do{
                        randomValue = rand() % getNumberOfValidRooms(floorPlan[i]);
                     }while(floorPlan[i-1][randomValue] == NULL);
                     floorPlan[i][randomValue]->setNorthExit(floorPlan[i-1][randomValue]);
                     floorPlan[i-1][randomValue]->setSouthExit(floorPlan[i][randomValue]);
                 }
             }
         }
     }
     //adding randomly generated rooms to the rooms list
     for(int i = 0; i < rows; i++){
         for(int j = 0; j < cols; j++){
             if(floorPlan[i][j] != NULL){
                rooms.push_back(floorPlan[i][j]);
             }
         }

     }
 }
void floor::pushNULLsToEnd(Room* rooms[]){
    /*This function sorts eash row of a floorPlan
     * so all the NULLs in it are pushed to the right
     * hand side removinging any "Room islands" that may form.
     */
    int count = 0;
    for(int i = 0; i < sizeof(rooms); i++)
        if(rooms[i] != NULL)
            rooms[count++] = rooms[i];
    while(count < sizeof(rooms))
        rooms[count++] = NULL;
}
int floor::getNumberOfValidRooms(Room* rooms[]){
    /*this function gets the number of rooms in a row so we
     * can generate a random index to connect it vertically to a room on the upper row.
     */
    int count  = 0;
    for(int i = 0; i < sizeof(rooms); i++){
        if(rooms[i] != NULL){
            count ++;
        }
    }
    return count;
}
bool floor::findMapCoordinates(Room* rooms,int *x_position, int *y_position, vector<vector<string>> mapDisplay){
    //this function finds the x-y coordinates of a room that we know is already on the map.
    for(int j = 0; j < mapDisplay.size(); j++){
        for(int k = 0; k <mapDisplay[j].size(); k++){
            if(rooms->shortDescription() == mapDisplay[j][k]){
                *x_position = k;
                *y_position = j;
                return true;
            }
        }
    }
    return false;
}
string floor::printMap(){
    vector<vector<string>> mapDisplay;
    int x_position = 0,y_position = 0;
    addMapIndex(x_position, y_position , &mapDisplay, rooms[0]);
    string textMap;
    vector<int> LargestIndex;

    for(int x = 0; x < mapDisplay.size(); x++){
    for(int y=0; y < mapDisplay[x].size();y++){
            while(LargestIndex.size() <= y){
                LargestIndex.push_back(0);
            }
            if(mapDisplay[x][y].length() > LargestIndex[y]){
                LargestIndex[y] = mapDisplay[x][y].length();
            }
        }
    }
    for(int i = 0; i < mapDisplay.size(); i++){
        for(int j =0; j < mapDisplay[i].size();j++){
           if(LargestIndex[j] > mapDisplay[i][j].length()){
                textMap += string(((LargestIndex[j]+1)-(mapDisplay[i][j].length()))/2,' ');
                textMap += mapDisplay[i][j];
                textMap += string(((LargestIndex[j]+1)-(mapDisplay[i][j].length()))/2,' ');
           }else{
                textMap += " "+mapDisplay[i][j];
           }
        }
        textMap += "\n";
    }
    return textMap;
}
vector<string> floor::fillEmptySlots(int x_position, bool invisible){
    //This function populates empty parts of the map with the neccessary text
    vector<string> temp;
    for(int i =0; i < x_position;i++){
        if(i%2==0){
            temp.push_back(" ");
        }else{
            //every second row is a blank row so any text entered must be made invisible for those rows.
            if(invisible){
                temp.push_back("   ");
            }else{
                temp.push_back("---");
            }
        }
    }
    return temp;
}
vector<vector<string>> floor::traverseExits(int x_position, int y_position,
                           vector<vector<string>> mapString,map<string,Room*> currentRoomExits,
                           vector<string> temp,Room* currentRoom){
    /*This function builds a text map displaying to
     * the user the current orientation of the rooms.
     * The method works recursively to get a full map.*/
    if(currentRoomExits["east"] != NULL){
        if(mapString[y_position].size() < (x_position)+2){
                mapString[y_position].push_back("---");
                mapString[y_position].push_back("");
                addMapIndex(x_position+2, y_position, &mapString, currentRoomExits["east"]);
        }
    }
    if(currentRoomExits["west"] != NULL){
        if(x_position < 2 && mapString[y_position][(x_position)] != to_string(currentRoomExits["west"]->getIdNumber())){
            mapString[y_position].insert(mapString[y_position].begin(),"---");
            mapString[y_position].insert(mapString[y_position].begin(),"");
            if(x_position < 0){
               x_position = 0;
            }
            addMapIndex(x_position, y_position, &mapString, currentRoomExits["west"]);
        }else if(mapString[y_position][(x_position)-2] != to_string(currentRoom->getIdNumber())){
            addMapIndex(x_position-2, y_position, &mapString, currentRoomExits["west"]);
        }
    }
    if(currentRoomExits["south"] != NULL){
        findMapCoordinates(currentRoom,&x_position, &y_position, mapString);
        if(y_position+1 == mapString.size()){
            temp.clear();
            temp = fillEmptySlots(x_position,true);
            temp.push_back("|");
            mapString.push_back(temp);
            temp.clear();
            temp = fillEmptySlots(x_position,false);
            temp.push_back("");
            mapString.push_back(temp);
            temp.clear();
            addMapIndex(x_position, y_position+2, &mapString, currentRoomExits["south"]);
        }else{
            addMapIndex(x_position, y_position+2, &mapString, currentRoomExits["south"]);
        }

    }
    return mapString;
}

void floor::addMapIndex(int x_position, int y_position, vector<vector<string>> *mapDisplay, Room* currentRoom){
    map<string,Room*> currentRoomExits;
    vector<string> temp;
    vector<vector<string>> mapString = *mapDisplay;
    if(x_position == 0 && y_position == 0 && mapString.size() == 0){
        temp.push_back(to_string(currentRoom->getIdNumber()));
        mapString.push_back(temp);
        currentRoomExits = currentRoom->getExits();
        mapString = traverseExits(x_position, y_position,
                                  mapString,currentRoomExits,
                                  temp,currentRoom);

     }else if(y_position < mapString.size()){
        if(x_position < mapString[y_position].size()){
            mapString[y_position][x_position] = to_string(currentRoom->getIdNumber());
            currentRoomExits = currentRoom->getExits();
            mapString = traverseExits(x_position, y_position,
                                      mapString,currentRoomExits,
                                      temp,currentRoom);
       }
    }
    *mapDisplay = mapString;
}

int floor::getLargestIndex(vector<vector<string>> mapDisplay, int j){
    /*this function goes through the selected column
     * and returns the size of the largest value in that columns.
     */
    int largest = 0;
    for(int k = 0; k < mapDisplay.size(); k++){
            if(largest < mapDisplay[k][j].length()){
                largest = mapDisplay[k][j].length();
            }
     }
    return largest;
}

