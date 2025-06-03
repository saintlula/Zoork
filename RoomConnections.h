//
// Created by Ehlinaz Duru Yildirim on 3/6/2025.
//

#ifndef ROOMCONNECTIONS_H
#define ROOMCONNECTIONS_H

#include <string>
#include <map>

class Room;

class RoomConnections
{
public:
    void connect(const std::string& direction, Room* destination);
    void setExit(const std::string& direction, Room* neighbour);
    Room* getExit(const std::string& direction) const;
    Room* getPassage(const std::string& direction);

private:
    std::map<std::string, Room*> exits;
};

#endif // ROOMCONNECTIONS_H