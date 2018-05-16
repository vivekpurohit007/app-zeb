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
#include <cstdio>

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

    this->cellsRemaining = MAX_CELLS;
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

int TicTacToeBoard::getCellsRemaining() const {
    return this->cellsRemaining;
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

    this->cellsRemaining--;

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

    this->cellsRemaining++;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

list<Move> TicTacToeBoard::ListMoves() const {
	list<Move> moves;
	Move move;

#ifdef DEBUG
	printf ("\n%s: Moves: ", __func__);
#endif

	for (int r = 0; r < DEGREE; r++) {
		for (int c = 0; c < DEGREE; c++) {
			if (this->board[r][c] == EMPTY) {
				move.setRow(r); move.setCol(c);
#ifdef DEBUG
				printf ("(%d, %d) ", move.getRow(), move.getCol());
#endif
				moves.push_back(move);
			}
		}
	}

	return moves;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

list<Move> TicTacToeBoard::ListMoves(Move start) const {
	list<Move> moves; //= new list<int[2]>;
	Move move;
	int row = start.getRow();
	int col = start.getCol();

	/*
	 * NW  N  NE
	 * W   *   E
	 * SW  S  SE
	 */
	/* push all row, col pairs */
    moves.push_back(start);

	move.setRow(row-1); move.setCol(col-1);	moves.push_back(move); /* North West */
	move.setRow(row-1); move.setCol(col);	moves.push_back(move); /* North */
	move.setRow(row-1); move.setCol(col+1);	moves.push_back(move); /* North East */
	move.setRow(row);   move.setCol(col+1);	moves.push_back(move); /* East */
    move.setRow(row+1); move.setCol(col+1);	moves.push_back(move); /* South East */
	move.setRow(row+1); move.setCol(col);	moves.push_back(move); /* South */
	move.setRow(row+1); move.setCol(col-1);	moves.push_back(move); /* South West */
	move.setRow(row);   move.setCol(col-1);	moves.push_back(move); /* West */

	list<Move>::iterator it = moves.begin();

#ifdef DEBUG
	printf ("\n%s: Moves from (%d,%d)", __func__, start.getRow(), start.getCol());

	printf ("\n%s: Moves: ", __func__);
	for (it = moves.begin(); it != moves.end(); it++) {
		printf ("(%d, %d) ", it->getRow(), it->getCol());
	}

	printf ("\n%s: Legal: ", __func__);
#endif

	/* remove moves that already contain vales */
	/* loop over all moves */
	list<Move> legalmoves;

	for (it = moves.begin(); it != moves.end(); it++) {
		/* check for validity */
        row = it->getRow();
	    col = it->getCol();

		if (((row >= 0 && row < DEGREE) && (col >= 0 && col < DEGREE))
			&& (this->board[row][col] == EMPTY)) {

			move.setRow(row); move.setCol(col);
#ifdef DEBUG
			printf ("\n%s: (%d, %d)", __func__, move.getRow(), move.getCol());
#endif
			legalmoves.push_back(move);
		}
	}

	return legalmoves;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void TicTacToeBoard::Display() const {
    cout << "\n+---+---+---+" << endl;
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