#pragma once
#include "gameObjects/ObjectColor.hpp"

namespace game
{

class RenderComponent
{
public:
    virtual ~RenderComponent() {}
    RenderComponent(char const t_renderChar, ObjectColor const t_color) : renderChar(t_renderChar), color(t_color) {}
public:
    char renderChar;
    ObjectColor color;
};

}