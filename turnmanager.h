#pragma once
#include <vector>
#include "player.h"
#include "enemy.h"

class TurnManager {
public:
    std::vector<player*> players;
    std::vector<enemy*> enemies;
    size_t currentTurnIndex;

    TurnManager(std::vector<player*> players, std::vector<enemy*> enemies);

    void nextTurn();
    bool isPlayerTurn();
    bool isCombatOver();
    player* getCurrentPlayer();
    enemy* getCurrentEnemy();
};