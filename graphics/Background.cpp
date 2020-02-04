/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** Background.cpp
*/

#include "../managing/ErrorManaging.hpp"
#include "Background.hpp"

Background::Background(const std::string &path)
{
        _background = al_load_bitmap(path.c_str());
        if (!_background)
                throw ErrorManaging("Failed to load background");
        _posX = 0;
        _posY = 0;
        _width = al_get_bitmap_width(_background);
        _height = al_get_bitmap_height(_background);
        _toClean = false;
}

Background::~Background()
{
        al_destroy_bitmap(_background);
}

void Background::drawMe() const
{
        al_draw_scaled_bitmap(_background, 0, 0, _width, _height, _posX, _posY, 1920, 1080, 0);
}

bool Background::eventGestion(unsigned char *key)
{
        return false;
}

bool Background::clean() const
{
        return _toClean;
}

void Background::setToClean(bool toClean)
{
        _toClean = toClean;
}