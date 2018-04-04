#include "ZorkUL.h"
using namespace std;



/*int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //UI
    //zorkHome n;
    //n.show();

    //game
    cout << "Starting" << endl;
    ZorkUL *temp = new ZorkUL();
    //temp->play();
    delete temp;
    cout << "Finished termination" <<endl;
   // temp.play();

    return a.exec();
}*/

/**
 * @brief ZorkUL::ZorkUL
 * Constructor that seeds the random number generator.
 * populates the floors of the map and populates the map with items.
 */
ZorkUL::ZorkUL(MainWindow *ui) {
    this->ui = ui;
    //ui->updateMap();
    //seeding the random numbers with the current timestamp
    srand(time(NULL));
    for(int i =0; i < 3; i++){
        // Building each floor (containing a floor of rooms)
        floors.push_back(new floor(i));
    }
    //user will always start on floor 0 or the "basement".
    currentFloor = 0;
    //connecting the floors with a "upstairs/downstairs" exits
    addStairSystem();

    //setting the rooms on the current floor and current room
    rooms = floors[currentFloor]->getRooms();
    currentRoom = rooms[0];
    //spawn items onto the map and set the lock system with corresponding keys
    populateRoomsWithItems();

    //cout << floors[currentFloor]->printMap();
    //QString test = QString::fromStdString(floors[currentFloor]->printMap());
    //ui->updateMap(test);
}

map<string, Room*> ZorkUL::getCurrentRoomExits(){
    return currentRoom->getExits();
}
vector<string> ZorkUL::getItemValidCommands(string ItemName){
    int index = currentRoom->isItemInRoom(ItemName);
    Item* foundItem = currentRoom->getItem(index);
    return foundItem->validRoomCommandsList();
}

void ZorkUL:: getMap(){
    ui->updateMap(QString::fromStdString(floors[currentFloor]->printMap()));
}
vector<string> ZorkUL::getCurrentRoomItemNames(){
    vector<Item*> itemsInRoom = currentRoom->getItemsInRoom();
    vector <string> ItemNames;
    for(int i =0; i < itemsInRoom.size(); i++){
        ItemNames.push_back(itemsInRoom[i]->getShortDescription());
    }
    return ItemNames;
}

/**
 * @brief ZorkUL::~ZorkUL
 * Destructor clearing memory once the object is finished
 */
ZorkUL::~ZorkUL(){
    if(floors.size() > 0){
        for(int i = 0; i < floors.size(); i++){
           delete floors[i];
        }
    }
}

/**
 * @brief ZorkUL::play
 * Main play routine.  Loops until end of play.
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
}

/**
 * @brief ZorkUL::populateRoomsWithItems
 * Item spawning system, populates map with items the user can interact with.
 */
void ZorkUL::populateRoomsWithItems(){
    /* Declaring local variables to store global variables
     * so we can play with them with out bad consequences....
     */
    int downstairsIndex,randomValue;
    vector <Room *> floorRooms;
    map<string, Room*> exits;
    Room* lockedRoom;
    vector <string> searchableNames = {"trunk","bin","cabinet","press","case","casket",
                                 "crate","strongbox","box","shelf","safe","toolbox","bedstand"};
    /*Starting from floors[1] instead of floors[0] as floors[0]
     * will always only have one room - "the basement" and we cant exactly lock that room :P
     */
    for(int i =1; i < floors.size(); i++){
        //get the rooms of the floor and store the rooms in a vector.
        floorRooms = floors[i]->getRooms();
        //find the index of the room in the vector that has the downstairs exit.
        for(int j =0; j < floorRooms.size(); j++){
            exits = floorRooms[j]->getExits();
            if(exits["downstairs"] != NULL){
                downstairsIndex = j;
            }
        }
        /*we use randomValue a number of times and in this
         * case we use it to figure out how many rooms in the floor to lock.
         */
        randomValue = rand() % floorRooms.size();
        int limit = (randomValue/1.5);
        //we always want at least one room on each floor to be locked.
        if(limit == 0){
            limit++;
        }
        searchableItem *chest;
        key *lockedRoomKey;
        //now locking random rooms on the floor
        for(int k = 0; k < limit; k++){
            //find a room that isnt already locked.
            do{
                //now repurposing randomValue to generate a room index that isnt already locked.
                randomValue = rand() % floorRooms.size();
            }while(floorRooms[randomValue]->isLocked());
            //passing the pointer of the selected room to the lockedRoom variable.
            lockedRoom = floorRooms[randomValue];
            //if the door were locking contains the downstairs exit for this floor we move the key the lower floor.
            if(randomValue == downstairsIndex){

                //Set the current floor to that of the floor below it.
                floorRooms = floors[i-1]->getRooms();
                //Repurposing the randomValue to generate a random index of the rooms on the floors below us.
                randomValue = rand() % floorRooms.size();
                lockedRoomKey = lockedRoom->lockRoom();
                if((rand() % 10) < 7){
                    chest = new searchableItem(searchableNames[rand() % searchableNames.size()]);
                    chest->insertItem(lockedRoomKey);
                    floorRooms[randomValue]->addItem(chest);
               }else{
                   floorRooms[randomValue]->addItem(lockedRoomKey);
               }

            }else{
                /*Otherwise we lock the room and going from the entry point of the floor(Room with downstairs exit)
                 * we recursivly go through every room on the floor and build
                 * a list of potential rooms we can place the key in.
                 */
                lockedRoomKey = lockedRoom->lockRoom();
                vector <Room *> validRoomsForKeys;
                //calling the function to start the recursion process.
                getValidRooms(&validRoomsForKeys, floorRooms[downstairsIndex]);
                /*Place the key in one the valid rooms we found
                 * (Any room that can be accessed from the downstairs exit on the current floor from navigating its exits).
                 */
                if((rand() % 10) < 7){
                    chest = new searchableItem(searchableNames[rand() % searchableNames.size()]);
                    chest->insertItem(lockedRoomKey);
                    validRoomsForKeys[rand() % validRoomsForKeys.size()]->addItem(chest);
               }else{
                    validRoomsForKeys[rand() % validRoomsForKeys.size()]->addItem(lockedRoomKey);
               }
            }
        }
    }
}

/**
 * @brief ZorkUL::getValidRooms
 * @param validRoomsForKeys
 * @param validRoom
 * Recursive function which builds a list of all the possible rooms that can be reached from travelling from the first room provided.
 */
void ZorkUL::getValidRooms(vector <Room *> *validRoomsForKeys, Room* validRoom){
    map<string, Room*> exits = validRoom->getExits();
    //push the room unto the vector (Already established in the last recursion if the room was valid.)
    (*validRoomsForKeys).push_back(validRoom);
    vector <string> directions = {"north","south","west","east","upstairs","downstairs"};
    //for loop going through all the possible exits of each room
    for(int i =0; i< directions.size(); i++){
        //checking if we can go in that direction in the first place.
        if(exits[directions[i]] != NULL){
            /*for the room in the indexed direction to be eligible to be added to the
             * list it must not be already on the list and the room is not locked.
             */
            if(checkForDublicates(*validRoomsForKeys,exits[directions[i]]) && exits[directions[i]]->isLocked() == false){
                //Call this function again with the room in the indexed direction as the new validRoom variable.
                getValidRooms(validRoomsForKeys, exits[directions[i]]);
            }
        }
    }
}

/**
 * @brief ZorkUL::checkForDublicates
 * @param validRoomsForKeys
 * @param newRoom
 * @return
 * Function which checks a vector of Rooms if it contains the second arguement (Another Room).
 */
bool ZorkUL::checkForDublicates(vector <Room *> validRoomsForKeys, Room* newRoom){
    //going through each room of the vector.
    for(int i =0; i < validRoomsForKeys.size(); i++){
        if(validRoomsForKeys[i] == newRoom){
            //if a index of the vector is equal to newRoom return a false value as we dont want duplicates.
            return false;
        }
    }
    validRoomsForKeys.clear();
    //if we went through the entire list of rooms and didn't find any duplicates we return a true value.
    return true;
}

/**
 * @brief ZorkUL::addStairSystem
 * Function that populates a random room on two floors to link both floors with a "stairway" exit.
 */
void ZorkUL::addStairSystem(){
    vector <Room *> lowerFloor, upperFloor;
    int lowerFloorRoom, upperFloorRoom;
    //go through every floor except the last floor(cant link the top floor to the nonexistant floor above it).
    for(int i =0; i < floors.size()-1; i++){
        //set the value of the lower floor and the room to place the stair in this iteration
        lowerFloor = floors[i]->getRooms();
        lowerFloorRoom= rand()%lowerFloor.size();

        //set the value of the upper floor and the room to place the stair in this iteration
        upperFloor = floors[i+1]->getRooms();
        upperFloorRoom= rand()%upperFloor.size();

        //assign the exits for the designated rooms.
        lowerFloor[lowerFloorRoom]->setUpstairsExit(upperFloor[upperFloorRoom]);
        upperFloor[upperFloorRoom]->setDownstairsExit(lowerFloor[lowerFloorRoom]);
    }
}

/**
 * @brief ZorkUL::printWelcome
 */
void ZorkUL::printWelcome() {
    ui->updateLog(QString::fromStdString("start"));
    ui->updateLog(QString::fromStdString(currentRoom->longDescription()));
}


/**
 * @brief ZorkUL::processCommand
 * @param command
 * @return
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
        //this command prints a string map to display the current map to the user.
        cout << floors[currentFloor]->printMap() << endl;
        cout << currentRoom->longDescription() << endl;
    }else if (commandWord.compare("go") == 0){
        //change the current room to that of the direction specified my the user.
        //goRoom(command);
    }else if (commandWord.compare("take") == 0){
        // added functionality for user to take items out of a room
        if (!command.hasSecondWord()) {
            cout << "incomplete input"<< endl;
        }else if (command.hasSecondWord()) {
            takeItem(command);
        }
    }else if(commandWord.compare("unlock") == 0){
        //some rooms on the map may be locked and the keys are required to unlock them.
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
                unlockRoom(roomToUnlock,direction);
            }
        }
    }else if(commandWord.compare("search") == 0){
        // added functionality for user to search a derived version of an item(searchable)
        if (!command.hasSecondWord()){
            cout << "incomplete input"<< endl;
        }else if (command.hasSecondWord()){
            int location = currentRoom->isItemInRoom(command.getSecondWord());
            if (location  < 0 ){
                cout << "item is not in room" << endl;
            }else{
                searchItem(location);
            }
        }
    }else if (commandWord.compare("drop") == 0){
        // Added functionality for user to drop an item in a room
        if (!command.hasSecondWord()) {
            cout << "incomplete input"<< endl;
        }else if (command.hasSecondWord()) {
            cout << "you're trying to drop " + command.getSecondWord() << endl;
            int location = user.isItemOnCharacter(command.getSecondWord());
            if (location  < 0 ){
                cout << "item is not on you" << endl;
            }else{
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
            teleport(command);
        }else{
            randomTeleport();
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

/**
 * @brief ZorkUL::randomTeleport
 * This function will move the user to a random room on the floor.
 */
void ZorkUL::randomTeleport(){
    if(rooms.size() > 1){
        int randomNum;
        //added a do-while to ensure you are teleported to another room
        do{
           randomNum = rand() % rooms.size();
        }while(currentRoom == rooms.at(randomNum));
        //set room to the room that was randomly generated.
        currentRoom = rooms.at(randomNum);
        cout << currentRoom->longDescription() << endl;
    }else{
        cout << "There is only one room on this floor."<<endl;
    }
}

/**
 * @brief ZorkUL::teleport
 * @param command
 * Teleport the user to a room they have specified that is on the current floor
 */
void ZorkUL::teleport(Command command){
    bool found = false;
    //go through each room to check if the room specified matches any of the rooms short description.
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
}
/**
 * @brief ZorkUL::takeItem
 * @param command
 * This function allows a user to take an object from the room and store it in their inventory.
 */
void ZorkUL::takeItem(Command command){
    //get the index of the item in the room
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

/**
 * @brief ZorkUL::unlockRoom
 * @param roomToUnlock
 * @param direction
 * This function changes the lock status of a room and moves the user to said room.
 */
void ZorkUL::unlockRoom(Room* roomToUnlock,string direction){
    vector <Item*> usersInventory = user.getItemList();
    bool found = false;
    //check if the user first of all has anything in their inventory
    if(usersInventory.size() > 0){
        key *roomKey;
        for(int i = 0; i < usersInventory.size(); i++){
           try{
            /* userInventory is a vector of item pointers but we can store
             * derived pointers of Item in it and cast them as those derived pointers if needed.
             */
            roomKey = static_cast<key*>(usersInventory[i]);
            /*if the pointer of the key points to the same
             * location as the rooms key pointer, we then have a match
             */
            if(roomKey == roomToUnlock->getKey()){
                user.removeItem(i);
                found = true;
                roomToUnlock->unlockRoom();
                cout << "Success! "<<roomToUnlock->shortDescription()<<" is now unlocked"<<endl;
                //goRoom(Command("go",direction));
            }
           }catch(const exception& e){
                /*We dont want the program to crash if a non
                 * key object is casted to a key, we dont care about those objects anyway :P
                 */
           }
       }
       if(!found){
           cout << "You dont have the key for this door" << endl;
       }
    }else{
        cout << "You dont have any keys!" << endl;
    }
}

/**
 * @brief ZorkUL::searchItem
 * @param location
 * Function that searches a searchableItem and transfers any items stored in the searchableItem to the users.
 */
void ZorkUL::searchItem(int location){
    //checking to see if the item is carryable
    if(currentRoom->getItem(location)->isSearchable()){
        //adding item to user's inventory while also removing it from the room
        searchableItem *box = static_cast<searchableItem*>(currentRoom->getItem(location));
        box->transferItemsToCharacter(&user);
        cout << endl;
        cout << user.longDescription() << endl;
    }else{
        cout << currentRoom->getItem(location)->getShortDescription() << " cant be searched you fucking cunt!" << endl;
    }
}

/** COMMANDS **/

/**
 * @brief ZorkUL::printHelp
 */
void ZorkUL::printHelp() {
    cout << "valid inputs are; " << endl;
    parser.showCommands();
}

/**
 * @brief ZorkUL::goRoom
 * @param command
 * goRoom allows users to traverse the map using the rooms exits.
 */
void ZorkUL::goRoom(string direction) {
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
            getMap();
        }else if(direction == "downstairs"){
            currentFloor--;
            cout << "Going downStairs!"<<endl;
            getMap();
        }
        rooms = floors[currentFloor]->getRooms();
        currentRoom = nextRoom;
        ui->updateLog(QString::fromStdString("Moving "+direction));
        ui->updateLog(QString::fromStdString(currentRoom->longDescription()));
    }
}

/**
 * @brief ZorkUL::go
 * @param direction
 * @return returns a string of the rooms description and items stored in it.
 */
string ZorkUL::go(string direction) {
    //get the room in the exit in the direction specified
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL){
        return("direction null");
    }else{
        //set the current room to room were going too
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}

