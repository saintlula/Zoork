//
// Created by Ehlinaz Duru Yildirim on 19/5/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Room.h"
#include <set>
#include <string>

//I had to use forward declaration here in addition to the "include".
class Room;
class Player
{
  public:
    Player();
    void setRoom(Room* room);
    Room* getCurrentRoom() const;
    void setCurrentRoom(Room* room);
    void look();
    void addToInventory(const std:: string& item);
    bool hasItem(const std::string& item) const;
    void removeItem(const std::string& itemName);
   // void showInventory() const;
    void openCase();
    void openChest();
    int getHealth() const { return health; }
    void setHealth(int newHealth) { health = newHealth; }
    //void showHealth() const;
    void useAntidote();
    void applyPoisonEffect();
    bool isPoisoned = false;
    int poisonTicksRemaining = 0;
    std::set<std::string> inventory;

  private:
    Room* currentRoom;
    bool chestOpened = false;
    int health = 100;
};

#endif //PLAYER_H
