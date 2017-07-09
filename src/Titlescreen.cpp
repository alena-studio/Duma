/*
*
*   Copyright (C) Alena Studio - 2017
*   Author : Akadream
*   Project : Duma
*
*
*/

#include <string>
#include "Titlescreen.h"

Titlescreen Titlescreen::instance = Titlescreen();

Titlescreen::Titlescreen() {
    backgroundFileName = "database/pictures/Titlescreen.png";
    cursor = new Sprite("database/pictures/selection.png");
    fontFile = TTF_OpenFont("arial.ttf", 14);

    SDL_Color color = {255,0,0};
    textPlay = TTF_RenderText_Blended(fontFile, "Jouer", color);
    textLoad = TTF_RenderText_Blended(fontFile, "Éditeur de map", color);
    textOptions = TTF_RenderText_Blended(fontFile, "Options", color);
    textQuit = TTF_RenderText_Blended(fontFile, "Quitter", color);
}

Titlescreen::~Titlescreen() {
    delete cursor;
}

void Titlescreen::display(SDL_Surface* parent) {
}

SDL_Surface* Titlescreen::getTextPlay() {
    return textPlay;
}

SDL_Surface* Titlescreen::getTextLoad() {
    return textLoad;
}

SDL_Surface* Titlescreen::getTextOptions() {
    return textOptions;
}

SDL_Surface* Titlescreen::getTextQuit() {
    return textQuit;
}

Titlescreen* Titlescreen::getInstance() {
    return &instance;
}

std::string Titlescreen::getBackgroundFileName() {
    return backgroundFileName;
}

void Titlescreen::free() {
    //SDL_FreeSurface(textPlay);
    //SDL_FreeSurface(textLoad);
    //SDL_FreeSurface(textOptions);
    //SDL_FreeSurface(textQuit);
}

int Titlescreen::getMenuLength() {
    return 4;
}
