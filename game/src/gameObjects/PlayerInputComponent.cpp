#include "gameObjects/PlayerInputComponent.hpp"
#include <windows.h>
#undef MOUSE_MOVED
#define IS_PRESSED 0x8000

namespace game
{

void PlayerInputComponent::update()
{
    needsUpdate = false;
    if (GetKeyState('W') & IS_PRESSED)
    {
        facing = Direction::UP;
        needsUpdate = true;
    }
    else if (GetKeyState('S') & IS_PRESSED)
    {   
        facing = Direction::DOWN;
        needsUpdate = true;
    }
    else if (GetKeyState('A') & IS_PRESSED)
    {
        facing = Direction::LEFT;
        needsUpdate = true;
    }
    else if (GetKeyState('D') & IS_PRESSED)
    {
        facing = Direction::RIGHT;
        needsUpdate = true;
    }
}


}