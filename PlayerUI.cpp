//
// Created by Ehlinaz Duru Yildirim on 3/6/2025.
//

// PlayerUI.cpp
#include "PlayerUI.h"
#include <iostream>

//Displays the list of items in the player's inventory
void PlayerUI::showInventory(const Player& player)
{
    if (player.inventory.empty())
    {
        std::cout << "Your inventory is empty.\n";
    }
    else
    {
        std::cout << "Inventory:\n";
        for (const auto& item : player.inventory)
        {
            std::cout << "~ " << item << "\n";
        }
    }
}

//Displays the current health of the player
void PlayerUI::showHealth(const Player& player)
{
    std::cout << "Your health is " << player.getHealth() << " HP!\n" << std::endl;
}