//
// Created by user on 25.05.2023.
//

#include "Positions.h"

Positions::Positions(int x, int y) {
    this->x = x;
    this->y = y;
}

int Positions::getX() const {
    return x;
}

int Positions::getY() const {
    return y;
}
