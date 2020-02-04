/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** GraphicManager.hpp
*/

#if !defined(GRAPHICMANAGER_HPP_)
#define GRAPHICMANAGER_HPP_

#include <vector>
#include <allegro5/allegro_image.h>
#include "Background.hpp"
#include "Platform.hpp"
#include "Block.hpp"
#include "Text.hpp"

#define KEY_SEEN 1
#define KEY_RELEASED 2

class GraphicManager
{
        public:
                GraphicManager();
                ~GraphicManager();

                bool eventManagement();
                int drawAll();
                void startTimer() const;
                int createBackground(const std::string &path);
                Text *createText(float width, float posX, float posY, const std::string &msg);
                Platform *createPlatform(const std::string &path);
                Block *createBlock(float posX, float posY, float width, float height);

        private:
                ALLEGRO_TIMER *_timer;
                ALLEGRO_EVENT_QUEUE *_queue;
                ALLEGRO_DISPLAY *_disp;
                ALLEGRO_EVENT _event;
                unsigned char _key[ALLEGRO_KEY_MAX];
                std::vector<IBitmap *> _bitmap;
};

#endif // GRAPHIC_HPP_
