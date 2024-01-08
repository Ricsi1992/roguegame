#include "gameObjects/CombatComponent.hpp"
#include "RandomGenerator.hpp"

namespace game
{

bool CombatComponent::sustainMeleeAttack(std::shared_ptr<MeleeAttack> t_attack)
{
    RandomGenerator* randomGenerator = RandomGenerator::getInstance();
    float chance = randomGenerator->getRandomFloat(1);
    int critMultiplier = 1;
    if (chance < t_attack->critRate)
    {
        critMultiplier = 2;
    }
    hp -= (t_attack->damage - defense) * critMultiplier;
    
    return hp <= 0;
}

}