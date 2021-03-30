/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Pacman
*/

#include "Pacman.hpp"

Arcade::Pacman::Pacman()
{
    std::ifstream map("assets/pacman/map.txt");
    std::string line;
    if (map.is_open()) {
        for (size_t i = 0; getline(map, line); i++)
            _map[i] = line;
        map.close();
    } else
        throw std::invalid_argument("Unable to open pacman map file");
}

Arcade::Pacman::~Pacman()
{
}

void Arcade::Pacman::setGLib(IGraphicals *glib)
{
    _glib = glib;
}

bool Arcade::Pacman::initGame()
{
    _glib->setAssetDir("assets/pacman/");
    return (true);
}

bool Arcade::Pacman::stopGame()
{
    return (true);
}

void Arcade::Pacman::updateGame()
{
}

size_t Arcade::Pacman::getScore() const
{
    return (_score);
}

std::string Arcade::Pacman::getGameName() const
{
    return (_game);
}

void Arcade::Pacman::menu()
{
    char ascii = 0;
	while (1) {
		ascii = _glib->getEvent();
		switch (ascii) {
			case 27:
				exit (0);
			case ' ':
				return;
			default:
				break;
		}
		_glib->printMenu(getGameName());
	}
}

char Arcade::Pacman::pause()
{
    char ascii = 0;
	while (1) {
		ascii = _glib->getEvent();
		switch (ascii) {
			case 27:
				exit (0);
			case ' ':
				return (ascii);
			default:
				break;
		}
		_glib->printPauseMenu(getGameName());
	}
}

void Arcade::Pacman::movePacman(char keyPressed)
{
}

void Arcade::Pacman::runGame()
{
    char ascii;
    menu();
    _glib->clear();
    initGame();
	while (1) {
		_glib->display();
		ascii = _glib->getEvent();
		switch (ascii) {
			case 27:
				return ;
			case ' ':
				ascii = pause();
				if (ascii != ' ')
    				return ;
				break;
			default:
				break;
		}
        movePacman(ascii);
	}
}
