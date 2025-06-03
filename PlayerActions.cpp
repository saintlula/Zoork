//
// Created by Ehlinaz Duru Yildirim on 3/6/2025.
//

//PlayerActions.cpp
#include "PlayerActions.h"
#include <iostream>

//Use an antidote if the player has one and is poisoned
void PlayerActions::useAntidote(Player& player)
{
  if (player.hasItem("Antidote"))
  {
    if (player.isPoisoned)
    {
      player.isPoisoned = false;
      std::cout << "You drank the antidote. You feel a cool sensation run through your veins. The poison is gone.\n";
    }
    else
    {
      std::cout << "You drink the antidote just to be safe... Nothing seems to change.\n";
    }

    player.removeItem("Antidote"); //Antidote is consumed upon use
  }
  else
  {
    std::cout << "You don’t have an antidote to use!\n";
  }
}

//Apply poison damage each turn if player is poisoned
void PlayerActions::applyPoisonEffect(Player& player)
{
  if (player.isPoisoned)
  {
    if (player.poisonTicksRemaining > 0)
    {
      player.setHealth(player.getHealth() - 2);  //Decrease health by 2 points
      player.poisonTicksRemaining--;             //Decrease poison duration
      std::cout << "You feel the poison burning in your veins... (-2 HP)\n";

      if (player.getHealth() <= 0)
      {
        std::cout << "The poison has claimed your life...\n";
        std::cout << "GAME OVER\n";
        exit(0); //End the game immediately if health reaches 0 or less
      }
    }
    else
    {
      player.isPoisoned = false; //Poison effect ends
      std::cout << "The poison fades from your body. You survived.\n";
    }
  }
}

//Attempt to open the display case in "The Taxidermy" room
void PlayerActions::openCase(Player& player)
{
  if (player.getCurrentRoom()->getName() != "The Taxidermy")
  {
    std::cout << "There's nothing to open here.\n";
    return;
  }

  if (player.hasItem("case key"))
  {
    std::cout << "You inserted the key and opened the case. You saw there was a strange, almost potion looking bottle inside of it, glowing green. On top of it you can barely make out what it says. 'Antidote'\nThe antidote has been added to your inventory.";
    player.addToInventory("Antidote");     //Add antidote to inventory
    player.removeItem("case key");          //Remove the key after use
  }
  else
  {
    std::cout << "Seems you need a key for this, and you don’t have one yet!\n";
  }
}

//Open the ancient chest, triggering a snake bite poison effect
void PlayerActions::openChest(Player& player)
{
  if (player.chestOpened)
  {
    std::cout << "Are you looking to die or something? The snake's already left!\n";
    return;
  }

  std::cout << "You open the ancient chest...\n";
  std::cout << "As the lid creaks open, a hissing sound escapes... a snake lunges and bites you!\n";

  player.isPoisoned = true;              //Player becomes poisoned
  player.poisonTicksRemaining = 48;      //Poison lasts for 48 ticks, just before the user dies. (hopefully)
  std::cout << "You've been poisoned! You must find an antidote before it's too late.\n";
  player.chestOpened = true;              //Mark chest as opened to prevent re-triggering
}