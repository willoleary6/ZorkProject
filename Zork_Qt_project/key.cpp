#include "key.h"

key::key(){
    description = "NULL Key";
    roomId = 0;
    floorId = 0;
}

key::key(string roomName,int roomId,int floorId){
    description = roomName+"-key"; //for room "+roomName+" on floor "+to_string(floorId);
    this->roomId = roomId;
    this->floorId = floorId;
    setProperties();
}
int key::getRoomId(){
    return roomId;
}
int key::getFloorId(){
    return floorId;
}


