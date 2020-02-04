/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** GameManager.cpp
*/

#include <string>
#include "GameManager.hpp"

GameManager::GameManager()
{
        _graph = new GraphicManager();
        _posIndex = 0;
        _toGo = 3;
        _score = 0;
        _timer = Timer();
        _run = true;
        _actualX = 0;
        _actualY = 0;
        _blockStart = nullptr;
        _platform = nullptr;
        srand(time(0));
        _pos.push_back(std::make_pair(755, 172));
        _pos.push_back(std::make_pair(852, 172));
        _pos.push_back(std::make_pair(952, 172));
        _pos.push_back(std::make_pair(1047, 172));
        _pos.push_back(std::make_pair(1145, 172));
        for (int i = 0; i != 5; i++)
                _blockMap.push_back(std::vector<Color>(5, NO_COLOR));
}

GameManager::~GameManager()
{
        delete _graph;
        delete _blockStart;
        delete _platform;
}

bool GameManager::checkBlockMap()
{
        int tmpIndex = _platform->getPosIndex();

        for (int i = 0; i != 5; i++) {
                if (_blockMap[i][tmpIndex] == NO_COLOR)
                        return true;
        }
        return false;
}

int GameManager::fillBlockMap()
{
        int tmpindex = _platform->getPosIndex();
        Color tmpColor = _blocksEnd.back()->getColor();
        int i = 0;

        while (_blockMap[i][tmpindex] != NO_COLOR)
                i++;
        _blockMap[i][tmpindex] = tmpColor;
        _blocksEnd.back()->setFinalPos(i);
        return 0;
}

bool GameManager::checkLastBlock(int x, int y)
{
        int vectorX = x - _actualX;
        int vectorY = y - _actualY;

        x += vectorX;
        y += vectorY;
        if ((x < 0 || x > 4) || (y < 0 || y > 4))
                return false;
        if (_blockMap[x][y] == _blockMap[_actualX][_actualY])
                return true;
        return false;
}

bool GameManager::checkIfSame(int x, int y)
{
        if ((x < 0 || x > 4) || (y < 0 || y > 4))
                return false;
        if (_blockMap[x][y] == _blockMap[_actualX][_actualY])
                return checkLastBlock(x, y);
        return false;
}

bool GameManager::checkAround(int x, int y)
{
        int i = 0;

        for (i = 0; i != 2; i++, y++) {
                if (checkIfSame(x, y))
                        return true;
        }
        for (i = 0; i != 2; i++, x++) {
                if (checkIfSame(x, y))
                        return true;
        }
        for (i = 0; i != 2; i++, y--) {
                if (checkIfSame(x, y))
                        return true;
        }
        for (i = 0; i != 2; i++, x--) {
                if (checkIfSame(x, y))
                        return true;
        }
        return false;
}

bool GameManager::checkForWin()
{
        for (_actualX = 0; _actualX != 5; _actualX++) {
                for (_actualY = 0; _actualY != 5; _actualY++) {
                        if (_blockMap[_actualX][_actualY] != NO_COLOR && checkAround(_actualX - 1, _actualY - 1))
                                return true;
                }
        }
        return false;
}

void GameManager::clearMap()
{
        for (int x = 0; x != 5; x++) {
                for (int y = 0; y != 5; y++)
                        _blockMap[x][y] = NO_COLOR;
        }
}

bool GameManager::isFull()
{
        for (int x = 0; x != 5; x++) {
                for (int y = 0; y != 5; y++) {
                        if (_blockMap[x][y] == NO_COLOR)
                                return false;
                }
        }
        return true;
}

int GameManager::manageDrop()
{
        if (_platform->canDrop()) {
                if (checkBlockMap()) {
                        _blocksEnd.push_back(_platform->dropBlock());
                        fillBlockMap();
                        _timer.setInterval<Block *, bool (Block::*)()>(_blocksEnd.back(), &Block::fallBlock, 50);
                }
                _platform->setDrop(false);
        } else if (!_blocksEnd.empty() && _blocksEnd.back()->isArrived()) {
                if (isFull()) {
                        _run = false;
                        std::cout << "Lose" << std::endl;
                        return 0;
                }
                if (checkForWin()) {
                        _score += 20 * _blocksEnd.size();
                        for (auto &i: _blocksEnd)
                                i->setToClean(true);
                        _blocksEnd.clear();
                        clearMap();
                        _toGo--;
                        if (_toGo == 0) {
                                _run = false;
                                std::cout << "Congratulations" << std::endl;
                                return 0;
                        }
                        _text[0]->setMsg("TO GO : " + std::to_string(_toGo));
                        _text[1]->setMsg("SCORE : " + std::to_string(_score));
                }
        }
        return 0;
}

int GameManager::playGame()
{
        if (!_blockStart) {
                _posIndex = (rand() % 5);
                _blockStart = _graph->createBlock(_pos[_posIndex].first, _pos[_posIndex].second, 20, 5);
                _timer.setInterval<Block *, bool (Block::*)()>(_blockStart, &Block::rollDown, 120);
        } else if (_blockStart->isArrived()) {
                if (!_platform->addBlock(_blockStart, _posIndex)) {
                        _score -= 10;
                        _text[1]->setMsg("SCORE : " + std::to_string(_score));
                }
                _blockStart = nullptr;
        }
        manageDrop();
        return 0;
}

int GameManager::startGame()
{
        _graph->createBackground("assets/background.png");
        _platform = _graph->createPlatform("assets/platform.png");
        _graph->startTimer();
        _graph->createText(90, 900, 10, "KLAX");
        _text.push_back(_graph->createText(70, 1400, 920, "TO GO : " + std::to_string(_toGo)));
        _text.push_back(_graph->createText(70, 150, 920, "SCORE : " + std::to_string(_score)));
        while (_run) {
                _run = _graph->eventManagement();
                playGame();
                _graph->drawAll();
        }
        std::cout << "Final score: " << _score << std::endl;
        return 0;
}
