#pragma once
#include <vector>
#include <iostream>
#include <curses.h>

namespace game
{

namespace utils
{
    void mvprintw_vector(int const y, int const x, std::vector<std::string> text)
    {
        int i = 0;
        for (const std::string& row: text)
        {
            mvprintw(y + i, x, row.c_str());
            ++i;
        }
        
    }


}


}