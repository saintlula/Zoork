//
// Created by Ehlinaz Duru Yildirim on 3/6/2025.
//

//PlayerUI.h
#ifndef PLAYER_UI_H
#define PLAYER_UI_H

#include "Player.h"

//Provides user interface functions related to the player
class PlayerUI
{
public:
    //Display the player's inventory items
    static void showInventory(const Player& player);

    //Display the player's current health
    static void showHealth(const Player& player);
};

#endif // PLAYER_UI_H