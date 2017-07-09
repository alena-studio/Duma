/*
*
*   Copyright (C) Alena Studio - 2017
*   Author : Akadream
*   Project : Duma
*
*
*/

#include "Sprite.h"

Sprite::Sprite(std::string fileName) {
    sprite = NULL;
    sprite = IMG_Load(fileName.c_str());
}

Sprite::Sprite(SDL_Surface* file) {
    sprite = file;
}

Sprite::~Sprite() {

}

SDL_Surface* Sprite::getSprite() {
    return sprite;
}

void Sprite::display(int x, int y, SDL_Surface *parent) {
    positionSprite.x = x;
    positionSprite.y = y;

    SDL_BlitSurface(sprite, NULL, parent, &positionSprite);
}

void Sprite::display(int x, int y, SDL_Surface *child, SDL_Surface *parent) {
    positionSprite.x = x;
    positionSprite.y = y;

    SDL_BlitSurface(child, NULL, parent, &positionSprite);
}

void Sprite::free() {
    SDL_FreeSurface(sprite);
}

int Sprite::getWidth() {
    return sprite->w;
}

int Sprite::getHeight() {
    return sprite->h;
}

int Sprite::getPositionX() {
    return positionSprite.x;
}

int Sprite::getPositionY() {
    return positionSprite.y;
}

void Sprite::setPositionX(int x) {
    positionSprite.x = x;
}

void Sprite::setPositionY(int y) {
    positionSprite.y = y;
}

void Sprite::setPosition(int x, int y) {
    positionSprite.x = x;
    positionSprite.y = y;
}
