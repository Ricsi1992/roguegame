#pragma once
#include <vector>
#include <iostream>
#include <curses.h>

namespace game
{

namespace utils
{

void mvprintw_vector(int const y, int const x, std::vector<std::string> text);

template<typename T>
void remove_index(std::vector<T>& vector, std::vector<int> const& toRemove)
{
    auto vectorBegin = vector.begin();
    typename std::vector<T>::size_type downStepCounter = 0;

    for (auto it = toRemove.cbegin(); it < toRemove.cend(); ++it, ++downStepCounter)
    {
        typename std::vector<T>::size_type next = (it + 1 == toRemove.cend()) ? vector.size() : *(it + 1);
        std::move(vectorBegin + *it + 1, vectorBegin + next, vectorBegin + *it - downStepCounter);
    }
    vector.resize(vector.size() - toRemove.size());
}

}


}