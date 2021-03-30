/*
** LibraryLoader.hpp for B-OOP-400-LYN-4-1-arcade-prince.miyigbena in /Users/charlesvictormahouve/delivery/B-OOP-400-LYN-4-1-arcade-prince.miyigbena/core/include
**
** Made by charles mahouve
** Login   <charles.mahouve>
**
** Started on  undefined Mar 28 2:34:38 PM 2021 charles mahouve
** Last update Mon Mar 28 2:45:58 PM 2021 charles mahouve
*/

#ifndef LIBRARYLOADER_HPP_
# define LIBRARYLOADER_HPP_
#include <string>
#include <dlfcn.h>
#include "Error.hpp"

namespace arcade {
    template <typename T>
    class LibraryLoader {
    public:
        LibraryLoader(const std::string &libpath, const std::string &constructor = CONSTRUCTOR):
            _handle(nullptr), _ctor(nullptr) {
            std::string errorMessage;

            if (libpath != "") {
                _handle = dlopen(libpath.c_str(), RTLD_LAZY | RTLD_LOCAL | RTLD_NODELETE);
                if (!_handle)
                    errorMessage = ": " + std::string(dlerror());
            }
            if (!_handle) {
                errorMessage = "Could not load dynamic library '" + libpath + "'" + errorMessage;
                throw LibraryLoaderError(errorMessage);
            }
            _ctor = reinterpret_cast<T *(*)()>(dlsym(_handle, constructor.c_str()));
            if (!_ctor)
                throw LibraryLoaderError(std::string("could not load constructor: ") + dlerror());
        }

        ~LibraryLoader() {
            if (_handle)
                dlclose(_handle);
        }

        T *getInstance() {
            return (_ctor());
        }

    private:
        void *_handle;
        T *(*_ctor)();
    };
}

#endif /* !LIBRARYLOADER_HPP_ */
