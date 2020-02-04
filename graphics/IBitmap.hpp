/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** IBitmap.hpp
*/

#if !defined(IBITMAP_HPP_)
#define IBITMAP_HPP_

class IBitmap
{
        public:
                virtual ~IBitmap() {};

                virtual void drawMe() const = 0;
                virtual bool eventGestion(unsigned char *key) = 0;
                virtual bool clean() const = 0;
                virtual void setToClean(bool toClean) = 0;

        protected:
                bool _toClean;
                float _posX;
                float _posY;
                float _width;
                float _height;
};

#endif // IBITMAP_HPP_
