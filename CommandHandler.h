//
// Created by Ehlinaz Duru Yildirim on 2/6/2025.
//
#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <string>
#include <vector>
#include "Player.h"
#include "PlayerUI.h"
#include "PlayerActions.h"

//Responsible for interpreting and executing player text commands
class CommandHandler
{
public:
    //Constructor takes a reference to the player whose actions will be managed
    CommandHandler(Player& playerRef);

    //Processes the player's input command and applies appropriate actions
    void handleCommand(const std::string& command, std::vector<std::string>& arguments, bool& playing, bool& playerLeftNursery);

    //Displays available commands to the player
    void printHelp() const;

private:
    Player& player; //referencing to the player object being controlled

    //handling the "go" command logic, including room transitions
    void handleGoCommand(std::vector<std::string>& arguments, bool& playerLeftNursery);
};

#endif // COMMANDHANDLER_H