/*
** Error.hpp for B-OOP-400-LYN-4-1-arcade-prince.miyigbena in /Users/charlesvictormahouve/delivery/B-OOP-400-LYN-4-1-arcade-prince.miyigbena/core/include
**
** Made by charles mahouve
** Login   <charles.mahouve>
**
** Started on  undefined Mar 28 2:34:46 PM 2021 charles mahouve
** Last update Mon Mar 28 2:54:06 PM 2021 charles mahouve
*/

#ifndef ERROR_HPP_
# define ERROR_HPP_
#include <exception>
#include <string>

namespace arcade {

    class ArcadeError: public std::exception {
    public:
        ArcadeError(const std::string &component, const std::string &message);
        const char *what() const noexcept override;
        const std::string &getComponent() const noexcept;

    private:
        std::string _component;
        std::string _message;
    };


    class DynamicLibraryLoaderError : public ArcadeError{
        public:
        DynamicLibraryLoaderError(const std::string &message);
    };

    class CoreError : public ArcadeError{
        public:
        CoreError(const std::string &message);
    };

}

#endif /* !ERROR_HPP_ */
