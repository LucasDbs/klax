/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** Text.hpp
*/

#if !defined(TEXT_HPP_)
#define TEXT_HPP_

#include <allegro5/allegro_ttf.h>
#include "../managing/ErrorManaging.hpp"
#include "IBitmap.hpp"

class Text : public IBitmap
{
        public:
                Text(float width, float posX, float posY, const std::string &msg);
                virtual ~Text();

                virtual void drawMe() const;
                virtual bool eventGestion(unsigned char *key);
                virtual bool clean() const;
                virtual void setToClean(bool toClean);
                void setMsg(const std::string &msg);

        private:
                ALLEGRO_FONT *_font;
                std::string _msg;
};

#endif // TEXT_HPP_
