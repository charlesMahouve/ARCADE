/*
** EPITECH PROJECT, 2021
** Aracde
** File description:
** Nibbler
*/

#pragma once

#include <iostream>
#include "../../IGames.hpp"

namespace Arcade
{
	class Nibbler : public IGames {
        public:
            Nibbler();
            ~Nibbler() override;
            bool initGame() override;
            bool stopGame() override;
            void updateGame() override;
            size_t getScore() const override;
            std::string getGameName() const override;

        private:
            std::string _game = "Nibbler";
            std::size_t _score = 0;
    };
}