#include "ZOOrkEngine.h"
#include "RoomBuilder.h"
#include "CommandParser.h"
#include "CommandHandler.h"
#include <iostream>
#include <sstream>

//Constructor
ZOOrkEngine::ZOOrkEngine() : commandHandler(player)
{
    player.setCurrentRoom(RoomBuilder::buildWorld());
}

void ZOOrkEngine::run() {
    std::cout << "Welcome to ZOOrk! If you have played before go ahead and enter the room your heart pleases.\nIf you're new here, that's ok! Type 'help' for the commands.\n";
    std::cout << "You are alive and well. Starting HP: " << player.getHealth() << "\n";

    bool playing = true;
    while (playing)
    {
        std::cout << "\n";
        std::string input;
        std::getline(std::cin, input);

        // New check: if input empty AND player in Nursery, auto move west
        if (input.empty() && player.getCurrentRoom()->getName() == "The Nursery")
        {
            std::vector<std::string> autoGo = {"west"};
            commandHandler.handleCommand("go", autoGo, playing, playerLeftNursery);
            continue;  // skip normal command processing this iteration
        }

        std::vector<std::string> tokens = CommandParser::parseCommand(input);
        if (tokens.empty()) continue;

        std::string command = tokens[0];
        tokens.erase(tokens.begin());

        commandHandler.handleCommand(command, tokens, playing, playerLeftNursery);
    }
}

