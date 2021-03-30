/*
** EPITECH PROJECT, 2021
** Pacman
** File description:
** Arcade
*/

#pragma once

#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include <utility>
#include <functional>
#include "../../IGames.hpp"
#include "../../../graphicals/IGraphicals.hpp"

namespace Arcade
{
	class Pacman : public IGames {
        public:
            ///////////////////////////////////////////////////////////////////////
            /// @brief BLABLA
            /// @warning BLABLA
            ///
            /// @param ---
            /// @return BLABLA
            //
            Pacman();
            ~Pacman();
            bool initGame() override;
            bool stopGame() override;
            void updateGame() override;
            void runGame() override;
            void menu();
            char pause();
            void movePacman(char ascii);
            void setGLib(IGraphicals *) override;
            size_t getScore() const override;
            std::string getGameName() const override;

        private:
            std::string _game = "Pacman";
            std::size_t _score = 0;
            std::size_t _bestScore = 0;
            std::map<std::size_t, std::string> _map;
            IGraphicals *_glib = nullptr;
    };
}