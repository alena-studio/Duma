/*
*
*   Copyright (C) Alena Studio - 2017
*   Author : Akadream
*   Project : Duma
*
*
*/

#ifndef WINDOWS_H_INCLUDED
#define WINDOWS_H_INCLUDED

#include <string>

#include <SDL.h>
#include <SDL_image.h>

class Windows {
    private:
        Windows();
        ~Windows();
        bool created;
        static Windows instance;
        SDL_Surface* window;
        SDL_Event event;

    public:
        static Windows* getInstance();
        bool getCreated() const;
        SDL_Surface* getWindow();
        void close();
        int createWindow(std::string title, std::string icon, int width, int height, int colors);
        void setWindow(std::string title, int width, int height);
        void refreshWindow();
        void fillRect();
        void exit();
};

#endif // WINDOWS_H_INCLUDED
