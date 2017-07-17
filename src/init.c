#include "init.h"

// Initialization
void init(char *title) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        exit(1);
    }

    game.window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH_DEFAULT, WINDOW_HEIGHT_DEFAULT, SDL_WINDOW_SHOWN);
    game.renderer = SDL_CreateRenderer(game.window, -1, SDL_RENDERER_PRESENTVSYNC);

    if(game.window == NULL || game.renderer == NULL) {
        exit(1);
    }
}

// Update de title of the window
void setTitle(char *title) {
    SDL_SetWindowTitle(game.window, title);
}

// Load the game
void loadGame(void) {
}

// Clean resources at exit
void cleanup(void) {
    SDL_DestroyWindow(game.window);
    game.window = NULL;

    SDL_DestroyRenderer(game.renderer);
    game.renderer = NULL;

    SDL_Quit();
}
