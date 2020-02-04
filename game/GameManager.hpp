/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** GameManager.hpp
*/

#if !defined(GAME_MANAGER_HPP_)
#define GAME_MANAGER_HPP_

#include "../graphics/GraphicManager.hpp"
#include "../graphics/Block.hpp"
#include "../graphics/Text.hpp"
#include "Timer.hpp"

class GameManager
{
        public:
                GameManager();
                ~GameManager();

                int startGame();
                int playGame();

        private:
                int _toGo;
                bool _run;
                int _posIndex;
                int _actualX;
                int _actualY;
                int _score;
                Timer _timer;
                GraphicManager *_graph;
                Block *_blockStart;
                Platform *_platform;
                std::vector<Text *> _text;
                std::vector<std::pair<float, float> > _pos;
                std::list<Block *> _blocksEnd;
                std::vector<std::vector<Color>> _blockMap;

                int fillBlockMap();
                bool checkBlockMap();
                bool checkForWin();
                bool checkAround(int x, int y);
                bool checkIfSame(int x, int y);
                bool checkLastBlock(int x, int y);
                void clearMap();
                bool isFull();
                int manageDrop();
};

#endif // GAME_MANAGER_HPP_
