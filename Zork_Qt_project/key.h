#ifndef KEY_H
#define KEY_H

#include "carryableItem.h"
class key : public carryableItem{
private:
    int floorId;
    int roomId;
public:
    key();
    ~key();
    key(string roomName,int roomId,int floorId);
    int getRoomId();
    int getFloorId();
};

#endif // KEY_H
