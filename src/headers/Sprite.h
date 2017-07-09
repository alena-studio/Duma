/*
*
*   Copyright (C) Alena Studio - 2017
*   Author : Akadream
*   Project : Duma
*
*
*/

#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include <string>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class Sprite {
    private:
        SDL_Surface *sprite;
        SDL_Rect positionSprite;
    public:
        Sprite(std::string fileName);
        Sprite(SDL_Surface* file);
        ~Sprite();
        SDL_Surface* getSprite();
        void display(int x, int y, SDL_Surface *parent);
        void display(int x, int y, SDL_Surface *child, SDL_Surface *parent);
        void free();
        int getWidth();
        int getHeight();
        int getPositionX();
        int getPositionY();
        void setPositionX(int x);
        void setPositionY(int y);
        void setPosition(int x, int y);
};

#endif // SPRITE_H_INCLUDED
