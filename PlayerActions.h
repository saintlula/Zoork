//
// Created by Ehlinaz Duru Yildirim on 3/6/2025.
//

// PlayerActions.h
#ifndef PLAYER_ACTIONS_H
#define PLAYER_ACTIONS_H

#include "Player.h"

class PlayerActions
{
public:
    static void useAntidote(Player& player);
    static void applyPoisonEffect(Player& player);
    static void openCase(Player& player);
    static void openChest(Player& player);
};

#endif // PLAYER_ACTIONS_H
