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
        static const int playAreaWidth{120};
        static const int playAreaHeight{20};

        static const int mapAreaWidth{80};
        static const int mapAreaHeight{10};
        
        static const int infoAreaWidth{40};
        static const int infoAreaHeight{10};
    };
    
}