#include "key.h"

key::key(){
    description = "NULL Key";
    roomId = 0;
    floorId = 0;
    setProperties();
    addValidCommands();
}
key::~key(){
}
key::key(string roomName,int roomId,int floorId){
    description = "Key-for-"+roomName+"-on-floor-"+to_string(floorId);
    this->roomId = roomId;
    this->floorId = floorId;
    setProperties();
    addValidCommands();

}
void key::addValidCommands(){
    validUserCommands.push_back("unlock north");
    validUserCommands.push_back("unlock west");
    validUserCommands.push_back("unlock east");
    validUserCommands.push_back("unlock south");
    validUserCommands.push_back("unlock upstairs");
    validUserCommands.push_back("unlock downstairs");
}

vector<string> key::validRoomCommandsList(){
    //ut << "this far?" << endl;
    return validRoomCommands;
}
vector<string> key::validUserCommandsList(){
    //ut << "this far?" << endl;
    return validUserCommands;
}

int key::getRoomId(){
    return roomId;
}
int key::getFloorId(){
    return floorId;
}


