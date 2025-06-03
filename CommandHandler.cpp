//
// Created by Ehlinaz Duru Yildirim on 2/6/2025.
//

#include "CommandHandler.h"
#include <iostream>
#include <algorithm>

CommandHandler::CommandHandler(Player& playerRef) : player(playerRef) {}

void CommandHandler::handleCommand(const std::string& command, std::vector<std::string>& arguments, bool& playing, bool& playerLeftNursery)
{
    if (command == "go")
    {
        handleGoCommand(arguments, playerLeftNursery);
        player.applyPoisonEffect();
    }
    else if (command == "look")
    {
        player.getCurrentRoom()->look(player);
    }
    else if (command == "examine")
    {
        player.getCurrentRoom()->examine(player);
    }
    else if (command == "open")
    {
        player.openCase();
    }
    else if (command == "reveal")
    {
        player.openChest();
    }
    else if (command == "quit")
    {
        std::cout << "You've been teleported to the exit door and you have walked out. Goodbye! For now!\n";
        playing = false;
    }
    else if (command == "inventory" || command == "i")
    {
        player.showInventory();
    }
    else if (command == "drop")
    {
        if (arguments.empty())
        {
            std::cout << "Drop what? Please specify an item name. You can type 'i' to see your inventory.\n";
        }
        else
        {
            std::string itemName;
            for (size_t i = 0; i < arguments.size(); ++i)
            {
                itemName += arguments[i];
                if (i != arguments.size() - 1) itemName += " ";
            }
            std::transform(itemName.begin(), itemName.end(), itemName.begin(), ::tolower);
            player.removeItem(itemName);
        }
    }
    else if (command == "health" || command == "h")
    {
        player.showHealth();
    }
    else if (command == "use")
    {
        if (arguments.empty())
        {
            std::cout << "Use what? Please specify an item.\n";
        }
        else
        {
            std::string item = arguments[0];
            if (item == "Antidote")
            {
                player.useAntidote();
            }
            else
            {
                std::cout << "You can't use that right now.\n";
            }
        }
    }
    else if (command == "help")
    {
        printHelp();
    }
    else
    {
        std::cout << "Oof. The developer has not added this command! Please try again!\nFor the command list say 'help'";
    }
}

void CommandHandler::handleGoCommand(std::vector<std::string>& arguments, bool& playerLeftNursery)
{
    if (arguments.empty())
    {
        std::cout << "Go where?\n";
        return;
    }

    std::string direction = arguments[0];
    Room* currentRoom = player.getCurrentRoom();
    Room* nextRoom = currentRoom->connections.getExit(direction);

    if (nextRoom == nullptr)
    {
        std::cout << "Hey, no, stop please! You can't go there.\n";
    }
    else
    {
        if (currentRoom->getName() == "The Nursery")
        {
            playerLeftNursery = true;
        }

        player.setCurrentRoom(nextRoom);
        nextRoom->enter(playerLeftNursery);
    }
}

void CommandHandler::printHelp() const
{
    std::cout << "~~Available commands are~~\n";
    std::cout << " go <direction>   ~~ Move in a direction. North, south, east, west\n";
    std::cout << " inventory/i      ~~ Shows your inventory.\n";
    std::cout << " drop<item name>  ~~ Drops an item from your inventory. But please be careful, if you drop it, it's gone. Forever.\n";
    std::cout << " use<item name>   ~~ Allows you to use the item you want, given it is usable.\n";
    std::cout << " look             ~~ Look around the room you are in\n";
    std::cout << " examine          ~~ Examine the part of room you are in.\n";
    std::cout << " quit             ~~ Teleports you to the exit door, so you can walk straight out and exit!\n";
    std::cout << " help             ~~ Shows this help message!\n";
}