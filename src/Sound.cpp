/*
*
*   Copyright (C) Alena Studio - 2017
*   Author : Akadream
*   Project : Duma
*
*
*/

#include "Sound.h"

Sound::Sound(std::string fileName) {
    music = Mix_LoadMUS(fileName.c_str());
}

Sound::~Sound() {

}

Mix_Music* Sound::getCurrent() {
    return music;
}

void Sound::play() {
    // Infinite loop
    Mix_PlayMusic(music, -1);
}

void Sound::play(int times) {
    Mix_PlayMusic(music, times);
}

void Sound::pause() {
    Mix_PauseMusic();
}

void Sound::free() {
    Mix_FreeMusic(music);
}
