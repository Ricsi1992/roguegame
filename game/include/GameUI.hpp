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

        static const char playerCharacter = '@';
        static const char emptyCharacter = ' ';
        static const char exitCharacter = 'X';
    };

    const std::vector<std::string> GameUI::title = {
"________      _____ __________    _____    ________    _____  .____     ____ ___  _____________  __.  _____",   
"\\______ \\    /  _  \\______   \\   /  _  \\  /  _____/   /  _  \\ |    |   |    |   \\/   _____/    |/ _| /  _  \\  ",
" |    |  \\  /  /_\\  \\|       _/ /  /_\\  \\/   \\  ___  /  /_\\  \\|    |   |    |   /\\_____  \\|      <  /  /_\\  \\ ",
" |    `   \\/    |    \\    |   \\/    |    \\    \\_\\  \\/    |    \\    |___|    |  / /        \\    |  \\/    |    \\",
"/_______  /\\____|__  /____|_  /\\____|__  /\\______  /\\____|__  /_______ \\______/ /_______  /____|__ \\____|__  /",
"        \\/         \\/       \\/         \\/        \\/         \\/        \\/                \\/        \\/       \\/ "
};
    
}