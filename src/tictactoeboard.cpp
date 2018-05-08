/**
 * @file tictactoeboard.cpp
 * @author augustronics@gmail.com
 * @date 06 May 2018
 * 
 * @brief Defines the tictactoe 3x3 board
 * 
 * Copyright (c) 2018, augustronics@gmail.com
 */

#include <iostream>

#include "move.h"
#include "player.h"
#include "tictactoeboard.h"

using namespace std;
using namespace tictactoe;

TicTacToeBoard::TicTacToeBoard() {
    /* init all to 0 */
    for (int r = 0; r < DEGREE; r++) {
        for (int c = 0; c < DEGREE; c++) {
            this->board[r][c] = INVALID ;
        }
    }
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

PlayerSymbol TicTacToeBoard::getValueAt(int row, int col) const {
    /* verify row col */
    if ((row < 0 || row >= DEGREE) 
        || (col < 0 || col >= DEGREE)) {
        cout << __func__ << ": Error: invalid position specified" << endl;
    }

    return (PlayerSymbol)this->board[row][col];

}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void TicTacToeBoard::Display() const {
    cout << "+---+---+---+" << endl;
    for (int r = 0; r < DEGREE; r++) {
        cout << "| ";
        for (int c = 0; c < DEGREE; c++) {
            char val = this->board[r][c];
            cout << (val?(char)val:' ') <<" | ";
        }
        cout << endl;
        cout << "+---+---+---+" << endl;
    }
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

int TicTacToeBoard::MakeMove(Move *move, Player *player) {
    /* verify input */
    if (NULL == move || NULL == player) {
        cout << __func__ << ": Error: invalid input" << endl;
        return -1;
    }

    /* verify move */
    int row = move->getRow();
    int col = move->getCol();

    if ((row < 0 || row >= DEGREE) 
        || (col < 0 || col >= DEGREE)) {
        cout << __func__ << ": Error: position (" 
             << row << "," << col << ") out of the arena" << endl;
        return -1;
    }

    /* check if the position is already filled */
    if (0 != this->board[row][col]) {
        cout << __func__ << ": Error: position (" 
             << row << "," << col << ") already occupied" << endl;
        return -1;
    }

    /* set player new position */
    this->board[row][col] = player->getSymbol();

    return 0;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void TicTacToeBoard::ResetMove(Move *move) {
    /* verify input */
    if (NULL == move) {
        cout << __func__ << ": Error: invalid input" << endl;
        return;
    }

    /* verify move */
    int row = move->getRow();
    int col = move->getCol();

    if ((row < 0 || row >= DEGREE) 
        || (col < 0 || col >= DEGREE)) {
        cout << __func__ << ": Error: position (" 
             << row << "," << col << ") out of the arena" << endl;
        return;
    }

    /* clear the position */
    this->board[row][col] = INVALID;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

int TicTacToeBoard::evaluateDir(int row, int col, Direction dir) {
    //cout << "(" << row << "," << col << "), " << dir;

    if (this->board[row][col] == INVALID) {
        //cout << ": EMPTY FIELDS" << endl;
        return 0;
    }

    int SL = 1; /* sequence lenght */
    int mark = this->board[row][col];

    /* check three boxes */
    /* the (row,col) of the boxes to be checked are found using the switch case */
    /* check three boxes for same Player symbol */
    for (int i = 1; i <= 3; i++) {
        switch (dir) {
            case S:
                row++;
                break;
            case SE:
                row++; col++;
                break;
            case E:
                col++;
                break;
            case SW:
                row++; col--;
                break;
            default:
                cout << __func__ << ": Error: Invalid direction" << endl;    
        }

        if (mark == this->board[row][col]) {
            SL++;
        } else {
            break;
        }
    }

    //cout << ": " << SL << endl;

    return SL;
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
int TicTacToeBoard::Evaluate() {
    if (DEGREE == this->evaluateDir(0, 0, S)) {
        cout << "'" << (char)this->board[0][0] << "' WON" << endl;
    } else
    if (DEGREE == this->evaluateDir(0, 0, SE)) {
        cout << "'" << (char)this->board[0][0] << "' WON" << endl;
    } else
    if (DEGREE == this->evaluateDir(0, 0, E)) {
        cout << "'" << (char)this->board[0][0] << "' WON" << endl;
    } else
    if (DEGREE == this->evaluateDir(0, 1, S)) {
        cout << "'" << (char)this->board[0][1] << "' WON" << endl;
    } else
    if (DEGREE == this->evaluateDir(0, 2, SW)) {
        cout << "'" << (char)this->board[0][2] << "' WON" << endl;
    } else
    if (DEGREE == this->evaluateDir(0, 2, S)) {
        cout << "'" << (char)this->board[0][2] << "' WON" << endl;
    } else
    if (DEGREE == this->evaluateDir(1, 0, E)) {
        cout << "'" << (char)this->board[1][0] << "' WON" << endl;
    } else
    if (DEGREE == this->evaluateDir(2, 2, S)) {
        cout << "'" << (char)this->board[2][2] << "' WON" << endl;
    } else {
        return 0; /* no result yet */
        /* TODO: check whether the game would proceed to a draw */
    }

    return 1;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

TicTacToeBoard::~TicTacToeBoard() {
    /* empty */
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* EOF */