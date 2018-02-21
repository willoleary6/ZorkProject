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
    /* Directly pushing rooms onto the rooms vector so im not dealing with 2 variables*/
    rooms.push_back(new Room("First Room"));//0
        rooms.at(0)->addItem(new Item("x", 1, 11));
        rooms.at(0)->addItem(new Item("y", 2, 22));
    rooms.push_back(new Room("Second Room"));//1
        rooms.at(1)->addItem(new Item("xx", 3, 33));
        rooms.at(1)->addItem(new Item("yy", 4, 44));
    rooms.push_back(new Room("Third Room"));//2
    rooms.push_back( new Room("Fourth Room"));//3
    rooms.push_back(new Room("Fifth Room"));//4
    rooms.push_back(new Room("Sixth Room"));//5
    rooms.push_back(new Room("Seventh Room"));//6
    rooms.push_back(new Room("Eigth Room"));//7
    rooms.push_back( new Room("Nineth Room"));//8
    rooms.push_back(new Room("Tenth Room"));//9
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

    currentRoom = rooms.at(0);
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
        //map<string,Room*> currentRoomExits = rooms.at(0)->getExits();
        //cout << currentRoomExits["north"]->shortDescription() << endl;
        /*cout << "[h] --- [f] --- [g]" << endl;
		cout << "         |         " << endl;
        cout << "         |         " << endl;
		cout << "[c] --- [a] --- [b]" << endl;
		cout << "         |         " << endl;
		cout << "         |         " << endl;
        cout << "[i] --- [d] --- [e]" << endl;*/
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
bool ZorkUL::findMapCoordinates(int index,int *x_position, int *y_position, vector<vector<string>> mapDisplay){
    for(int j = 0; j < mapDisplay.size(); j++){
        for(int k = 0; k <mapDisplay[j].size(); k++){
            if(rooms[index]->shortDescription() == mapDisplay[j][k]){
                *x_position = k;
                *y_position = j;
                return true;
            }
        }
    }
    return false;
}
string ZorkUL::printMap(){
    bool pushBackUsed = false, insertUsed = false;
    map<string,Room*> currentRoomExits;
            //cout << currentRoomExits["north"]->shortDescription() << endl;
    vector<vector<string>> mapDisplay;
    vector<string> temp;
    int x_position = 0,y_position = 0;
    temp.push_back(rooms.at(0)->shortDescription());
    mapDisplay.push_back(temp);
    //go through each room and add it to vector map
    for(int i = 0; i < rooms.size(); i++){
        currentRoomExits  = rooms.at(i)->getExits();
        //TODO: add safegaurd to stop island rooms

        findMapCoordinates(i,&x_position, &y_position,mapDisplay);
        if(currentRoomExits["east"] != NULL){
            /*we have now established that the current room has
             * an exit to its east and we will now reflect that on the map.
             */
            if(x_position == (mapDisplay[y_position].size()-1)){
               /*since the room is on the edge of the vector
                * we must add a new element to encorporate the new room to the map.
                */
               mapDisplay[y_position].push_back(" --- ");
               mapDisplay[y_position].push_back(currentRoomExits["east"]->shortDescription());
               pushBackUsed = true;
            }else{
                /*setting the element to the right of the
                 * current room to that of its eastern neighbour.
                 */
                mapDisplay[y_position].at(x_position+1) =  " --- ";
                mapDisplay[y_position].at(x_position+2) =  currentRoomExits["east"]->shortDescription();
            }
        }
        if(currentRoomExits["west"]!= NULL){
            //there's a room to our west and we must now incorporate it into the map.
            if(x_position == 0){
              //if the room is at the begining of the array we must insert a new element into the start.
              mapDisplay[y_position].insert(mapDisplay[y_position].begin()," --- ");
              mapDisplay[y_position].insert(mapDisplay[y_position].begin(),currentRoomExits["west"]->shortDescription());
              insertUsed = true;
              //increment x_position variable to accuratly reflect the new position of the current room.
              x_position++;
              x_position++;
            }else{
                // if the element already exists we simply set its value to the western room.
                mapDisplay[y_position].at(x_position-1) =  " --- ";
                mapDisplay[y_position].at(x_position-2) =  currentRoomExits["west"]->shortDescription();
            }
        }
        if(currentRoomExits["south"]!= NULL){
           //there is a room to our south and we are now mapping it similar to if blocks above
           if(mapDisplay.size() == (y_position+1)){
               temp.clear();
               temp.push_back("|");
               mapDisplay.push_back(temp);

               temp.clear();
               temp.push_back(currentRoomExits["south"]->shortDescription());
               mapDisplay.push_back(temp);
            }else{
               mapDisplay[y_position+2].at(x_position) = currentRoomExits["south"]->shortDescription();
           }
        }
        if(currentRoomExits["north"]!= NULL){
           //if i == 0
            if(y_position == 0){
               temp.clear();
               temp.push_back("|");
               mapDisplay.insert(mapDisplay.begin(),temp);

               temp.clear();
               temp.push_back(currentRoomExits["north"]->shortDescription());
               mapDisplay.insert(mapDisplay.begin(),temp);
               y_position++;
               y_position++;
            }else{
                mapDisplay[y_position-2].at(x_position) = currentRoomExits["north"]->shortDescription();
            }
        }
        int largest = 0;
        for(int x = 0; x < mapDisplay.size(); x++){
              if(largest < mapDisplay[x].size()){
                  largest = mapDisplay[x].size();
              }
        }
        for(int x = 0; x < mapDisplay.size(); x++){
            if(mapDisplay[x].size() < largest){
                if(pushBackUsed){
                  mapDisplay[x].push_back("");
                }
                if(insertUsed){
                  mapDisplay[x].insert(mapDisplay[x].begin(),"");
                }

            }
        }
    }

    string textMap;
    //printing vector map
    for(int i = 0; i < mapDisplay.size(); i++){
        for(int j = 0; j < mapDisplay[i].size(); j++){
            if(mapDisplay[i][j] == "" && i%2 == 0 && i != (mapDisplay.size()-1)){
                textMap += string(mapDisplay[i+2][j].length(),' ');
            }else if(mapDisplay[i][j] == ""){
                textMap += string(mapDisplay[i+1][j].length(),' ');
            }else if(mapDisplay[i][j] == "|"){
                textMap += string((mapDisplay[i+1][j].length()+mapDisplay[i-1][j].length())/4,' ')+mapDisplay[i][j];
            }else{
                textMap += mapDisplay[i][j];
            }
        }
        textMap += "\n";
     }
    return textMap;
}
