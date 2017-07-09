/*
*
*   Copyright (C) Alena Studio - 2017
*   Author : Akadream
*   Project : Duma
*
*
*/


#ifndef EDITOR_H_INCLUDED
#define EDITOR_H_INCLUDED

#include <SDL.h>

class Editor {
    private:
        Editor();
        ~Editor();
        static Editor instance;
    public:
        int init();
        static Editor* getInstance();
        void actionListener(SDL_Event* event);
        void mappingHighLayer();
        void mappingLowLayer();
};

#endif // EDITOR_H_INCLUDED
