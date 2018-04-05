#ifndef KEY_H
#define KEY_H

#include "carryableItem.h"
class key : public carryableItem{
private:
    int floorId;
    int roomId;
    void addValidCommands();
public:
    key();
    ~key();
    key(string roomName,int roomId,int floorId);
    vector<string> validRoomCommandsList();
    vector<string> validUserCommandsList();
    int getRoomId();
    int getFloorId();
};

#endif // KEY_H
