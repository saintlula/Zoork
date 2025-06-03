//
// Created by Ehlinaz Duru Yildirim on 19/5/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Room.h"
#include <set>
#include <string>

//Forward declaration of Room to avoid circular dependency
class Room;

class Player
{
public:
  Player();

  //Sets the player's current room (alternate method, possibly unused)
  void setRoom(Room* room);

  //returns a pointer to the player's current room
  Room* getCurrentRoom() const;

  //Sets the player's current room
  void setCurrentRoom(Room* room);

  //Player looks around the current room
  void look();

  //Adds an item to the player's inventory
  void addToInventory(const std::string& item);

  //Checks if the player has a specific item
  bool hasItem(const std::string& item) const;

  //Removes an item from the player's inventory
  void removeItem(const std::string& itemName);

  //Gets the current health of the player
  int getHealth() const { return health; }

  //Sets the player's health to a new value
  void setHealth(int newHealth) { health = newHealth; }

  bool isPoisoned = false;          //Indicates if the player is poisoned
  int poisonTicksRemaining = 0;     //Number of poison ticks left

  std::set<std::string> inventory; //Player's inventory of item names

  bool chestOpened = false;         //Tracks if player has opened the chest

private:
  Room* currentRoom;   //Pointer to the room player is currently in
  int health = 100;    //Player's health starting at 100
};

#endif //PLAYER_H
