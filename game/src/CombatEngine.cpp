#include "CombatEngine.hpp"

namespace game
{

void CombatEngine::updatePlayer(GameObjectManager& t_gameObjectManager, std::shared_ptr <GameState> t_currentGameState,
std::map<int, std::vector<std::shared_ptr<GameObject>>> const& t_currentPositions)
{
    previousTargetPositions = targetPositions;
    targetPositions.clear();
    switch (t_gameObjectManager.playerObject->inputComponent->nextCombatAction)
    {
    case CombatAction::MELEE:
        handleMeleeAttack(t_gameObjectManager.playerObject, t_currentPositions, t_currentGameState);
        break;
    
    case CombatAction::NONE:
    default:
        break;
    }
}

void CombatEngine::handleMeleeAttack(std::shared_ptr<GameObject> t_playerObject, std::map<int, std::vector<std::shared_ptr<GameObject>>> const& t_currentPositions,
    std::shared_ptr <GameState> t_currentGameState)
{
    if (!t_playerObject->combatComponent)
    {
        return;
    }
    
    auto&& meleeAttack = t_playerObject->combatComponent->meleeAttack;
    if (!meleeAttack)
    {
        return;
    }
    
    Position& sourcePosition = t_playerObject->movementComponent->position;
    Position attackBoxTopLeft;
    int xMax = 0;
    int yMax = 0;
    
    switch (t_playerObject->inputComponent->facing)
    {
    case Direction::UP:
        attackBoxTopLeft = Position{sourcePosition.x - meleeAttack->cleave / 2, sourcePosition.y - meleeAttack->range};
        xMax = meleeAttack->cleave;
        yMax = meleeAttack->range;
        break;
    case Direction::DOWN:
        attackBoxTopLeft = Position{sourcePosition.x - meleeAttack->cleave / 2, sourcePosition.y + 1};
        xMax = meleeAttack->cleave;
        yMax = meleeAttack->range;
        break;
    case Direction::RIGHT:
        attackBoxTopLeft = Position{sourcePosition.x + 1, sourcePosition.y - meleeAttack->cleave / 2};
        xMax = meleeAttack->range;
        yMax = meleeAttack->cleave;
        break;
    case Direction::LEFT:
        attackBoxTopLeft = Position{sourcePosition.x - meleeAttack->range, sourcePosition.y - meleeAttack->cleave / 2};
        xMax = meleeAttack->range;
        yMax = meleeAttack->cleave;
        break;
    case Direction::NUMBER_OF_ELEMENTS:
    default:
        break;
    }

    auto&& currentRoom = t_currentGameState->level.rooms[t_currentGameState->level.currentRoomIndex];

    for (int y = 0; y < yMax; ++y)
    {
        for (int x = 0; x < xMax; ++x)
        {
            Position targetPosition = Position{attackBoxTopLeft.x + x, attackBoxTopLeft.y + y};

            int encodedPosition = targetPosition.y * currentRoom.width + targetPosition.x;
            targetPositions.emplace_back(targetPosition);

            if (t_currentPositions.count(encodedPosition) == 0)
            {
                continue;
            }
            
            for (auto&& object : t_currentPositions.at(encodedPosition))
            {
                if (object->combatComponent)
                {
                    object->markedForDeletion = object->combatComponent->sustainMeleeAttack(meleeAttack);
                }
            }
        }
    } 
}

}