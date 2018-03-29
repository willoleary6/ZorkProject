#include "key.h"

key::key(){
    description = "NULL Key";
    roomId = 0;
    floorId = 0;
}

key::key(string roomName,int roomId,int floorId){
    description = "floor:"+to_string(floorId)+"-room:"+roomName+"-key";
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


