#include <QCoreApplication>
#include <QApplication>
#include <iostream>
#include <ctime>
using namespace std;
#include "ZorkUL.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*MainWindow w;
    w.show();
    ZorkUL temp;
    temp.play();*/
    //return a.exec();
    ZorkUL temp;
	temp.play();
    return 0;
}
ZorkUL::ZorkUL() {
	createRooms();
}
void ZorkUL::createRooms()  {
    generateRandomFloorPlan();
    /* Directly pushing rooms onto the rooms vector so im not dealing with 2 variables*/
    /*rooms.push_back(new Room("First Room",0));//0
        rooms.at(0)->addItem(new Item("x", 1, 11));
        rooms.at(0)->addItem(new Item("y", 2, 22));
    rooms.push_back(new Room("Second Room",1));//1
        rooms.at(1)->addItem(new Item("xx", 3, 33));
        rooms.at(1)->addItem(new Item("yy", 4, 44));
    rooms.push_back(new Room("Third Room",2));//2
    rooms.push_back( new Room("Fourth Room",3));//3
    rooms.push_back(new Room("Fifth Room",4));//4
    rooms.push_back(new Room("Sixth Room",5));//5
    rooms.push_back(new Room("Seventh Room",6));//6
    rooms.push_back(new Room("Eigth Room",7));//7
    rooms.push_back( new Room("Nineth Room",8));//8
    rooms.push_back(new Room("Tenth Room",9));//9
    rooms.at(9)->addItem(new Item("A small bust of Aaron Dunes ginger head", 5, 33));
    //                   (N, E, S, W)
    rooms.at(0)->setExits(rooms.at(5),rooms.at(1),rooms.at(3), rooms.at(2));
    rooms.at(1)->setExits(NULL, NULL, NULL, rooms.at(0));
    rooms.at(2)->setExits(NULL, rooms.at(0), NULL, NULL);
    rooms.at(3)->setExits(rooms.at(0), rooms.at(4), NULL, rooms.at(8));
    rooms.at(4)->setExits(NULL, NULL, NULL, rooms.at(3));
    rooms.at(5)->setExits(rooms.at(9), rooms.at(6), rooms.at(0), rooms.at(7));
    rooms.at(6)->setExits(NULL, NULL, NULL, rooms.at(5));
    rooms.at(7)->setExits(NULL, rooms.at(5), NULL, NULL);
    rooms.at(8)->setExits(NULL, rooms.at(3), NULL, NULL);
    rooms.at(9)->setExits(NULL,NULL,rooms.at(5),NULL);

    currentRoom = rooms.at(0);*/
}
void ZorkUL::generateRandomFloorPlan(){
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
     srand(time(NULL));
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
     currentRoom = rooms.at(0);
 }
void ZorkUL::pushNULLsToEnd(Room* rooms[]){
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
int ZorkUL::getNumberOfValidRooms(Room* rooms[]){
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
/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
    printWelcome();
    // Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.
    bool finished = false;
	while (!finished) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << endl;
	cout << "end" << endl;
}
void ZorkUL::printWelcome() {
	cout << "start"<< endl;
	cout << "info for help"<< endl;
	cout << endl;
	cout << currentRoom->longDescription() << endl;
}
/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}
    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0){
		printHelp();
    }else if (commandWord.compare("map") == 0){
        cout << printMap() << endl;
         cout << currentRoom->longDescription() << endl;
    }else if (commandWord.compare("go") == 0){
		goRoom(command);
    }
    else if (commandWord.compare("take") == 0){
        // added functionality for user to take items out of a room
        if (!command.hasSecondWord()) {
            cout << "incomplete input"<< endl;
        }else if (command.hasSecondWord()) {
            cout << "you're trying to take " + command.getSecondWord() << endl;
            int location = currentRoom->isItemInRoom(command.getSecondWord());
            if (location  < 0 ){
                cout << "item is not in room" << endl;
            }else{
                cout << "item is in room" << endl;
                //adding item to user's inventory while also removing it from the room
                user.addItem(currentRoom->removeItem(location));
                cout << endl;
                cout << user.longDescription() << endl;
            }
        }
    }else if (commandWord.compare("put") == 0){
        // Added functionality for user to place item in a room

        if (!command.hasSecondWord()) {
            cout << "incomplete input"<< endl;
        }else if (command.hasSecondWord()) {
            cout << "you're trying to place " + command.getSecondWord() << endl;
            int location = user.isItemOnCharacter(command.getSecondWord());
            if (location  < 0 ){
                cout << "item is not on you" << endl;
            }else{
                cout << "item is on you "<< endl;
                /*Wrote a hand over function here,
                 * so while the room is gaining said item the user is loosing it.*/
                currentRoom->addItem(user.removeItem(location));
                cout << endl;
                cout << currentRoom->longDescription() << endl;
            }
        }
    }else if(commandWord.compare("teleport") == 0){
        //added debug functionality to jump to any room a player wanted
        if (command.hasSecondWord()){
            bool found = false;
            //go through each room to check if the room specified matches any of the rooms short description
            for(unsigned int i = 0; i < rooms.size(); i++){
                if(rooms.at(i)->shortDescription() == command.getSecondWord()){
                    currentRoom = rooms.at(i);
                    cout << currentRoom->longDescription() << endl;
                    found = true;
                    break;
                }
            }
            if(!found){
                cout << "No room by that name." << endl;
            }
        }else{
            //seeding random function with the current timestamp
            srand(time(NULL));
            int randomNum;
            //added a do-while to ensure you are teleported to another room
            do{
               randomNum = rand() % rooms.size();
            }while(currentRoom == rooms.at(randomNum));
            //set room to the room that was randomly generated.
            currentRoom = rooms.at(randomNum);
            cout << currentRoom->longDescription() << endl;
        }
    }else if(commandWord.compare("inventory") == 0){
        //displaying all the items in users inventory
        cout << user.longDescription() << endl;
    }else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord()){
			cout << "overdefined input"<< endl;
        }else{
			return true; /**signal to quit*/
        }
    }
	return false;
}
/** COMMANDS **/
void ZorkUL::printHelp() {
	cout << "valid inputs are; " << endl;
	parser.showCommands();
}
void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}
    string direction = command.getSecondWord();
    // Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL){
		cout << "underdefined input"<< endl;
    }else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}
string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL){
		return("direction null");
    }else{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}
bool ZorkUL::findMapCoordinates(Room* rooms,int *x_position, int *y_position, vector<vector<string>> mapDisplay){
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
string ZorkUL::printMap(){
    vector<vector<string>> mapDisplay;
    int x_position = 0,y_position = 0;
    string textMap;
    addMapIndex(x_position, y_position , &mapDisplay, rooms[0], &textMap);
    return textMap;
}
vector<string> ZorkUL::fillEmptySlots(int x_position, bool invisible){
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
vector<vector<string>> ZorkUL::traverseExits(int x_position, int y_position,
                           vector<vector<string>> mapString,map<string,Room*> currentRoomExits,
                           vector<string> temp,Room* currentRoom,string *textMap){
    /*This function builds a text map displaying to
     * the user the current orientation of the rooms.
     * The method works recursively to get a full map.*/
    if(currentRoomExits["east"] != NULL){
        if(mapString[y_position].size() < (x_position)+2){
                mapString[y_position].push_back("---");
                mapString[y_position].push_back("");
                addMapIndex(x_position+2, y_position, &mapString, currentRoomExits["east"],textMap);
        }
    }
    if(currentRoomExits["west"] != NULL){
        if(x_position < 2 && mapString[y_position][(x_position)] != to_string(currentRoomExits["west"]->getIdNumber())){
            mapString[y_position].insert(mapString[y_position].begin(),"---");
            mapString[y_position].insert(mapString[y_position].begin(),"");
            if(x_position < 0){
               x_position = 0;
            }
            addMapIndex(x_position, y_position, &mapString, currentRoomExits["west"],textMap);
        }else if(mapString[y_position][(x_position)-2] != to_string(currentRoom->getIdNumber())){
            addMapIndex(x_position-2, y_position, &mapString, currentRoomExits["west"],textMap);
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
            addMapIndex(x_position, y_position+2, &mapString, currentRoomExits["south"],textMap);
        }else{
            addMapIndex(x_position, y_position+2, &mapString, currentRoomExits["south"],textMap);
        }

    }
    return mapString;
}

void ZorkUL::addMapIndex(int x_position, int y_position, vector<vector<string>> *mapDisplay, Room* currentRoom, string *textMap){
    map<string,Room*> currentRoomExits;
    vector<string> temp;
    vector<vector<string>> mapString = *mapDisplay;
    if(x_position == 0 && y_position == 0 && mapString.size() == 0){
        temp.push_back(to_string(currentRoom->getIdNumber()));
        mapString.push_back(temp);
        currentRoomExits = currentRoom->getExits();
        mapString = traverseExits(x_position, y_position,
                                  mapString,currentRoomExits,
                                  temp,currentRoom,textMap);

     }else if(y_position < mapString.size()){
        if(x_position < mapString[y_position].size()){
            mapString[y_position][x_position] = to_string(currentRoom->getIdNumber());
            currentRoomExits = currentRoom->getExits();
            mapString = traverseExits(x_position, y_position,
                                      mapString,currentRoomExits,
                                      temp,currentRoom,textMap);
       }
    }
    *mapDisplay = mapString;
    *textMap = "";
    for(int i = 0; i < mapString.size(); i++){
        for(int j =0; j < mapString[i].size();j++){
           *textMap += mapString[i][j] + " ";
        }
        *textMap += "\n";
    }
}

int ZorkUL::getLargestIndex(vector<vector<string>> mapDisplay, int i, int j){
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
