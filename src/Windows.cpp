/*
*
*   Copyright (C) Alena Studio - 2017
*   Author : Akadream
*   Project : Duma
*
*
*/

#include "Windows.h"

Windows Windows::instance = Windows();

Windows::Windows() : created(false) {
    window = NULL;
}

Windows::~Windows() {
    // Supprimer toutes les allocations dynamique
}

Windows* Windows::getInstance() {
    return &instance;
}

int Windows::createWindow(std::string title, std::string icon, int width, int height, int colors) {
    if(!created) {
        if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        return -1;
        printf("Impossible de charger la SDL !");
    }
    atexit(SDL_Quit);

    SDL_WM_SetCaption(title.c_str() , NULL);
    SDL_WM_SetIcon(IMG_Load(icon.c_str()), NULL);

    window = SDL_SetVideoMode(width, height, colors, SDL_HWSURFACE | SDL_DOUBLEBUF);

    created = true;
    }
    return 0;
}

void Windows::setWindow(std::string title, int width, int height) {
    SDL_WM_SetCaption(title.c_str(), NULL);
    window = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
}

void Windows::fillRect() {
    SDL_FillRect(window, NULL, SDL_MapRGB(window->format, 0, 0, 0));
}

bool Windows::getCreated() const {
    return created;
}

SDL_Surface* Windows::getWindow() {
    return window;
}

void Windows::close() {
    created = false;
}

void Windows::refreshWindow() {
    SDL_Flip(window);
}

void Windows::exit() {
    SDL_Quit();
}
