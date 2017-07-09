/*
*
*   Copyright (C) Alena Studio - 2017
*   Author : Akadream
*   Project : Duma
*
*
*/

#include "Editor.h"

Editor Editor::instance = Editor();

Editor::Editor() {

}

Editor::~Editor() {
}

Editor* Editor::getInstance() {
    return &instance;
}

int Editor::init() {

}

void Editor::actionListener(SDL_Event* event) {
}

void Editor::mappingHighLayer() {
}

void Editor::mappingLowLayer() {
}
