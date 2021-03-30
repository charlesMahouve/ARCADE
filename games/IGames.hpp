/*
** EPITECH PROJECT, 2021
** Interface for games
** File description:
** Arcade
*/

#pragma once

#include <iostream>
#include "../../../graphicals/IGraphicals.hpp"

namespace Arcade
{
	class IGames {
        public:
            virtual ~IGames() = default;
            virtual std::string getGameName() const = 0;
            virtual bool initGame() = 0;
            virtual bool stopGame() = 0;
            virtual void runGame() = 0;
            virtual void updateGame() = 0;
            virtual void setGLib(IGraphicals *) = 0;
            virtual size_t getScore() const = 0;
	};
}