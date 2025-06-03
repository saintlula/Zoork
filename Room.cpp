//
// Created by Ehlinaz Duru Yildirim on 19/5/2025.
//

#include "Room.h"
#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>
#include <atomic>

//Atomic flag to indicate if the player has left the nursery (for event timing)
std::atomic<bool> playerLeftNursery(false);
//Constructor initializing room attributes
Room::Room(int id, const std::string& name, const std::string& description, bool isLocked, const std::string& keyRequired, const std::string& lookHint)
    : id(id), name(name), description(description), isLocked(isLocked), keyRequired(keyRequired), specialLookHint(lookHint) {}

int Room::getId() const {return id;}
std::string Room::getName() const {return name;}
std::string Room::getDescription() const {return description;}
bool Room::getIsLocked() const {return isLocked;}
std::string Room::getKeyRequired() const {return keyRequired;}
void Room::addItem(const std::string& item) {items.push_back(item); }

//looking command.
void Room::look(Player& player)
{
    if (name == "Library")
    {
        std::cout << "Some of the books look funny. Would you like to examine them further? (yes/no)\n";
        std::string choice;
        std::getline(std::cin, choice);

        if (choice == "yes")
        {
            //Checking if key is still in the room
            std::vector<std::string> roomItems = getItems();
            if (std::find(roomItems.begin(), roomItems.end(), "case key") == roomItems.end())
            {
                std::cout << "You already took the key from the hollow book earlier.\n";
                return;
            }

            std::cout << "You took the funny looking book and opened it. You saw that inside of the book was carved, and inside the hollow book was a key! Looks like it could open a.. case? It's pretty small.\n";
            std::cout << "Would you wanna take it? (yes/no)\n";

            std::string takeChoice;
            std::getline(std::cin, takeChoice);
            std::transform(takeChoice.begin(), takeChoice.end(), takeChoice.begin(), ::tolower);

            if (takeChoice == "yes")
            {
                player.addToInventory("case key");
                removeItem("case key");  // Remove the key from the room
                std::cout << "The key has been added to your inventory.\n";
            }
            else
            {
                std::cout << "You did noy investigate the funny looking books, and left.\n";
            }
        }
        if (choice == "no")
        {
            std::cout << "Okay, you left the key inside the hollow book.\n";
        }
    }
    else if (name == "The Taxidermy")
    {
        std::cout << "You creep closer and see a case underneath the paws of one of the sneering animals. It's almost entirely made out of.. fur. A shiver runs down your spine but you can see a key hole at the front. Would you like to open it? (open)\n";
    }

    else
    {
        if (!specialLookHint.empty())
        {
            std::cout << specialLookHint << std::endl;
        }
        else
        {
            std::cout << "You looked but there was nothing interesting." << std::endl;
        }
    }
}


//removing the items that are found
void Room::removeItem(const std::string& item)
{
    auto it = std::find(items.begin(), items.end(), item);
    if (it != items.end())
    {
        items.erase(it);
    }
}

//getting the items that are found
std::vector<std::string> Room::getItems() const
{
    return items;
}

void Room::setExamineDetails(const std::string& description, const std::string& item)
{
    examineDescription = description;
    itemFound = item;
    canExamine = true;
}

void Room::examine(Player& player)
{
    if (!canExamine)
    {
        std::cout << "There is nothing interesting to examine here.\n";
        return;
    }

    std::cout << examineDescription << std::endl;
    player.addToInventory(itemFound);
    canExamine = false; //to avoid doubles.
}
//Handles player entering the room and triggers special events when entered.
void Room::enter(bool& playerLeftNursery)
{
    std::cout << "You are in " << name << "\n";
    std::cout << description << "\n";
    if (isLocked)
    {
        std::cout << "Yikes! This room is locked.\n";
    }
    if (!specialLookHint.empty())
    {
        std::cout << specialLookHint << std::endl;
    }

    if (name == "The Nursery" && !nurseryEventTriggered)
    {
        nurseryEventTriggered = true;
        //Run event on a separate thread so it doesn't block main flow
        std::thread([&]()
        {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            if (playerLeftNursery) return;

            std::cout << "\nOH MY GOD RUN, LEAVE QUICK! PRESS ENTER TO JUMP INTO THE NEXT ROOM! IT'S COMING.\n";
            //Countdown from 20 seconds with checks if player leaves
            for (int i = 20; i > 0; --i)
            {
                if (playerLeftNursery) return;
                std::cout << i << "...\n";
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            //If countdown finishes, end game
            std::cout << "It's too late... Something bad is coming.\n";
            std::exit(0);

        }).detach();
    }
}


