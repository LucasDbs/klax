/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** Platform.hpp
*/

#if !defined(PLATFORM_HPP_)
#define PLATFORM_HPP_

#include <iostream>
#include <vector>
#include <list>
#include <allegro5/allegro5.h>
#include "IBitmap.hpp"
#include "Block.hpp"

class Platform : public IBitmap
{
        public:
                Platform(const std::string &path);
                virtual ~Platform();

                virtual void drawMe() const;
                virtual bool eventGestion(unsigned char *key);
                virtual bool clean() const;
                virtual void setToClean(bool toClean);
                bool addBlock(Block *block, int index);
                bool canDrop() const;
                Block *dropBlock();
                void setDrop(bool drop);
                int getPosIndex() const;

        private:
                bool _dropBlock;
                ALLEGRO_BITMAP *_platform;
                int _posIndex;
                std::vector<float> _pos;
                std::list<Block *> _blocks;

                void blockAdjust() const;
};

#endif // PLATFORM_HPP_