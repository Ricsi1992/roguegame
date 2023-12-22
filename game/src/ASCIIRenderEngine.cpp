#include "ASCIIRenderEngine.hpp"
#include <sstream>
#include <iostream>

namespace game
{
    void ASCIIRenderEngine::render(std::shared_ptr<GameState> t_currentState)
    {
    if (t_currentState->currentGameState == GameStateEnum::PLAY)
    {
        system("cls");
        std::stringstream ss;

        for(int height = 0; height < t_currentState->map.height; ++height) 
        {
            for(int width = 0; width < t_currentState->map.width; ++width) 
            {
                if (height == 0 || height == t_currentState->map.height - 1 
                    || width == 0 || width == t_currentState->map.width - 1)
                {
                    ss << "#";
                }
                else if (height == t_currentState->playerPosition.y 
                    && width == t_currentState->playerPosition.x)
                {
                    ss << "@";
                }
                else if (height == t_currentState->map.end.y && width == t_currentState->map.end.x)
                {
                    ss << "X";
                }
                else
                {
                    ss << " ";
                }
            }
            ss << std::endl;
        }
        std::cout << ss.str();
    }
    
    else if (t_currentState->currentGameState == GameStateEnum::START)
    {
        system("cls");
        std::cout << "Press SPACE to play" << std::endl;
    }
    
    else if (t_currentState->currentGameState == GameStateEnum::WIN)
    {
        system("cls");
        std::cout << "YOU WON THE GAME!!!" << std::endl;
    }
    }
}