/*
** Error.cpp for B-OOP-400-LYN-4-1-arcade-prince.miyigbena in /Users/charlesvictormahouve/delivery/B-OOP-400-LYN-4-1-arcade-prince.miyigbena/core/src
**
** Made by charles mahouve
** Login   <charles.mahouve>
**
** Started on  undefined Mar 28 2:35:41 PM 2021 charles mahouve
** Last update Mon Mar 28 8:23:34 PM 2021 charles mahouve
*/

#include "Error.hpp"

#include "LibraryLoader.hpp"

using namespace arcade;

ArcadeError::ArcadeError(const std::string &component, const std::string &message):
    _component(component), _message(message)
{}

const char *ArcadeError::what() const noexcept
{
    return (_message.c_str());
}

const std::string &ArcadeError::getComponent() const noexcept
{
    return (_component);
}

DynamicLibraryLoaderError::DynamicLibraryLoaderError(const std::string &message):
    ArcadeError("Library Loader", message)
{}

CoreError::CoreError(const std::string &message):
    ArcadeError("Core", message)
{}