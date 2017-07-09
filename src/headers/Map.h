/*
*
*   Copyright (C) Alena Studio - 2017
*   Author : Akadream
*   Project : Duma
*
*
*/

#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <string>

#include "Tileset.h"

class Map {
    private:
        int id;
        int x;
        int y;
        std::string name;
        int highLayer[][100];
        int lowLayer[][100];
        Tileset* tileset;
    public:
        Map(std::string nameMap, std::string fileName);
        ~Map();
        int getId();
        int getX();
        int getY();
        std::string getName();
        int load(std::string fileName);
        int save();
        void reset();
};

#endif // MAP_H_INCLUDED
