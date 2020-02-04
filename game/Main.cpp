/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** Main.cpp
*/

#include <iostream>
#include "GameManager.hpp"

int main()
{
        try {
                GameManager *game_mngr = new GameManager();

                game_mngr->startGame();
        } catch (const std::exception &e) {
                std::cout << e.what() << std::endl;
                return 84;
        }
        return 0;
}