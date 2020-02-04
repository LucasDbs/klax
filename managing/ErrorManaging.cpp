/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** ErrorManaging.cpp
*/

#include "ErrorManaging.hpp"

ErrorManaging::ErrorManaging(const std::string &msg)
{
        _msg = msg;
}

ErrorManaging::~ErrorManaging()
{
}

const char *ErrorManaging::what() const noexcept
{
        return _msg.c_str();
}