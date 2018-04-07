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
#include <iostream>
#include <string>
#include <QString>
#include <QDebug>
class MainWindow;
using namespace std;

class ZorkUL {
private:
    void randomTeleport();
    void teleport(Command command);
    void unlockRoom(Room* roomToUnlock,string direction);
    void takeItem(Command command);
    void searchItem(int location);
    void getValidRooms(vector <Room *> *validRoomsForKeys, Room* nextRoom);

    void populateRoomsWithItems();
    void printHelp();
    void createItems();
    void displayItems();
    void addStairSystem();


    bool checkForDublicates(vector <Room *> validRoomsForKeys, Room* newRoom);
    bool processCommand(Command command);


    string go(string direction);


    //Global private Variables
    int currentFloor =0;
    vector<floor*> floors;
    Character user;
    Parser parser;
	Room *currentRoom;
    vector <Room *> rooms;
    MainWindow *ui;

public:
    ZorkUL(MainWindow *ui);
    ~ZorkUL();
    void play();
    void getMap();
    void printWelcome();
    void goRoom(string direction);
    void runCommand(string commandString);
    bool isExit();
    vector<string> getItemValidCommands(string ItemName, bool isRoom);
    vector<string> getItemValidUserCommands(string ItemName);
    vector<string> getCurrentItemNames( bool isRoom);
    map<string, Room*> getCurrentRoomExits();
};

#endif /*ZORKUL_H_*/
