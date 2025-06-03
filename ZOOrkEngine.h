//
// Created by Ehlinaz Duru Yildirim on 19/5/2025.
//

#ifndef ZOORKENGINE_H
#define ZOORKENGINE_H

#include "Player.h"
#include <string>
#include <vector>
#include "CommandHandler.h"

class ZOOrkEngine
{
  public:
    ZOOrkEngine();
    void run();

  private:
    Player player;
    CommandHandler commandHandler;
    bool playerLeftNursery = false;
};

#endif //ZOORKENGINE_H
