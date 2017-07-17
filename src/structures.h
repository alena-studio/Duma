#include "defines.h"

typedef struct Game {
    SDL_Window *window;
    SDL_Renderer *renderer;

    int currentMod;
}Game;

typedef struct Dungeon {
    char tilesetFileName[255];

    int lowLayer[DUNGEON_MAX_X][DUNGEON_MAX_Y];
    int highLayer[DUNGEON_MAX_X][DUNGEON_MAX_Y];
    int eventLayer[DUNGEON_MAX_X][DUNGEON_MAX_Y];
}Dungeon;

typedef struct Cursor {
    int x, y, tileX, tileY;
}Cursor;

typedef struct Input {
    int setTile, setEmpty, getCopy, left, right, up, down, switchMode, nextTile, previousTile, save, load;
}Input;
