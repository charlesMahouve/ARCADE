/*
** core.hpp for B-OOP-400-LYN-4-1-arcade-prince.miyigbena in /Users/charlesvictormahouve/delivery/B-OOP-400-LYN-4-1-arcade-prince.miyigbena/core/include
**
** Made by charles mahouve
** Login   <charles.mahouve>
**
** Started on  undefined Mar 28 2:37:22 PM 2021 charles mahouve
** Last update Tue Mar 29 12:35:30 AM 2021 charles mahouve
*/

#ifndef CORE_HPP_
#define CORE_HPP_
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include <map>

namespace arcade {
       class Core {
    public:
        Core(const std::string &graphicalLib);
        ~Core();

        void loadGraphicalLibrary(const std::string &path);
        void loadGameLibrary(const std::string &path);

        void run();

        std::vector<std::pair<std::string, std::string>> getControls() const;

    private:
        void refreshLibrarieLists();
        const std::vector<std::string> &getGameList() const;
        const std::vector<std::string> &getGraphicalList() const;

        void setGraphicalLibFunctions();
        void startGame();

        static std::string getDynamicLibraryName(const std::string &path);

        void setCurrentLib(const std::string &lib);
        void setCurrentGame(const std::string &game);

        void sendListsToGraphicalLib();

        void initGeneralControl();

        void getBestScoresGame();
        void saveBestScore();

        bool endGame();

        void coreClock();

        std::unique_ptr<IGraphical> _graphical;
        std::unique_ptr<IGame> _game;
        std::unique_ptr<IGame> _oldGame;

        std::string _currentGame;
        std::vector<std::string> _gameList;
        std::map<std::string, std::unique_ptr<LibraryLoader<IGame>>> _gameLoaders;

        std::string _currentGraphicalLib;
        std::vector<std::string> _graphicalList;
        std::map<std::string, std::unique_ptr<LibraryLoader<IGraphical>>> _graphicalLoaders;

        bool _quitGame;
        bool _isPaused;

        //IGraphical::Scene _scene;

        //std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> _generalControls;

        std::vector<std::pair<std::string, std::string>> _bestScoresGame;

        std::string _username;

        bool _changeLib;

        std::chrono::system_clock::time_point _startTime;
        std::chrono::system_clock::time_point _endTime;

    };
}


#endif /* !CORE_HPP_ */
