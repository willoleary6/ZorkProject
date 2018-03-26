#include "ZorkUL.h"
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    zorkHome n;
    n.show();

    //w.show();
    /*ZorkUL temp;
    temp.play();*/
    return a.exec();
}

ZorkUL::ZorkUL() {
    srand(time(NULL));
    for(int i =0; i < 3; i++){
        if(i == 0){
            floors.push_back(new floor(0));
        }else{
            //floors.push_back(new floor());
        }
    }

    currentFloor = 0;
    addStairSystem();
    rooms = floors[currentFloor]->getRooms();
    currentRoom = rooms[0];
}
/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
    printWelcome();
    // Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.
    bool finished = false;
    Command* command;
    while (!finished) {
		// Create pointer to command and give it a command.
        command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
	}
    // Free the memory allocated by "parser.getCommand()"
    //   with ("return new Command(...)")
    delete command;
	cout << endl;
	cout << "end" << endl;
}
void ZorkUL::addStairSystem(){
    vector <Room *> lowerFloor;
    vector <Room *> upperFloor;
    int randomValue1;
    int randomValue2;
    for(int i =0; i < floors.size()-1; i++){
        lowerFloor = floors[i]->getRooms();
        randomValue1= rand()%lowerFloor.size();
        //randomValue1 = 0;
        upperFloor = floors[i+1]->getRooms();
        randomValue2= rand()%upperFloor.size();
        //randomValue2 = randomValue1;
        lowerFloor[randomValue1]->setUpstairsExit(upperFloor[randomValue2]);
        upperFloor[randomValue2]->setDownstairsExit(lowerFloor[randomValue1]);

    }
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
         cout << floors[currentFloor]->printMap() << endl;
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
    }else if (commandWord.compare("drop") == 0){
        // Added functionality for user to place item in a room

        if (!command.hasSecondWord()) {
            cout << "incomplete input"<< endl;
        }else if (command.hasSecondWord()) {
            cout << "you're trying to drop " + command.getSecondWord() << endl;
            int location = user.isItemOnCharacter(command.getSecondWord());
            if (location  < 0 ){
                cout << "item is not on you" << endl;
            }else{
                //cout << "item is on you "<< endl;
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
            //srand(time(NULL));
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
        if(direction == "upstairs"){
            currentFloor++;
            cout << "Going Up stairs!"<<endl;
        }else if(direction == "downstairs"){
            currentFloor--;
            cout << "Going downStairs!"<<endl;
        }
        rooms = floors[currentFloor]->getRooms();
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

