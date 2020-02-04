/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** GraphicManager.cpp
*/

#include "../managing/ErrorManaging.hpp"
#include "GraphicManager.hpp"

GraphicManager::GraphicManager()
{
        if (!al_init())
                throw ErrorManaging("Couldn't initialize Allegro\n");
        else if (!al_install_keyboard())
                throw ErrorManaging("Couldn't initialize keyboard\n");
        else if (!al_init_image_addon())
                throw ErrorManaging("Couldn't initialize image addon\n");
        else if (!al_init_font_addon() || !al_init_ttf_addon())
                throw ErrorManaging("Couldn't initialize ttf addon\n");
        _timer = al_create_timer(1.0 / 30.0);
        _queue = al_create_event_queue();
        _disp = al_create_display(1920, 1080);
        if (!_timer || !_queue || !_disp)
                throw ErrorManaging("Failed to load lib tools");
        al_register_event_source(_queue, al_get_keyboard_event_source());
        al_register_event_source(_queue, al_get_display_event_source(_disp));
        al_register_event_source(_queue, al_get_timer_event_source(_timer));
        memset(_key, 0, sizeof(_key));
}

GraphicManager::~GraphicManager()
{
        al_destroy_display(_disp);
        al_destroy_timer(_timer);
        al_destroy_event_queue(_queue);
}

bool GraphicManager::eventManagement()
{
        al_wait_for_event(_queue, &_event);

        switch (_event.type)
        {
                case ALLEGRO_EVENT_TIMER:
                        if (_key[ALLEGRO_KEY_ESCAPE])
                                return false;
                        for (int i = 0; i < ALLEGRO_KEY_MAX; i++)
                                _key[i] &= KEY_SEEN;
                        break;
                case ALLEGRO_EVENT_KEY_DOWN:
                        _key[_event.keyboard.keycode] = KEY_SEEN | KEY_RELEASED;
                        break;
                case ALLEGRO_EVENT_KEY_UP:
                        for (auto &i: _bitmap) {
                                if (i->eventGestion(_key))
                                        break;
                        }
                        _key[_event.keyboard.keycode] &= KEY_RELEASED;
                        break;
                case ALLEGRO_EVENT_DISPLAY_CLOSE:
                        return false;
        }
        return true;
}

int GraphicManager::drawAll()
{
        int index = 0;

        if (al_is_event_queue_empty(_queue))
        {
                al_clear_to_color(al_map_rgb(0, 0, 0));
                for (auto &i: _bitmap) {
                        if (i->clean()) {
                                delete i;
                                _bitmap.erase(_bitmap.begin() + index);
                        }
                        else
                                i->drawMe();
                        index++;
                }
                al_flip_display();
        }
        return 0;
}

int GraphicManager::createBackground(const std::string &path)
{
        _bitmap.push_back(new Background(path));
        return 0;
}

Text *GraphicManager::createText(float width, float posX, float posY, const std::string &msg)
{
        _bitmap.push_back(new Text(width, posX, posY, msg));
        return dynamic_cast<Text *>(_bitmap.back());
}

Platform *GraphicManager::createPlatform(const std::string &path)
{
        _bitmap.push_back(new Platform(path));
        return dynamic_cast<Platform *>(_bitmap.back());
}

Block *GraphicManager::createBlock(float posX, float posY, float width, float height)
{
        _bitmap.push_back(new Block(posX, posY, width, height));
        return dynamic_cast<Block *>(_bitmap.back());
}

void GraphicManager::startTimer() const
{
        al_start_timer(_timer);
}
