/**
 * @file tictactoegame.cpp
 * @author augustronics@gmail.com
 * @date 06 May 2018
 * 
 * @brief Implementation file for TicTacToe Game
 * 
 * Copyright (c) 2018, augustronics@gmail.com
 */

#include <iostream>
#include <cstdlib>

#include "game.h"
#include "move.h"
#include "player.h"
#include "arena.h"
#include "tictactoe.h"
#include "tictactoegame.h"
#include "tictactoeboard.h"

using namespace std;

TicTacToeGame::TicTacToeGame() {
    this->arena = new TicTacToeBoard();
    this->playerCount = MAX_PLAYERS;

    /* init the players */
    this->players = new Player[MAX_PLAYERS];

    (this->players+0)->setType(PLAYER_HUMAN);
    (this->players+0)->setSymbol(PLAYER_CROSS);
    (this->players+1)->setType(PLAYER_COMPUTER);
    (this->players+1)->setSymbol(PLAYER_CIRCLE);
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void TicTacToeGame::Display() const {
    (void)system("clear");

    cout << "++++++ T I C T A C T O E ++++++" << endl
         << endl
         << "++++++     Board State   ++++++" << endl;
    this->arena->Display();

    cout << "+++++++++++++++++++++++++++++++" << endl
         << "+ STATUS : " << endl;
    cout << "+++++++++++++++++++++++++++++++" << endl;
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void TicTacToeGame::Play() {
    int turn = 0; /* first player to make first move */
    enum State gamestate = PLAY;

    this->Display();

    /* loop for 9 possible positions */
    while (gamestate == PLAY) {
        cout << "+++++++++++++++++++++++++++++++" << endl;
        cout << "Turn: Player " << (turn+1) << endl;
        cout << "+++++++++++++++++++++++++++++++" << endl;
again:
        int moveX, moveY;
        Move move;
        cout << "Enter row: ";
        cin >> moveX;

        cout << "Enter col: ";
        cin >> moveY;

        move.setRow(moveX);
        move.setCol(moveY);

        if (this->arena->MakeMove(&move, (this->players+turn))) {
            /* if move failed, try again */
            /* TODO: fix this goto*/
            cout << "Try another move" << endl;
            goto again;
        }

        this->Display();

        /* evaluate the board for result */
        gamestate = (enum State) this->Evaluate();
        cout << "State = " << gamestate << endl;

        if (RESULT == gamestate) {
            cout << "GAME END: Player " << (turn+1) << " WON." << endl;
        } else
        if (DRAW == gamestate) {
            cout << "GAME ended in a DRAW." << endl;
        }

        turn = (turn+1)%2;
    }
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#define CHECK_BOARD_STATE(cell, isempty, value, seqlen, state) { \
    if (cell == EMPTY)                          \
        isempty = true;                         \
                                                \
    if (value == cell) {                        \
        seqlen++;                               \
    } else {                                    \
        value = cell;                           \
        seqlen = 1;                             \
    }                                           \
    if (!isempty && seqlen == DEGREE) {         \
        return (int)RESULT;                     \
    } else {                                    \
        if (isempty) {                          \
            state = PLAY;                       \
        }                                       \
    }                                           \
}

/**
 * Evaluates the board for DRAW/WIN/etc
 *
 * Sequences which need to be checked for WINning sequence
 *
 * +--+  +
 * |\ | /|
 * +-\-/ |
 * |     |
 * +---
 */
int TicTacToeGame::Evaluate() {
    enum State gamestate = DRAW;
    bool cellempty;
    int SL;
    int mark;
    TicTacToeBoard *board = dynamic_cast<TicTacToeBoard*>(this->arena);

    /* check rows */
    for (int r = 0; r < DEGREE; r++) {
        SL = 0;
        mark = EMPTY;
        cellempty = false;

        for (int c = 0; c < DEGREE; c++) {
            CHECK_BOARD_STATE(board->getValueAt(r,c), cellempty, mark, SL, gamestate);
        }
    }

    /* check columns */
    for (int c = 0; c < DEGREE; c ++) {
        SL = 0;
        mark = EMPTY;
        cellempty = false;

        for (int r = 0; r < DEGREE; r++) {
            CHECK_BOARD_STATE(board->getValueAt(r,c), cellempty, mark, SL, gamestate);
        }
    }

    /* upper-left to lower-right diagonal */
    SL = 0;
    mark = EMPTY;
    cellempty = false;

    for (int i = 0; i < DEGREE; i++) {
        CHECK_BOARD_STATE(board->getValueAt(i,DEGREE-i-1), cellempty, mark, SL, gamestate);
    }

    /* upper-right to lower-left diagonal */
    SL = 0;
    mark = EMPTY;
    cellempty = false;

    for (int i = 0; i < DEGREE; i++) {
        CHECK_BOARD_STATE(board->getValueAt(i, i), cellempty, mark, SL, gamestate);
    }

    return (int)gamestate;
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


TicTacToeGame::~TicTacToeGame() {
    if (this->players) {
        delete[] this->players;
    }
    if (this->arena) {
        delete this->arena;
    }
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* EOF */