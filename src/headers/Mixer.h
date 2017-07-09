/*
*
*   Copyright (C) Alena Studio - 2017
*   Author : Akadream
*   Project : Duma
*
*
*/

#ifndef MIXER_H_INCLUDED
#define MIXER_H_INCLUDED

#include <SDL.h>
#include <SDL_mixer.h>

class Mixer {
    private:
        Mixer();
        ~Mixer();

        static Mixer instance;
    public:
        static Mixer* getInstance();
        int loadAudio();
        void exit();
};

#endif // MIXER_H_INCLUDED
