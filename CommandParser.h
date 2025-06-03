//
// Created by Ehlinaz Duru Yildirim on 2/6/2025.
//

#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <string>
#include <vector>

class CommandParser
{
public:
    static std::vector<std::string> parseCommand(const std::string& input);
};

#endif // COMMANDPARSER_H