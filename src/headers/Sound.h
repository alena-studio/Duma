/*
*
*   Copyright (C) Alena Studio - 2017
*   Author : Akadream
*   Project : Duma
*
*
*/

#ifndef SOUND_H_INCLUDED
#define SOUND_H_INCLUDED

#include <string>
#include <SDL.h>
#include <SDL_mixer.h>

class Sound {
    private:
        Mix_Music* music;
    public:
        Sound(std::string fileName);
        ~Sound();
        Mix_Music* getCurrent();
        void play();
        void play(int times);
        void pause();
        void free();
};

#endif // SOUND_H_INCLUDED
