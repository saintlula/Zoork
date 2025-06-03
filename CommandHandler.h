//
// Created by Ehlinaz Duru Yildirim on 2/6/2025.
//

#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <string>
#include <vector>
#include "Player.h"
#include "PlayerUI.h"

class CommandHandler
{
public:
    CommandHandler(Player& playerRef);

    void handleCommand(const std::string& command, std::vector<std::string>& arguments, bool& playing, bool& playerLeftNursery);

    void printHelp() const;

private:
    Player& player;

    void handleGoCommand(std::vector<std::string>& arguments, bool& playerLeftNursery);
};

#endif // COMMANDHANDLER_H