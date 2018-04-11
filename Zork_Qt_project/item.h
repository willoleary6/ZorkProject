#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Item {
private:

protected:
    string description;
    string longDescription;
    int weightGrams;
    float value;
    bool weaponCheck;
    bool carryable;
    bool searchable;
    virtual void setProperties();
    vector<string> validRoomCommands;
    vector<string> validUserCommands;
public:
    Item();
    virtual ~Item();
    virtual vector<string> validRoomCommandsList() = 0;
    virtual vector<string> validUserCommandsList() = 0;
    Item (string description, int inWeight, float inValue);
    Item (string description);
    string getShortDescription();
    string getLongDescription();
    bool isCarryable();
    bool isSearchable();
};

#endif /*ITEM_H_*/
