#include <QCoreApplication>
#include <iostream>
#include <ctime>
using namespace std;
#include "ZorkUL.h"

/*int main() {
	ZorkUL temp;
	temp.play();
	return 0;
}*/

ZorkUL::ZorkUL() {
	createRooms();
}

void ZorkUL::createRooms()  {
    /* Directly pushing rooms onto the rooms vector so im not dealing with 2 variables*/
    rooms.push_back(new Room("a"));//0
        rooms.at(0)->addItem(new Item("x", 1, 11));
        rooms.at(0)->addItem(new Item("y", 2, 22));
    rooms.push_back(new Room("b"));//1
        rooms.at(1)->addItem(new Item("xx", 3, 33));
        rooms.at(1)->addItem(new Item("yy", 4, 44));
    rooms.push_back(new Room("c"));//2
    rooms.push_back( new Room("d"));//3
    rooms.push_back(new Room("e"));//4
    rooms.push_back(new Room("f"));//5
    rooms.push_back(new Room("g"));//6
    rooms.push_back(new Room("h"));//7
    rooms.push_back( new Room("i"));//8
    rooms.push_back(new Room("j"));//9
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
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        cout << "[h] --- [f] --- [g]" << endl;
		cout << "         |         " << endl;
        cout << "         |         " << endl;
		cout << "[c] --- [a] --- [b]" << endl;
		cout << "         |         " << endl;
		cout << "         |         " << endl;
		cout << "[i] --- [d] --- [e]" << endl;
		}

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    else if(commandWord.compare("teleport") == 0){
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
    /*
    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
			return true; /**signal to quit*/
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

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}

string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}
