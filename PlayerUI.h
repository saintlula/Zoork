//
// Created by Ehlinaz Duru Yildirim on 3/6/2025.
//

// PlayerUI.h
#ifndef PLAYER_UI_H
#define PLAYER_UI_H

#include "Player.h"

class PlayerUI
{
public:
    static void showInventory(const Player& player);
    static void showHealth(const Player& player);
};

#endif // PLAYER_UI_H
