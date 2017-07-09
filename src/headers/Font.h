/*
*
*   Copyright (C) Alena Studio - 2017
*   Author : Akadream
*   Project : Duma
*
*
*/

#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

class Font {
    private:
        Font();
        ~Font();

        static Font instance;
    public:
        static Font* getInstance();
        int loadFont();
        void closeFont();
};

#endif // FONT_H_INCLUDED
