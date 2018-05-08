/**
 * @file move.cpp
 * @author augustronics@gmail.com
 * @date 06 May 2018
 * 
 * @brief Defines the move played by a player
 * 
 * Copyright (c) 2018, augustronics@gmail.com
 */

#include <iostream>

#include "move.h"

Move::Move() {
    this->row = this->col = 0;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

Move::Move(int r, int c) {
    this->row = r;
    this->col = c;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

int Move::getRow() const {
    return this->row;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void Move::setRow(int row) {
    this->row = row;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

int Move::getCol() const {
    return this->col;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void Move::setCol(int col) {
    this->col = col;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

Move::~Move() {
    /* empty */
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* EOF */