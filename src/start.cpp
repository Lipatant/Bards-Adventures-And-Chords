/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** start.cpp
** File description:
** When the game starts
*/

#include "returned.hpp"

#include "utility/strings.hpp"
#include <iostream>
#include "engine.hpp"

using namespace engine;

int start(int const ac, char *av[], char *env[])
{
    class WindowLayer_c WindowLayer();

    std::cout << "Start" << LINEBREAK;
    std::cout << WindowLayer << LINEBREAK;
    return RETURNED_EXIT;
}
