#pragma once
#include <random>

namespace game
{

class RandomGenerator
{
public:
    const int INVALID_SEED = -1;
public:
    static RandomGenerator* getInstance();
    
    void setSeed(int64_t const t_seed);
    int64_t getSeed();

    int getRandomInt(int const t_min, int const t_max);
    int getRandomInt(int const t_max);

    float getRandomFloat(int const t_min, int const t_max);
    float getRandomFloat(int const t_max);
private:
    RandomGenerator() {}
private:
    static RandomGenerator* instance;
    std::default_random_engine generator;
    int64_t seed = INVALID_SEED;
};

}