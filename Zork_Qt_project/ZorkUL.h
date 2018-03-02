#ifndef ZORKUL_H_
#define ZORKUL_H_
#include "mainwindow.h"
#include "Character.h"
#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:
    Character user;
    Parser parser;
	Room *currentRoom;
    vector <Room *> rooms;
    void createRooms();
	void printWelcome();
	bool processCommand(Command command);
    bool findMapCoordinates(int index,int *x_position, int *y_position, vector<vector<string>> mapDisplay);
    void printHelp();
	void goRoom(Command command);
    void createItems();
    void displayItems();
    string printMap();
    int getLargestIndex(vector<vector<string>> mapDisplay, int i, int j);
    void generateRandomFloorPlan();

public:
	ZorkUL();
	void play();
	string go(string direction);
};

#endif /*ZORKUL_H_*/
