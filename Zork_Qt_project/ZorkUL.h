#ifndef ZORKUL_H_
#define ZORKUL_H_
#include <QCoreApplication>
#include <QApplication>
#include <iostream>
#include <ctime>
#include "mainwindow.h"
#include "Character.h"
#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include "floor.h"
#include "zorkhome.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:

    void getValidRooms(vector <Room *> *validRoomsForKeys, Room* nextRoom);
    bool checkForDublicates(vector <Room *> validRoomsForKeys, Room* newRoom);
    void populateRoomsWithItems();
    int currentFloor =0;
    vector<floor*> floors;
    Character user;
    Parser parser;
	Room *currentRoom;
    vector <Room *> rooms;
	void printWelcome();
	bool processCommand(Command command);
    void printHelp();
	void goRoom(Command command);
    void createItems();
    void displayItems();
    void addStairSystem();
    string go(string direction);
public:
	ZorkUL();
    ~ZorkUL();
    void play();
};

#endif /*ZORKUL_H_*/
