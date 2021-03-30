/*
** EPITECH PROJECT, 2021
** Main
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

Arcade::Nibbler::Nibbler()
{
}

Arcade::Nibbler::~Nibbler()
{
}

bool Arcade::Nibbler::initGame()
{
    return (true);
}

bool Arcade::Nibbler::stopGame()
{
    return (true);
}

void Arcade::Nibbler::updateGame()
{
}

size_t Arcade::Nibbler::getScore() const
{
    return (_score);
}

std::string Arcade::Nibbler::getGameName() const
{
    return (_game);
}