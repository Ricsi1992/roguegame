#pragma once
#include <map>
#include "gameObjects/GameObjectManager.hpp"
#include "GameState.hpp"

namespace game
{

class CombatEngine
{
public:
    void updatePlayer(GameObjectManager& t_gameObjectManager, std::shared_ptr <GameState> t_currentGameState,
    std::map<int, std::vector<std::shared_ptr<GameObject>>> const& t_currentPositions);
    
    void handleMeleeAttack(std::shared_ptr<GameObject> t_playerObject, std::map<int, std::vector<std::shared_ptr<GameObject>>> const& t_currentPositions,
    std::shared_ptr <GameState> t_currentGameState);
public:
    std::vector<Position> targetPositions;
    std::vector<Position> previousTargetPositions;
};


}