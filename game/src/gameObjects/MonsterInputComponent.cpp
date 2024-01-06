#include "gameObjects/MonsterInputComponent.hpp"
#include "RandomGenerator.hpp"

namespace game
{

void MonsterInputComponent::update()
{
    RandomGenerator* randomGenerator = RandomGenerator::getInstance();
    Direction randomDirection = static_cast<Direction>(randomGenerator->getRandomInt(0, static_cast<int>(Direction::NUMBER_OF_ELEMENTS) - 1));
    facing = randomDirection;
    needsUpdate = true;
}    

}

