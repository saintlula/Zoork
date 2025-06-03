//
// Created by Ehlinaz Duru Yildirim on 3/6/2025.
//

#include "RoomConnections.h"
#include "Room.h"
#include <iostream>

void RoomConnections::connect(const std::string& direction, Room* destination)
{
    exits[direction] = destination;
}

void RoomConnections::setExit(const std::string& direction, Room* neighbour)
{
    exits[direction] = neighbour;
}

Room* RoomConnections::getExit(const std::string& direction) const
{
    auto it = exits.find(direction);
    if (it != exits.end())
    {
        return it->second;
    }
    return nullptr;
}

Room* RoomConnections::getPassage(const std::string& direction)
{
    if (exits.find(direction) != exits.end())
    {
        return exits[direction];
    }
    else
    {
        std::cout << "Seems you can't go that way!\n";
        return nullptr;
    }
}