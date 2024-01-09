#pragma once
#include <iostream>

namespace game
{

struct MeleeAttack
{
public:
    MeleeAttack(std::string const& t_name, int const t_damage, float const t_critRate = 0, int const t_range = 1, int const t_cleave = 1)
    : name(t_name), damage(t_damage), critRate(t_critRate), range(t_range), cleave(t_cleave) {}
public:
    std::string name;
    int damage;
    float critRate = 0;
    int range = 1;
    int cleave = 1;
};


}