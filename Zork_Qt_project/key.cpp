#include "key.h"

key::key(){
    description = "NULL Key";
    roomId = 0;
    floorId = 0;
    setProperties();
}
key::~key(){
}
key::key(string roomName,int roomId,int floorId){
    description = "Key for "+roomName+" on floor "+to_string(floorId);
    this->roomId = roomId;
    this->floorId = floorId;
    setProperties();
}
vector<string> key::validRoomCommandsList(){
    return validRoomCommandsList();
}

int key::getRoomId(){
    return roomId;
}
int key::getFloorId(){
    return floorId;
}


