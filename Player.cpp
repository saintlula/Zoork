//
// Created by Ehlinaz Duru Yildirim on 19/5/2025.
//
#include "Player.h"
#include <iostream>

//Constructor initializes player with no current room
Player::Player() : currentRoom(nullptr) {}

void Player::setCurrentRoom(Room* room)
{
  currentRoom = room; //Update the current room the player is in
}

Room* Player::getCurrentRoom() const
{
  return currentRoom; //Retrieve the current room pointer
}

void Player::look()
{
  if (currentRoom != nullptr)
  {
    currentRoom->look(*this); //Delegate the "look" action to the current room
  }
  else
  {
    std::cout << "You seem to be.. Nowhere? Something went wrong!\n";
  }
}

void Player::addToInventory(const std::string& item)
{
  inventory.insert(item); //add item to player's inventory
}

bool Player::hasItem(const std::string& item) const
{
  return inventory.find(item) != inventory.end(); //Check if player owns the item
}

void Player::removeItem(const std::string& itemName)
{
  auto it = inventory.find(itemName);
  if (it != inventory.end())
  {
    inventory.erase(it); //Remove item if found
    std::cout << itemName << " has been removed from your inventory.\n";
  }
  else
  {
    std::cout << "You don't have " << itemName << " in your inventory.";
  }
}
