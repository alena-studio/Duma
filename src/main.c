/*
 *  Copyright (C) : Alena Studio
 *  Last update : 17/07/2017 - 21h25
 *
 *  This file call global functions needed for the game
 */

#include "main.h"

int main(int argc, char* argv[]) {
    // To let the console
    freopen("CON", "w", stdout);
    freopen("CON", "r", stdin);
    freopen("CON", "w", stderr);

    unsigned int frameLimit = SDL_GetTicks() + 16;
    int mainLoop = 1;

    init("Alena Studio - Duma Engine");

    loadGame();

    atexit(cleanup);

    while(mainLoop == 1) {
        // Get input used
        getInputs();

        // Update inputs
        update();

        // Draw the screen
        draw();

        display(frameLimit);
        frameLimit = SDL_GetTicks() + 16;
    }
}
