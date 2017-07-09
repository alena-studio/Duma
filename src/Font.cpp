/*
*
*   Copyright (C) Alena Studio - 2017
*   Author : Akadream
*   Project : Duma
*
*
*/


#include "Font.h"

Font Font::instance = Font();

Font::Font() {

}

Font::~Font() {

}

Font* Font::getInstance() {
    return &instance;
}

int Font::loadFont() {
    if(TTF_Init() == -1) {
        return -1;
    }

    return 0;
}

void Font::closeFont() {
    TTF_Quit();
}
