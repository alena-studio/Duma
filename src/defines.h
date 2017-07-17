#ifndef DEFINES_H_INCLUDED // CONST VARIABLES
#define DEFINES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

#define WINDOW_WIDTH_DEFAULT            800
#define WINDOW_HEIGHT_DEFAULT           640
#define WINDW_COLOR_DEFAULT             32

#define DUNGEON_MAX_X                   1000
#define DUNGEON_MAX_Y                   1000

#define ALPHA_R                         0
#define ALPHA_G                         0
#define ALPHA_B                         0

#define TILE_SIZE                       32

#define EMPTY                           0
#define FILL                            1

#define LOWLAYER                        0
#define HIGHLAYER                       1
#define EVENTLAYER                      2

#define EVENT_INDEX                     20

#define EDITING                         3
#define PLAY                            4
#define EVENTS                          5

#define START_POINT                     1

#define BLOCKS                          1
#define BLOCK_MOVABLE                   2
#define BLOCK_ONE_MOVE                  3

#define KEYS                            4
#define KEY_BASIC                       5
#define KEY_BOSS                        6

#define CHESTS                          7
#define CHEST_BOSS                      8
#define CHEST_BASIC                     9

#define SWITCHS                         10
#define SWITCH_TOLD                     11
#define SWITCH_ONE                      12

#define DOORS                           13
#define DOOR_UP                         14
#define DOOR_LEFT                       15
#define DOOR_RIGHT                      16
#define DOOR_DOWN                       17

#define MONSTERS                        18
#define MONSTER_SLIME                   19
#define MONSTER_GOBELIN                 20

#define OBJECTS                         21
#define OBJECT_SWORD                    22
#define OBJECT_SHIELD                   23
#define OBJECT_BOMB                     24
#define OBJECT_BOOMERANG                25
#define OBJECT_ARROW                    26
#define OBJECT_BOW                      27

#endif // DEFINES_H_INCLUDED
