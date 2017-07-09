/*
*
*   Copyright (C) Alena Studio - 2017
*   Author : Akadream
*   Project : Duma
*
*
*/

#include "Mixer.h"

Mixer Mixer::instance = Mixer();

Mixer::Mixer() {}

Mixer::~Mixer() {}

Mixer* Mixer::getInstance() {
    return &instance;
}

int Mixer::loadAudio() {
    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY * 2, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0) {
        printf("Error !");
        return -1;
    }

    return 0;
}

void Mixer::exit() {
    Mix_CloseAudio();
}
