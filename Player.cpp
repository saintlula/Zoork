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

void Player::applyPoisonEffect()
{
  if (isPoisoned)
  {
    if (poisonTicksRemaining > 0)
    {
      health -= 2; // poison deals 1 damage per tick
      poisonTicksRemaining--;
      std::cout << "You feel the poison burning in your veins... (-2 HP)\n";

      if (health <= 0)
      {
        std::cout << "The poison has claimed your life...\n";
        std::cout << "GAME OVER\n";
        exit(0);
      }
    }
    else
    {
      isPoisoned = false;
      std::cout << "The poison fades from your body. You survived.\n";
    }
  }
}

void Player::useAntidote()
{
  if (hasItem("Antidote"))
  {
    if (isPoisoned)
    {
      isPoisoned = false;
      std::cout << "You drank the antidote. You feel a cool sensation run through your veins. The poison is gone.\n";
    }
    else
    {
      std::cout << "You drink the antidote just to be safe... Nothing seems to change.\n";
    }

    removeItem("Antidote");
  }
  else
  {
    std::cout << "You don’t have an antidote to use!\n";
  }
}

void Player::openCase()
{
  if (currentRoom->getName() != "The Taxidermy")
  {
    std::cout << "There's nothing to open here.\n";
    return;
  }

  if (hasItem("case key"))
  {
    std::cout << "You inserted the key and opened the case. You saw there was a strange, almost potion looking bottle inside of it, glowing green. On top of it you can barely make out what it says. 'Antidote'\nThe antidote has been added to your inventory.";
    addToInventory("Antidote");
    removeItem("case key");
  }
  else
  {
    std::cout << "Seems you need a key for this, and you don’t have one yet!\n";
  }
}

void Player::openChest()
{
  if (chestOpened)
  {
    std::cout << "Are you looking to die or something? The snake's already left!\n";
    return;
  }

  std::cout << "You open the ancient chest...\n";
  std::cout << "As the lid creaks open, a hissing sound escapes... a snake lunges and bites you!\n";

  isPoisoned = true;
  poisonTicksRemaining = 48;
  std::cout << "You've been poisoned! You must find an antidote before it's too late.\n";
  chestOpened = true;
}
