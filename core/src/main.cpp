/*
** Main.cpp for B-OOP-400-LYN-4-1-arcade-prince.miyigbena in /Users/charlesvictormahouve/delivery/B-OOP-400-LYN-4-1-arcade-prince.miyigbena/core/src
**
** Made by charles mahouve
** Login   <charles.mahouve>
**
** Started on  undefined Mar 28 2:49:13 PM 2021 charles mahouve
** Last update Mon Mar 28 2:53:01 PM 2021 charles mahouve
*/

#include <fstream>
#include <iostream>
#include "../include/core.hpp"
#include "../include/Error.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);

    try {
        arcade::Core core(av[1]);

        core.run();
    } catch (arcade::ArcadeError &error) {
        std::cerr << error.getComponent() << ": " << error.what() << std::endl;
        return (84);
    }

    return (0);
}