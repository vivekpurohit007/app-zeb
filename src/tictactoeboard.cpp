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
            this->board[r][c] = EMPTY ;
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

    this->ResetMove(row, col);
}

void TicTacToeBoard::ResetMove(int row, int col) {

        if ((row < 0 || row >= DEGREE)
        || (col < 0 || col >= DEGREE)) {
        cout << __func__ << ": Error: position (" 
             << row << "," << col << ") out of the arena" << endl;
        return;
    }

    /* clear the position */
    this->board[row][col] = EMPTY;
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

TicTacToeBoard::~TicTacToeBoard() {
    /* empty */
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* EOF */