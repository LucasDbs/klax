/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** Platform.cpp
*/

#include "Platform.hpp"
#include "../managing/ErrorManaging.hpp"

Platform::Platform(const std::string &path)
{
        _platform = al_load_bitmap(path.c_str());
        if (!_platform)
                throw ErrorManaging("Failed to load cursor image");
        _posY = 580;
        _width = al_get_bitmap_width(_platform);
        _height = al_get_bitmap_height(_platform);
        _pos.push_back(720);
        _pos.push_back(820);
        _pos.push_back(915);
        _pos.push_back(1010);
        _pos.push_back(1110);
        _posIndex = 2;
        _posX = _pos[_posIndex];
        _toClean = false;
        _dropBlock = false;
}

Platform::~Platform()
{
        al_destroy_bitmap(_platform);
}

void Platform::drawMe() const
{
        al_draw_scaled_bitmap(_platform, 0, 0, _width, _height, _posX, _posY, 90, 40, 0);
}

bool Platform::clean() const
{
        return _toClean;
}

void Platform::setToClean(bool toClean)
{
        _toClean = toClean;
}

bool Platform::eventGestion(unsigned char *key)
{
        if (key[ALLEGRO_KEY_SPACE] && !_blocks.empty())
                _dropBlock = true;
        if (key[ALLEGRO_KEY_LEFT] && _posIndex > 0)
                _posIndex--;
        if (key[ALLEGRO_KEY_RIGHT] && _posIndex < 4)
                _posIndex++;
        _posX = _pos[_posIndex];
        for (auto &i: _blocks)
                i->setX(_pos[_posIndex]);
        return true;
}

void Platform::blockAdjust() const
{
        int total = 0;

        for (auto &i: _blocks) {
                i->setY(_posY - total - 10 - i->getHeight());
                total += (10 + i->getHeight());
        }
}

bool Platform::addBlock(Block *block, int index)
{
        if (index != _posIndex || _blocks.size() > 3) {
                block->setToClean(true);
                return false;
        }
        _blocks.push_back(block);
        _posY += 20;
        blockAdjust();
        return true;
}

bool Platform::canDrop() const
{
        return _dropBlock;
}

Block *Platform::dropBlock()
{
        Block *tmp = _blocks.back();

        _blocks.pop_back();
        _posY -= 20;
        blockAdjust();
        return tmp;
}

void Platform::setDrop(bool drop)
{
        _dropBlock = drop;
}

int Platform::getPosIndex() const
{
        return _posIndex;
}