/*
** EPITECH PROJECT, 2021
** Interface for graphicals
** File description:
** Arcade
*/

#pragma once

#include <iostream>

namespace Arcade
{
	class IGraphicals {
        public:
            virtual ~IGraphicals() = default;
            virtual void setAssetDir(std::string) = 0;
            virtual void printMenu(std::string) = 0;
            virtual void printPauseMenu(std::string) = 0;
            virtual void display() = 0;
            virtual void clear() = 0;
            virtual size_t getEvent() const = 0;
            virtual std::string getGraphicalName() const = 0;
	};
}