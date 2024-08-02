#include "turnmanager.h"

TurnManager::TurnManager(std::vector<player*> players, std::vector<enemy*> enemies)
    : players(players), enemies(enemies), currentTurnIndex(0) {}

void TurnManager::nextTurn() {
    currentTurnIndex = (currentTurnIndex + 1) % (players.size() + enemies.size());
}

bool TurnManager::isPlayerTurn() {
    return currentTurnIndex < players.size();
}

bool TurnManager::isCombatOver() {
    bool allPlayersDead = std::all_of(players.begin(), players.end(), [](player* p) { return p->getCurrentHealth() <= 0; });
    bool allEnemiesDead = std::all_of(enemies.begin(), enemies.end(), [](enemy* e) { return e->health <= 0; });
    return allPlayersDead || allEnemiesDead;
}

player* TurnManager::getCurrentPlayer() {
    if (isPlayerTurn()) {
        return players[currentTurnIndex];
    }
    return nullptr;
}

enemy* TurnManager::getCurrentEnemy() {
    if (!isPlayerTurn()) {
        return enemies[currentTurnIndex - players.size()];
    }
    return nullptr;
}
