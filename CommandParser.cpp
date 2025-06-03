//
// Created by Ehlinaz Duru Yildirim on 2/6/2025.
//

#include "CommandParser.h"
#include <sstream>

std::vector<std::string> CommandParser::parseCommand(const std::string& input)
{
    std::istringstream iss(input);
    std::string word;
    std::vector<std::string> tokens;

    while (iss >> word)
    {
        tokens.push_back(word);
    }
    return tokens;
}