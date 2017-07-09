/*
*
*   Copyright (C) Alena Studio - 2017
*   Author : Akadream
*   Project : Duma
*
*
*/

#include "Tileset.h"

Tileset::Tileset(std::string fileName) {
    picture = new Sprite(fileName);
}

Tileset::~Tileset() {
    delete picture;
}

Sprite* Tileset::getTileset() {
    return picture;
}

int Tileset::getWidth() {
    return picture->getWidth();
}

int Tileset::getHeight() {
    return picture->getHeight();
}
