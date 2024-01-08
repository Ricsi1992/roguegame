#pragma once
#include <iostream>

namespace game
{

struct MeleeAttack
{
public:
    std::string name;
    int damage;
    float critRate = 0;
    int range = 1;
    int cleave = 1;
};


}