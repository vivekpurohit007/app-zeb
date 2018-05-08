/**
 * @file player.cpp
 * @author augustronics@gmail.com
 * @date 06 May 2018
 * 
 * @brief Implementation of player
 * 
 * Copyright (c) 2018, augustronics@gmail.com
 */

#include <iostream>
#include <cstdlib>

#include "move.h"
#include "player.h"
#include "tictactoe.h"

using namespace std;
using namespace tictactoe;

Player::Player() {
    /* default is Human player */
    this->type  = PLAYER_HUMAN;
    this->symbol = PLAYER_CROSS;

    this->arena = NULL;
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

PlayerType Player::getType() {
    return this->type;
}

void Player::setType(PlayerType type) {
    this->type = type;
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

PlayerSymbol Player::getSymbol() {
    return this->symbol;
}

void Player::setSymbol(PlayerSymbol symbol) {
    this->symbol = symbol;
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

Arena *Player::getArena() {
    return this->arena;
}

void Player::setArena(Arena *arena) {
    if (NULL == arena) {
        cout << __func__ << ": Error: invalid parameter" << endl;
        exit(0);
    }

    this->arena = arena;
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void Player::makemove(int row, int col) {
    Move *move = new Move(row, col);
    
    /* present move to the arena */
    this->arena->MakeMove(move, this);

    delete move;
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void Player::MakeMove(int row, int col) {
    /* check for player arena */
    if (NULL == this->arena) {
        cout << __func__ << ": Error: no arena to move." << endl;
        return;
    }

    this->makemove(row, col);
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void Player::MakeMove(Arena *arena, int row, int col) {
    /* check for player arena */
    if (NULL == arena) {
        cout << __func__ << ": Error: invalid input." << endl;
        return;
    }

    this->setArena(arena);

    this->makemove(row, col);
}
 
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

Player::~Player() {
    this->arena = NULL;
}
/* EOF */
