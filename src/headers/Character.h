/*
*
*   Copyright (C) Alena Studio - 2017
*   Author : Akadream
*   Project : Duma
*
*
*/


#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <string>
#include <SDL.h>

#include "Sprite.h"

class Character {
    private:
        std::string name;
        int health;
        int maxHealth;
        int inventory[3];

        Sprite charset;
    public:
        Character();
        ~Character();
        std::string getName();
        int getHealth();
        int getMaxHealth();
};

#endif // CHARACTER_H_INCLUDED
