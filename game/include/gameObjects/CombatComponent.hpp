#pragma once
#include <memory>
#include "gameObjects/combat/MeleeAttack.hpp"

namespace game
{

class CombatComponent
{
public:
    CombatComponent(int const t_hp, int const t_defence, std::shared_ptr<MeleeAttack> t_meleeAttack = nullptr) : 
    hp(t_hp), defense(t_defence), meleeAttack(t_meleeAttack) {}
    virtual ~CombatComponent() {}
    bool sustainMeleeAttack(std::shared_ptr<MeleeAttack> t_attack);
public:
    int hp = 0;
    int defense = 0;
    std::shared_ptr<MeleeAttack> meleeAttack;
};

}