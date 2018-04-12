#include "floor.h"
#define DEFAULT 0
#define floorDimension 4
/**
 * @brief floor::floor
 * @param floorId
 * Constructor that creates and populates a vector of rooms.
 */
floor::floor(int floorId){
    this->floorId = floorId;
    if(floorId == 0){
        // The 1st floor will always be the basement
        rooms.push_back(new Room("Basement",0,floorId));
    }else{
        // Every other floor is randomly generated
        generateRandomFloorPlan();
    }
}

/**
 * @brief floor::~floor
 */
floor::~floor(){
    for(int i =0; i < rooms.size(); i++){
        delete rooms[i];
    }
}

/**
 * @brief floor::getRooms
 * @return returns the vector of rooms on the floor
 */
vector<Room *> floor::getRooms(){
    return rooms;
}

/**
 * @brief floor::generateRandomFloorPlan
 * Function that generates a random floor plan for a map.
 */
void floor::generateRandomFloorPlan(){
    // This function generates a random floor plan of the map.
    Room* floorPlan[floorDimension][floorDimension];
    int rows = sizeof floorPlan/sizeof floorPlan[DEFAULT];
    int cols = sizeof floorPlan[DEFAULT]/sizeof(Room*);
    int count = DEFAULT;
    int randomValue =0;
    vector <string> roomNames = {"Gallery", "Library", "Bedrm", "Kitchen", "Dining", "Sitting",
                                "Mstr-bedrm", "Bathrm", "Garage", "Cloak-rm", "Conservatory", "Pantry", "Office",
                                "Lounge", "Closet", "Guest-bedrm", "Lndry-rm", "Game-rm", "Storage"};

    /*Basic idea of the floor plan is a matt of 4X4 NULLs
     * and we change some of them to actual rooms depending on a random value.
     */
    bool populationCheck;
    for(int i =0; i < rows; i++){
        populationCheck = false;
        do {
            for(int j = 0; j < cols; j++){
                // Generating random value
                randomValue = rand() % 9;
                // About a 60% chance that each index will be populated with a room.
                if(randomValue > 5){
                    floorPlan[i][j] = NULL;
                }else{
                    populationCheck = true;
                    count++;
                    // Create a new room and set its ID number to that of the count.
                    int roomNameIndex = rand() % roomNames.size();
                    floorPlan[i][j] = new Room(roomNames[roomNameIndex],count,floorId);
                    roomNames.erase(roomNames.begin() + roomNameIndex);
                }
            }
        }while(!populationCheck);
     }
     // Sorting this row so nulls are all to the right

     for(int row = 0; row < rows;row++){
         pushNULLsToEnd(floorPlan[row]);
     }
     map<string, Room*> roomExits;
     // Linking each room together so a player can traverse the map.

     for(int i = 0; i < rows;i++){
         for(int j=0; j < cols;j++){
             if(floorPlan[i][j] != NULL){
                 // Get the exits currently set.
                 roomExits = floorPlan[i][j]->getExits();
                 // Range horizontal right populating the eastern exit possibly
                 // Making sure there is actually space to move right

                 if(j < cols-1 && roomExits["east"] == NULL){
                     // This block adds a link to all rooms horizontally
                     for(int rangeRight = j+1; rangeRight < rows; rangeRight++){
                         if(floorPlan[i][rangeRight] != NULL && floorPlan[i][rangeRight] != floorPlan[i][j]){
                            // Linking each room
                            floorPlan[i][j]->setEastExit(floorPlan[i][rangeRight]);
                            floorPlan[i][rangeRight]->setWestExit(floorPlan[i][j]);
                            // Jump out of for loop once found
                            goto upWard;
                         }
                     }
                 }
                 upWard:
                 if(i > 0 && j ==0 && roomExits["north"] == NULL){
                     // This block adds a vertical link to one of the rooms on this row(Chosen Randomly)
                     do {
                        randomValue = rand() % getNumberOfValidRooms(floorPlan[i]);
                     } while(floorPlan[i-1][randomValue] == NULL);
                     floorPlan[i][randomValue]->setNorthExit(floorPlan[i-1][randomValue]);
                     floorPlan[i-1][randomValue]->setSouthExit(floorPlan[i][randomValue]);
                 }
             }
         }
     }

     // Adding randomly generated rooms to the rooms list
     for(int i = 0; i < rows; i++){
         for(int j = 0; j < cols; j++){
             if(floorPlan[i][j] != NULL){
                rooms.push_back(floorPlan[i][j]);
             }
         }
     }
}

/**
 * @brief floor::pushNULLsToEnd
 * @param rooms
 * function that sorts NULL values on the floor plan to the end of the row.
 */
void floor::pushNULLsToEnd(Room* rooms[]){
    /*
     *  This function sorts eash row of a floorPlan
     *  so all the NULLs in it are pushed to the right
     *  hand side removinging any "Room islands" that may form.
     */
    int count = DEFAULT;
    for(int i = 0; i < sizeof(rooms); i++)
        if(rooms[i] != NULL)
            rooms[count++] = rooms[i];
    while(count < sizeof(rooms))
        rooms[count++] = NULL;
}


/**
 * @brief floor::getNumberOfValidRooms
 * @param rooms
 * @return returns the number of non NULL rooms on a row of a floor plan.
 */
int floor::getNumberOfValidRooms(Room* rooms[]){
    /*
     *  This function gets the number of rooms in a row so we
     *  can generate a random index to connect it vertically to a room on the upper row.
     */
    int count  = DEFAULT;
    for(int i = 0; i < sizeof(rooms); i++){
        if(rooms[i] != NULL){
            count ++;
        }
    }
    return count;
}

/**
 * @brief floor::findMapCoordinates
 * @param rooms
 * @param x_position
 * @param y_position
 * @param mapDisplay
 * @return returns the coordinates on the 2D floor plan vector of the current room
 */
bool floor::findMapCoordinates(Room* rooms,int *x_position, int *y_position, vector<vector<string>> mapDisplay){
    // This function finds the x-y coordinates of a room that we know is already on the map.
    for(int j = 0; j < mapDisplay.size(); j++){
        for(int k = 0; k <mapDisplay[j].size(); k++){
            if(rooms->roomName() == mapDisplay[j][k]){
                *x_position = k;
                *y_position = j;
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief floor::printMap
 * @return returns the string of the floor plan for this floor
 */
string floor::printMap(){
    // Initialising variables
    vector<vector<string>> mapDisplay;
    int x_position = DEFAULT,y_position = DEFAULT;
    // Starting the recursive process with the first room on the floor
    addMapIndex(x_position, y_position , &mapDisplay, rooms[0]);
    string textMap;
    vector<int> LargestIndex;
    int before, after;
    // Get the largest value in each index so we can properly keep the map formatted
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
    // Now building the string of the text map to be returned
    for(int i = 0; i < mapDisplay.size(); i++){
        for(int j =0; j < mapDisplay[i].size();j++){
           if(LargestIndex[j] > mapDisplay[i][j].length()){
                // Add each element of the map so each room is in line
                before = ((LargestIndex[j])-(mapDisplay[i][j].length()))/2;
                after = ((LargestIndex[j])-(mapDisplay[i][j].length())) - before;
                textMap += ' '+string(before+1,' ');    // to_string();//string(((LargestIndex[j])-(mapDisplay[i][j].length()))/2,'_');
                textMap += mapDisplay[i][j];
                textMap += string(after+1,' ')+' ';     // to_string(/2);//string(((LargestIndex[j])-(mapDisplay[i][j].length()))/2,'_');
           }else{
                textMap += ' '+mapDisplay[i][j]+' ';
           }
        }
        textMap += "\n";
    }
    return textMap;
}

/**
 * @brief floor::fillEmptySlots
 * @param x_position
 * @param invisible
 * @return returns an empty vector which is used to format the string map
 */
vector<string> floor::fillEmptySlots(int x_position, bool invisible){
    //  This function populates empty parts of the map with the neccessary text
    vector<string> temp;
    for(int i =0; i < x_position;i++){
        if(i%2==0){
            temp.push_back(" ");
        }else{
            //  Every second row is a blank row so any text entered must be made invisible for those rows.
            if(invisible){
                temp.push_back(" ");
            }else{
                temp.push_back("___");
            }
        }
    }
    return temp;
}
/**
 * @brief floor::traverseExits
 * @param x_position
 * @param y_position
 * @param mapString
 * @param currentRoomExits
 * @param temp
 * @param currentRoom
 * @return
 * a recursive function which returns a vector of vectors of all rooms on the floor, travelling recursively through each room.
 */
vector<vector<string>> floor::traverseExits(int x_position, int y_position,
                           vector<vector<string>> mapString,map<string,Room*> currentRoomExits,
                           vector<string> temp,Room* currentRoom){
    /*
     *  This function builds a text map displaying to
     *  the user the current orientation of the rooms.
     *  The method works recursively to get a full map.
     */
    if(currentRoomExits["east"] != NULL){
        if(mapString[y_position].size() < (x_position)+2){
                /*
                 *  Add new indexes to the mapString and call this function again
                 *  setting the last index to be replaced with the eastern exit.
                 */
                mapString[y_position].push_back("---");
                mapString[y_position].push_back("");
                addMapIndex(x_position+2, y_position, &mapString, currentRoomExits["east"]);
        }
    }
    if(currentRoomExits["west"] != NULL){
        if(x_position < 2 && mapString[y_position][(x_position)] != currentRoomExits["west"]->roomName()){
            /*
             *  We've determined that we need to insert new indexes at the start of the vector
             *  and we then set the new first index by calling this function again.
             */
            mapString[y_position].insert(mapString[y_position].begin(),"---");
            mapString[y_position].insert(mapString[y_position].begin(),"");
            //  Ensuring x_position doesnt go off target
            if(x_position < 0){
               x_position = DEFAULT;
            }
            addMapIndex(x_position, y_position, &mapString, currentRoomExits["west"]);
        }else if(mapString[y_position][(x_position)-2] != currentRoom->roomName()){
            /*
             *  The index 2 spaces to our left needs to be
             *  set so we call this function again to set its new value.
             */
            addMapIndex(x_position-2, y_position, &mapString, currentRoomExits["west"]);
        }
    }
    if(currentRoomExits["south"] != NULL){
        findMapCoordinates(currentRoom,&x_position, &y_position, mapString);
        if(y_position+1 == mapString.size()){
            /*
             *  We've to created a new row on the map so we must
             *  now populate it with empty values and set the relevant values by calling this fuction again...
             */
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
            //  Index below us already exists so we simply set the value
            addMapIndex(x_position, y_position+2, &mapString, currentRoomExits["south"]);
        }
    }
    return mapString;
}

/**
 * @brief floor::addMapIndex
 * @param x_position
 * @param y_position
 * @param mapDisplay
 * @param currentRoom
 * sets values of the mapString vector with that of room names
 */
void floor::addMapIndex(int x_position, int y_position, vector<vector<string>> *mapDisplay, Room* currentRoom){
    //  Initialising variables
    map<string,Room*> currentRoomExits;
    vector<string> temp;
    vector<vector<string>> mapString = *mapDisplay;
    //  1st run through
    if(x_position == 0 && y_position == 0 && mapString.size() == 0){
        //  1st index of the map will be the room
        temp.push_back(currentRoom->roomName());
        mapString.push_back(temp);
        currentRoomExits = currentRoom->getExits();
        //  Get next room
        mapString = traverseExits(x_position, y_position,
                                  mapString,currentRoomExits,
                                  temp,currentRoom);

     }else if(y_position < mapString.size()){
        //  Checking were not out of bounds
        if(x_position < mapString[y_position].size()){
            /*
             *  mapString already has the indexes initialised
             *  so we simply set the value of right index with the room name.
             */
            mapString[y_position][x_position] = currentRoom->roomName();
            currentRoomExits = currentRoom->getExits();
            //  Get next room
            mapString = traverseExits(x_position, y_position,
                                      mapString,currentRoomExits,
                                      temp,currentRoom);
       }
    }
    //  Update the mapDisplay vector(the final product of this recursion).
    *mapDisplay = mapString;
}

/**
 * @brief floor::getLargestIndex
 * @param mapDisplay
 * @param j
 * @return
 * returns the largest index in this column of the map so we can properly format the map.
 */
int floor::getLargestIndex(vector<vector<string>> mapDisplay, int j){
    /*
     *  This function goes through the selected column
     *  and returns the size of the largest value in that columns.
     */
    int largest = DEFAULT;
    for(int k = 0; k < mapDisplay.size(); k++){
            if(largest < mapDisplay[k][j].length()){
                largest = mapDisplay[k][j].length();
            }
     }
    return largest;
}
