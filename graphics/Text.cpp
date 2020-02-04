/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** Text.cpp
*/


#include "Text.hpp"

Text::Text(float width, float posX, float posY, const std::string &msg)
{
        _font = al_load_ttf_font("assets/arial.ttf", width, 0);
        if (!_font)
                throw ErrorManaging("Failed to load text font");
        _posX = posX;
        _posY = posY;
        _width = 0;
        _height = 0;
        _msg = msg;
        _toClean = false;
}

Text::~Text()
{
        al_destroy_font(_font);
}

void Text::drawMe() const
{
        al_draw_text(_font, al_map_rgb(255, 255, 255), _posX, _posY, 0, _msg.c_str());
}

bool Text::eventGestion(unsigned char *key)
{
        return false;
}

bool Text::clean() const
{
        return _toClean;
}

void Text::setToClean(bool toClean)
{
        _toClean = toClean;
}

void Text::setMsg(const std::string &msg)
{
        _msg = msg;
}