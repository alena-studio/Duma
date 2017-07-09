/*
*
*   Copyright (C) Alena Studio - 2017
*   Author : Akadream
*   Project : Duma
*
*
*/

#include "Donjon.h"

Donjon::Donjon() {
    room = NULL;
    room = SDL_CreateRGBSurface(SDL_HWSURFACE, 32, 32, 32, 0, 0, 0, 0);
    positionRoom.x = 0;
    positionRoom.y = 0;

    for(int i = 0 ; i < 10 ; i++) {
        for(int j = 0 ; j < 10 ; j++) {
            area[i][j] = 0;
        }
    }
}

Donjon::~Donjon() {
}

void Donjon::display() {
    for(int i = 0 ; i < 10 ; i++) {
        for(int j = 0 ; j < 0 ; j++) {
            switch(area[i][j]) {
                case 0:
                    SDL_FillRect(room, NULL, SDL_MapRGB(room->format, 0, 0, 0));
                    break;
                case 1:
                    SDL_FillRect(room, NULL, SDL_MapRGB(room->format, 216, 46, 46));
                    break;
            }
            positionRoom.x = i * 32;
            positionRoom.y = j * 32;
            SDL_BlitSurface(room, NULL, Windows::getInstance()->getWindow(), &positionRoom);
        }
    }
}

void Donjon::setRoom(int i, int j, int value) {
    area[i][j] = value;
}

void Donjon::console() {
    for(int i = 0 ; i < 10 ; i++) {
        for(int j = 0 ; j < 10 ; j++) {
            std::cout << area[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Donjon::free() {
    SDL_FreeSurface(room);
}
