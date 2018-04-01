#include "ZorkUL.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // UI
    zorkHome n;
    n.show();

    // Game
    /*ZorkUL temp;
    temp.play();*/
    return a.exec();
    // return 0;
}
ZorkUL::ZorkUL() {
    srand(time(NULL));
    for(int i =0; i < 3; i++){
        floors.push_back(new floor(i));
    }
    currentFloor = 0;
    addStairSystem();
    rooms = floors[currentFloor]->getRooms();
    currentRoom = rooms[0];
    populateRoomsWithItems();

}
ZorkUL::~ZorkUL(){
    delete currentRoom;
    int i;
    for(i = 0; i < floors.size(); i++){
        delete floors[i];
    }
    for(i = 0; i < rooms.size(); i++){
        delete rooms[i];
    }
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
void ZorkUL::populateRoomsWithItems(){
    int downstairsIndex,randomValue;
    vector <Room *> floorRooms;
    map<string, Room*> exits;
    Room* lockedRoom;
    for(int i =1; i < floors.size(); i++){
        floorRooms = floors[i]->getRooms();
        for(int j =0; j < floorRooms.size(); j++){
            exits = floorRooms[j]->getExits();
            if(exits["downstairs"] != NULL){
                downstairsIndex = j;
            }
        }
        randomValue = rand() % floorRooms.size();
        int limit = (randomValue/1.5);
        if(limit == 0){
            limit++;
        }
        for(int k = 0; k < limit; k++){
            while(floorRooms[randomValue]->isLocked()){
                randomValue = rand() % floorRooms.size();
            }
            lockedRoom = floorRooms[randomValue];
            //key is downstairs
            if(randomValue == downstairsIndex){
                floorRooms = floors[i-1]->getRooms();
                randomValue = rand() % floorRooms.size();
                floorRooms[randomValue]->addItem(lockedRoom->lockRoom());

            }else{
                key *temp = lockedRoom->lockRoom();
                vector <Room *> validRoomsForKeys;
                getValidRooms(&validRoomsForKeys, floorRooms[downstairsIndex]);
                int keyRoom= rand() % validRoomsForKeys.size();
                validRoomsForKeys[keyRoom]->addItem(temp);
            }
        }

    }
}
void ZorkUL::getValidRooms(vector <Room *> *validRoomsForKeys, Room* validRoom){
    map<string, Room*> exits = validRoom->getExits();
    (*validRoomsForKeys).push_back(validRoom);
    vector <string> directions = {"north","south","west","east","upstairs","downstairs"};
    for(int i =0; i< directions.size(); i++){
        if(exits[directions[i]] != NULL){
            if(checkForDublicates(*validRoomsForKeys,exits[directions[i]]) && exits[directions[i]]->isLocked() == false){
                getValidRooms(validRoomsForKeys, exits[directions[i]]);
            }
        }
    }
}
bool ZorkUL::checkForDublicates(vector <Room *> validRoomsForKeys, Room* newRoom){
    for(int i =0; i < validRoomsForKeys.size(); i++){
        if(validRoomsForKeys[i] == newRoom){
            return false;
        }
    }
    return true;
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
                //checking to see if the item is carryable

                if(currentRoom->getItem(location)->isCarryable()){
                    //adding item to user's inventory while also removing it from the room
                    user.addItem(currentRoom->removeItem(location));
                    cout << endl;
                    cout << user.longDescription() << endl;
                }else{
                    cout << currentRoom->getItem(location)->getShortDescription() << " seems to be nailed to the fucking floor you bell end." << endl;
                }
            }
        }
    }else if(commandWord.compare("unlock") == 0){
        if (!command.hasSecondWord()) {
            cout << "incomplete input"<< endl;
        }else{
            string direction = command.getSecondWord();
            // Try to leave current room.
            Room* roomToUnlock = currentRoom->nextRoom(direction);
            if (roomToUnlock == NULL){
                cout << "underdefined input"<< endl;
            }else if(!(roomToUnlock->isLocked())){
                cout << "Room is already unlocked" << endl;
            }else{
                vector <Item*> usersInventory = user.getItemList();
                bool found = false;
                if(usersInventory.size() > 0){
                    key *roomKey;
                    for(int i = 0; i < usersInventory.size(); i++){
                       try{
                        roomKey = static_cast<key*>(usersInventory[i]);
                        if(roomKey == roomToUnlock->getKey()){
                            user.removeItem(i);
                            found = true;
                            roomToUnlock->unlockRoom();
                            cout << "Success! "<<roomToUnlock->shortDescription()<<" is now unlocked"<<endl;
                            goRoom(Command("go",direction));
                        }
                       }catch(const exception& e){

                       }
                   }
                   if(!found){
                       cout << "You dont have the key for this door" << endl;
                   }
                   //cout << "Found key" << endl;
                }else{
                    cout << "You dont have any keys!" << endl;

                }
            }
        }
        //TODO implement a system that checks user inventory for a key of the locked door
    }else if(commandWord.compare("search") == 0){
        // added functionality for user to take items out of a room
        if (!command.hasSecondWord()) {
            cout << "incomplete input"<< endl;
        }else if (command.hasSecondWord()) {
            cout << "you're trying to search " + command.getSecondWord() << endl;
            int location = currentRoom->isItemInRoom(command.getSecondWord());
            if (location  < 0 ){
                cout << "item is not in room" << endl;
            }else{
                //checking to see if the item is carryable

                if(currentRoom->getItem(location)->isSearchable()){

                    //adding item to user's inventory while also removing it from the room
                    //user.addItem(currentRoom->removeItem(location));
                    searchableItem *box = static_cast<searchableItem*>(currentRoom->getItem(location));
                    box->transferItemsToCharacter(&user);
                    cout << endl;
                    cout << user.longDescription() << endl;
                }else{
                    cout << currentRoom->getItem(location)->getShortDescription() << " cant be searched you fucking cunt!" << endl;
                }
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
    }else if(nextRoom->isLocked()){
        cout << nextRoom->shortDescription()<<" is locked, find the key and unlock it !" << endl;
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

