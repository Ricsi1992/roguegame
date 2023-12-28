#pragma once
#include "Position.hpp"

namespace game
{
    struct GameUI
    {
        //Terminal size
        static const int windowWidth{120};
        static const int windowHeight{30};

        //Main play area
        static constexpr Position topLeft{0, 0};
        static const int playArewaWidth{120};
        static const int playArewaHeight{20};
    };
    
}