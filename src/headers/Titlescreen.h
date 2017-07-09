/*
*
*   Copyright (C) Alena Studio - 2017
*   Author : Akadream
*   Project : Duma
*
*
*/

#ifndef TITLESCREEN_H_INCLUDED
#define TITLESCREEN_H_INCLUDED

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Sprite.h"

class Titlescreen {
    private:
        Titlescreen();
        ~Titlescreen();
        Sprite* cursor;
        std::string backgroundFileName;
        TTF_Font* fontFile;
        SDL_Surface* textPlay;
        SDL_Surface* textLoad;
        SDL_Surface* textOptions;
        SDL_Surface* textQuit;
        SDL_Rect textPosition;
        static Titlescreen instance;
    public:
        static Titlescreen* getInstance();
        void display(SDL_Surface* parent);
        std::string getBackgroundFileName();
        SDL_Surface* getTextPlay();
        SDL_Surface* getTextLoad();
        SDL_Surface* getTextOptions();
        SDL_Surface* getTextQuit();
        int getMenuLength();
        void free();
};

#endif // TITLESCREEN_H_INCLUDED
