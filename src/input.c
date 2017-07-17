#include "input.h"

// Get input data
void getInputs(void) {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type) {
        case SDL_QUIT:
            exit(1);
            break;
        case SDL_KEYDOWN:
            // Key down
            switch(event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    // End
                    exit(1);
                case SDLK_l:
                    // Load the dungeon
                    break;
                case SDLK_s:
                    // Save dungeon
                    input.setSave = 1;
                    break;
                case SDLK_LCTRL:
                    input.switchMode = 1;;
                case SDLK_UP:
                    input.up = 1;
                    break;
                case SDLK_DOWN:
                    input.down = 1;
                    break;
                case SDLK_LEFT:
                    input.left = 1;
                    break;
                case SDLK_RIGHT:
                    input.right = 1;
                    break;
            }
            break;
        case SDL_KEYUP:
            switch(event.key.keysym.sym) {
                case SDLK_LCTRL:
                    input.switchMode = 0;
                    break;
                case SDLK_LEFT:
                    input.left = 0;
                    break;
                case SDLK_RIGHT:
                    input.right = 0;
                    break;
                case SDLK_UP:
                    input.up = 0;
                    break;
                case SDLK_DOWN:
                    input.down = 0;
                    break;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            // Lorsque l'on appuis sur un bouton de la souris
            switch(event.button.button) {
                case SDL_BUTTON_LEFT:
                    input.setTile = 1;
                    break;
                case SDL_BUTTON_MIDDLE:
                    input.getCopy = 1;
                    break;
                case SDL_BUTTON_RIGHT:
                    input.setEmpty = 1;
                    break;
                case SDL_BUTTON_WHEELUP:
                    input.nextTile = 1;
                    break;
                case SDL_BUTTON_WHEELDOWN:
                    input.previousTile = 1;
                    break;
            }
            break;
        case SDL_MOUSEBUTTONUP:
            switch(event.button.button) {
                case SDL_BUTTON_LEFT:
                    input.setTile = 0;
                    break;
                case SDL_BUTTON_RIGHT:
                    input.setEmpty = 0;
                    break;
            }
            // When button up
            break;
        case SDL_MOUSEMOTION:
            cursor.x = event.motion.x;
            cursor.y = event.motion.y;
            cursor.tileX = event.motion.x / TILE_SIZE;
            cursor.tileY = event.motion.y / TILE_SIZE;
            // When moving mouse
            break;
    }
}

// Update input values
void update(void) {
    if(input.up == 1) {
        room.roomY--;

        if(room.roomY < 0) {
            room.roomY = 0;
        }
    }
    else if(input.down == 1) {
        room.roomY++;

        if(room.roomY >= WINDOWS_Y + TILE_MAX) {
            room.roomY = WINDOWS_Y - TILE_MAX;
        }
    }

    if(input.left == 1) {
        room.roomX--;

        if(room.roomX < 0) {
            room.roomX = 0;
        }
    }
    else if(input.right == 1) {
        room.roomX++;

        if(room.roomX > WINDOWS_X + TILE_MAX) {
            room.roomX = WINDOWS_X - TILE_MAX;
        }
    }


    if(input.setTile == 1) {
        // Place a tile
        if(game.currentMod == EDITING) {
            switch(room.currentLayer) {
                case LOWLAYER:
                    // Place a tile on the low layer
                    room.lowLayer[(cursor.x / TILE_MAX) + room.roomX][(cursor.y / TILE_MAX) + room.roomY] = room.tileIndex;
                    break;
                case HIGHLAYER:
                    // Place a tile on the high layer
                    room.highLayer[(cursor.x / TILE_MAX) + room.roomX][(cursor.y / TILE_MAX) + room.roomY] = room.tileIndex;
                    break;
                case EVENTLAYER:
                    // Place an event
                    if(room.eventIndex == START_POINT && room.start == 0) {
                        room.start = 1;
                        room.eventLayer[(cursor.x / TILE_MAX) + room.roomX][(cursor.y / TILE_MAX) + room.roomY] = room.eventIndex;
                    }
                    else if(room.eventIndex != START_POINT) {
                        room.eventLayer[(cursor.x / TILE_MAX) + room.roomX][(cursor.y / TILE_MAX) + room.roomY] = room.eventIndex;
                    }
                    input.setTile = 0;
                    break;
            }
            break;
        }
    }
    else if(input.setEmpty == 1) {
        // Place an empty tile
        if(game.currentMod == EDITING) {
            switch(room.currentLayer) {
                case LOWLAYER:
                    room.lowLayer[(cursor.x / TILE_MAX) + room.roomX][(cursor.y / TILE_MAX) + room.roomY] = EMPTY;
                    break;
                case HIGHLAYER:
                    room.highLayer[(cursor.x / TILE_MAX) + room.roomX][(cursor.y / TILE_MAX) + room.roomY] = EMPTY;
                    break;
                case EVENTLAYER:
                    if(room.eventLayer[(cursor.x / TILE_MAX) + room.roomX][(cursor.y / TILE_MAX) + room.roomY] == START_POINT) {
                        room.start = 0;
                    }
                    room.eventLayer[(cursor.x / TILE_MAX) + room.roomX][(cursor.y / TILE_MAX) + room.roomY] = EMPTY;
                    input.setEmpty = 0;
                    break;
            }
        }
    }

    if(input.getCopy == 1) {
        if(game.currentMod == EDITING) {
            switch(room.currentLayer) {
                case LOWLAYER:
                    room.tileIndex = room.lowLayer[(cursor.x / TILE_MAX) + room.roomX][(cursor.y / TILE_MAX) + room.roomY];
                    break;
                case HIGHLAYER:
                    room.tileIndex = room.highLayer[(cursor.x / TILE_MAX) + room.roomX][(cursor.y / TILE_MAX) + room.roomY];
                    break;
                case EVENTLAYER:
                    room.eventIndex = room.eventLayer[(cursor.x / TILE_MAX) + room.roomX][(cursor.y / TILE_MAX) + room.roomY];
                    break;
            }
        }
        input.getCopy = 0;
    }

    if(input.nextTile == 1) {
        // Select the next tile
        if(room.currentLayer == LOWLAYER || room.currentLayer == HIGHLAYER) {
            room.tileIndex++;

            if(room.tileIndex > (tileset.w / 32) * (tileset.h / 32)) {
                room.tileIndex = 0;
            }
        }
        else if(room.currentLayer == EVENTLAYER) {
            room.eventIndex++;

            if(room.eventIndex > 1) {
                room.eventIndex = 0;
            }
        }
        input.nextTile = 0;
    }
    else if(input.previousTile == 1) {
        // Select the previous tile
        if(room.currentLayer == LOWLAYER || room.currentLayer == HIGHLAYER) {
            room.tileIndex--;

            if(room.tileIndex < 0) {
                room.tileIndex = (tileset.w / 32) * (tileset.h / 32);
            }
        }
        else if(room.currentLayer == EVENTLAYER) {
            room.eventIndex--;

            if(room.eventIndex < 0) {
                room.eventIndex = 1;
            }
        }
        input.previousTile = 0;
    }

    /*if(input.setLowLayer == 1) {
        if(game.edit == ROOM_MAPPING) {
            room.currentLayer = LOWLAYER;
        }

        input.setLowLayer = 0;
    }
    else if(input.setHighLayer == 1) {
        if(game.edit == ROOM_MAPPING) {
            room.currentLayer = HIGHLAYER;
        }

        input.setHighLayer = 0;
    }
    else if(input.setEventLayer == 1) {
        if(game.edit == ROOM_MAPPING) {
            room.currentLayer = EVENTLAYER;
        }

        input.setEventLayer = 0;
    }*/

    // Switch the current mode (CTRL Button)
    if(input.switchMode == 1) {
        switch(game.edit) {
            case EDITING:
                // Set editing mode
                game.edit = PLAY;
                setWindow("Alena Studio - Duma (Test en cours...)");
                break;
            case PLAY:
                // Try the dungeon
                game.edit = EDITING;
                setWindow("Alena Studio - Duma Engine");
                break;
        }

        input.switchMode = 0;
    }

    // L Button
    if(input.load == 1) {
        if(game.currentMod == EDITING) {
            // Load the dungeon
        }
        input.load = 0;
    }

    // S Button
    if(input.save == 1) {
        if(game.currentMod == EDITING) {
            // Save the dungeon
        }

        input.save = 0;
    }

    // Scrolling speed
    if(input.left == 1 || input.up == 1 || input.down == 1 || input.right == 1) {
        SDL_Delay(30);
    }
}
