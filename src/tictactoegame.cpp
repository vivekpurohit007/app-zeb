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
        gamestate = (enum State) this->arena->Evaluate();
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