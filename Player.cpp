//
// Created by Ehlinaz Duru Yildirim on 19/5/2025.
//

#include "Player.h"
#include <iostream>

Player::Player() : currentRoom(nullptr) {}

void Player::setCurrentRoom(Room* room)
{
     currentRoom = room;
}

Room* Player::getCurrentRoom() const
{
  return currentRoom;
}

void Player::look()
{
  if (currentRoom != nullptr)
  {
    currentRoom->look(*this);
  }
  else
  {
    std::cout << "You seem to be.. Nowhere? Something went wrong!\n";
  }
}


void Player::addToInventory(const std::string& item)
{
  inventory.insert(item);
}

bool Player::hasItem(const std::string& item) const
{
  return inventory.find(item) != inventory.end();
}

void Player::removeItem(const std::string& itemName)
{
  auto it = inventory.find(itemName);
  if (it != inventory.end())
  {
    inventory.erase(it);
    std::cout << itemName << " has been removed from your inventory.\n";
  } else
  {
    std::cout << "You don't have " << itemName << " in your inventory.";
  }
}
