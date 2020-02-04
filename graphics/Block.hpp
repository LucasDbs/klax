/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** Block.hpp
*/

#if !defined(BLOCK_HPP_)
#define BLOCK_HPP_

#include <vector>
#include <allegro5/allegro5.h>
#include "IBitmap.hpp"

enum Color {
        NO_COLOR,
        BLUE,
        GREEN,
        YELLOW,
        RED
};

class Block : public IBitmap
{
        public:
                Block(float posX, float posY, float width, float height);
                virtual ~Block();

                virtual void drawMe() const;
                virtual bool eventGestion(unsigned char *key);
                virtual bool clean() const;
                virtual void setToClean(bool toClean);

                int rotate();
                bool rollDown();
                bool isArrived() const;
                void setX(float x);
                void setY(float y);
                void setFinalPos(int finalIndex);
                Color getColor() const;
                float getHeight() const;
                bool fallBlock();

        private:
                bool _stop;
                bool _toRotate;
                int _colorIndex;
                float _finalPos;
                std::vector<std::pair<ALLEGRO_COLOR, Color>> _colors;
};

#endif // BLOCK_HPP_
