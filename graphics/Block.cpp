/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** Block.cpp
*/

#include <iostream>
#include <allegro5/allegro_primitives.h>
#include "Block.hpp"

Block::Block(float posX, float posY, float width, float height)
{
        _posX = posX;
        _posY = posY;
        _width = width;
        _height = height;
        _finalPos = 0;
        _toRotate = true;
        _stop = false;
        _colors.push_back(std::make_pair(al_map_rgb(116, 252, 43), GREEN));
        _colors.push_back(std::make_pair(al_map_rgb(43, 106, 252), BLUE));
        _colors.push_back(std::make_pair(al_map_rgb(252, 43, 43), RED));
        _colors.push_back(std::make_pair(al_map_rgb(252, 249, 43), YELLOW));
        _colorIndex = (rand() % 4);
        _toClean = false;
}

Block::~Block()
{
}

void Block::drawMe() const
{
        al_draw_filled_rectangle(_posX, _posY, _posX + _width, _posY + _height, _colors[_colorIndex].first);
}

bool Block::eventGestion(unsigned char *key)
{
        return false;
}

bool Block::clean() const
{
        return _toClean;
}

void Block::setToClean(bool toClean)
{
        _toClean = toClean;
}

int Block::rotate()
{
        if (_toRotate) {
                _height /= 1.5;
                _toRotate = false;
        } else {
                _height *= 1.5;
                _toRotate = true;
        }
        return 0;
}

bool Block::isArrived() const
{
        return _stop;
}

bool Block::rollDown()
{
        if (_posY >= 510) {
                _stop = true;
                return false;
        }
        _posY += 10;
        _posX--;
        _width += 2;
        _height += 0.7;
        rotate();
        return true;
}

bool Block::fallBlock()
{
        if (_posY >= _finalPos) {
                _posY = _finalPos;
                _stop = true;
                return false;
        }
        _posY += 15;
        return true;
}

void Block::setX(float x)
{
        _posX = x;
}

void Block::setY(float y)
{
        _posY = y;
}

void Block::setFinalPos(int finalIndex)
{
        _stop = false;
        switch (finalIndex) {
                case (0):
                        _finalPos = 830;
                        break;
                case (1):
                        _finalPos = 790;
                        break;
                case (2):
                        _finalPos = 750;
                        break;
                case (3):
                        _finalPos = 710;
                        break;
                case (4):
                        _finalPos = 670;
                        break;
        }
}

float Block::getHeight() const
{
        return _height;
}

Color Block::getColor() const
{
        return _colors[_colorIndex].second;
}