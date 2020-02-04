/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** Background.hpp
*/

#if !defined(BACKGROUND_HPP_)
#define BACKGROUND_HPP_

#include <allegro5/allegro5.h>
#include "IBitmap.hpp"

class Background : public IBitmap
{
        public:
                Background(const std::string &path);
                virtual ~Background();

                virtual void drawMe() const;
                virtual bool eventGestion(unsigned char *key);
                virtual bool clean() const;
                virtual void setToClean(bool toClean);

        private:
                ALLEGRO_BITMAP *_background;
};

#endif // BACKGROUND_HPP_
