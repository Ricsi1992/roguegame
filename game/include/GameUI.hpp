#pragma once
#include <vector>
#include <iostream>
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

        static const std::vector<std::string> title;
    };

    const std::vector<std::string> GameUI::title = {
" _ __ ___   __ _ _   _  ___  __ _  __ _ _ __ ___   ___ ",
"| '__/ _ \\ / _` | | | |/ _ \\/ _` |/ _` | '_ ` _ \\ / _ \\",
"| | | (_) | (_| | |_| |  __/ (_| | (_| | | | | | |  __/",
"|_|  \\___/ \\__, |\\__,_|\\___|\\__, |\\__,_|_| |_| |_|\\___|",
"           |___/            |___/               "
};
    
}