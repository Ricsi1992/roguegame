#include <stdexcept>
#include "RandomGenerator.hpp"

namespace game
{
RandomGenerator* RandomGenerator::instance = nullptr;

RandomGenerator* RandomGenerator::getInstance()
{
    if (!instance)
    {
        instance = new RandomGenerator;
    }
    return instance;
}

void RandomGenerator::setSeed(int64_t const t_seed)
{
    seed = t_seed;
    generator.seed(t_seed);
}
int64_t RandomGenerator::getSeed()
{
    return seed;
}

int RandomGenerator::getRandomInt(int const t_min, int const t_max)
{
    if (seed == INVALID_SEED)
    {
        throw std::runtime_error("Must seed first");
    }

    std::uniform_int_distribution<int> distribution(t_min, t_max);
    return distribution(generator);
}
int RandomGenerator::getRandomInt(int const t_max)
{
    return getRandomInt(0, t_max);
}

float RandomGenerator::getRandomFloat(int const t_min, int const t_max)
{
    if (seed == INVALID_SEED)
    {
        throw std::runtime_error("Must seed first");
    }

    std::uniform_real_distribution<float> distribution(t_min, t_max);
    return distribution(generator);
}
float RandomGenerator::getRandomFloat(int const t_max)
{
    return getRandomFloat(0, t_max);
}

}