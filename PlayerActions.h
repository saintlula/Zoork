//
// Created by Ehlinaz Duru Yildirim on 3/6/2025.
//

// PlayerActions.h
#ifndef PLAYER_ACTIONS_H
#define PLAYER_ACTIONS_H

#include "Player.h"

//Static class containing actions that can be performed by the player
class PlayerActions
{
public:
    //Use an antidote to cure poison if available
    static void useAntidote(Player& player);

    //Apply ongoing poison damage effect each turn
    static void applyPoisonEffect(Player& player);

    //Attempt to open the display case (requires key)
    static void openCase(Player& player);

    //Open an ancient chest that triggers a poison snake bite
    static void openChest(Player& player);
};

#endif // PLAYER_ACTIONS_H
