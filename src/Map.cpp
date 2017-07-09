/*
*
*   Copyright (C) Alena Studio - 2017
*   Author : Akadream
*   Project : Duma
*
*
*/

#include <iostream>

#include "Map.h"

Map::Map(std::string nameMap, std::string fileName) {
    tileset = new Tileset(fileName);
    name = nameMap;
}

Map::~Map() {
    delete tileset;
}

int Map::getId() {
    return id;
}

int Map::getX() {
    return x;
}

int Map::getY() {
    return y;
}

std::string Map::getName() {
    return name;
}

int Map::load(std::string fileName) {
    return 0;
}

int Map::save() {
    return 0;
}

void Map::reset() {

}
