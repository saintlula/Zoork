//
// Created by Ehlinaz Duru Yildirim on 19/5/2025.
//

#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include <map>
#include "Player.h"
#include "RoomConnections.h"
extern std::atomic<bool> playerLeftNursery;

//I had to use forward declaration here in addition to the "include".
class Player;
class Room
{
private:
    int id;
    std::string name;
    std::string description;
    bool isLocked;
    std::string keyRequired;
    std::vector<std::string> items;
    std::string specialLookHint;
    bool canExamine = false;
    std::string examineDescription;
    std::string itemFound;

public:
    Room(int id, const std::string& name, const std::string& description, bool isLocked = false, const std::string& keyRequired = "",const std::string& lookHint = "");

    bool nurseryEventTriggered = false;
    RoomConnections connections;
    //Getters
    int getId() const;
    std::string getName() const;
    std::string getDescription() const;
    bool getIsLocked() const;
    std::string getKeyRequired() const;

    //Examining
    void setExamineDetails(const std:: string& description, const std::string& item);
    void examine(Player& player);

    //Items
    void addItem(const std::string& item);
    void removeItem(const std::string& item);
    std::vector<std::string> getItems() const;

    //Room connections
    void enter(bool& playerLeftNursery);
    RoomConnections& getConnections() { return connections; }
    const RoomConnections& getConnections() const { return connections; }


    //Special additions
    void look(Player& player);

};

#endif //ROOM_H
