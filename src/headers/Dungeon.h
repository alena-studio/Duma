/*
*
*   Copyright (C) Alena Studio - 2017
*   Author : Akadream
*   Project : Duma
*
*
*/

#ifndef DONJON_H_INCLUDED
#define DONJON_H_INCLUDED

#include <iostream>
#include <string>
#include <SDL.h>
#include "Windows.h"

class Donjon {
    private:
        SDL_Surface* room;
        SDL_Rect positionRoom;
        int area[10][10];
    public:
        Donjon();
        ~Donjon();
        void display();
        void setRoom(int i, int j, int value);
        void free();
        void console();
};

#endif // DONJON_H_INCLUDED
