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
#include <cstdio>
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

            //this->arena->isSolvable();
        } else
        if (DRAW == gamestate) {
            cout << "GAME ended in a DRAW." << endl;
        }

        turn = (turn+1)%2;
    }
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 * @param isempty an empty cell found
 * @param value cell value
 * @param seqlen consecutive cells with same value
 * @param state the game state
 */
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
bool TicTacToeGame::IsSolvable() {
    TicTacToeBoard *board = dynamic_cast<TicTacToeBoard*>(this->arena);
    bool terminal = false;

#if 0
    Move move;

    /*
     * X O X
     * X O O
     * O X _
     */
    move.set(0,0);  board->MakeMove(&move, (this->players+0));
    move.set(0,1);  board->MakeMove(&move, (this->players+1));
    move.set(0,2);  board->MakeMove(&move, (this->players+0));
    move.set(1,0);  board->MakeMove(&move, (this->players+0));
    move.set(1,1);  board->MakeMove(&move, (this->players+1));
    move.set(1,2);  board->MakeMove(&move, (this->players+1));
    move.set(2,0);  board->MakeMove(&move, (this->players+1));
    move.set(2,1);  board->MakeMove(&move, (this->players+0));

    terminal = this->issolvable(board, 4, 1);
#else

    terminal = this->issolvable(board, board->getCellsRemaining(), 0);
#endif

    if (terminal) {
        cout << "@@@ Game can End @@@" << endl;
    } else {
        cout << "### Game ends in Draw ###" << endl;
    }

    return true;
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

static int total_moves = 0;

bool TicTacToeGame::issolvable(TicTacToeBoard *board, int depth, int turn) {
    if (!depth)
        return 0;

#ifdef DEBUG
    printf ("\n%s: start", __func__);
    printf ("\n%s: depth=%d, turn=%d", __func__, depth, turn);
#endif
	bool solved = false;
    int status = PLAY;
    Move move;

    /* list moves from the current cell */
    //list<Move> moves = ListMovesFromCell(board, start);
    list<Move> moves = board->ListMoves();

#ifdef DEBUG
    printf ("\n%s: moves list size=%ld", __func__, moves.size());
#endif
    /* loop over all moves */
    list<Move>::iterator it;

    for (it = moves.begin(); it != moves.end(); ++it) {
	    /* make move */
        move.setRow(it->getRow());
        move.setCol(it->getCol());

        if (!board->MakeMove(&move, (this->players+turn))) {
            total_moves++;
#ifdef DEBUG
            printf ("\n%s: [[%d]] processing move(%d,%d) at depth=%d", __func__,
			        total_moves, it->getRow(), it->getCol(), depth);
#endif

            /* evaluate whether this moves leads to a result/draw */
            status = this->Evaluate();
#ifdef DEBUG
            printf ("\n%s: evaluation status=%d.", __func__, status);
#endif
            /* proceed as per the evaluation result */
            switch (status) {
                case RESULT:
#ifdef DEBUG
                    printf ("\n%s: [%c] Won.", __func__, (this->players+turn)->getSymbol());
#endif
                    if (status == RESULT) {
#ifdef DEBUG
                        printf ("\n%s: [[%d]] Move (%d,%d) can produce RESULT.",
                        __func__, total_moves, it->getRow(), it->getCol());
#endif
                        solved = true;
                    }

                    break;

                case PLAY:
#ifdef DEBUG
                    printf ("\n%s: Continue...", __func__);
#endif
                    break;

				case DRAW:
#ifdef DEBUG
                    printf ("\n%s: It's a DRAW", __func__);
#endif
                    break;
            }

            /* if board produces result */
            if (solved) {
                /* display */
                board->Display();

                /* reset move */
                board->ResetMove(it->getRow(), it->getCol());

                return true;
            }

#ifdef DEBUG
            printf ("\n%s: going to depth (%d).", __func__, depth-1);
#endif

            /* process */
            solved = this->issolvable(board, depth-1, !turn);

            /* reset move */
            board->ResetMove(it->getRow(), it->getCol());

            if (solved)
                return solved;
        }

        /* reset move */
        board->ResetMove(it->getRow(), it->getCol());
    }

#ifdef DEBUG
    printf ("\n%s: end", __func__);
#endif

    return solved;
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
