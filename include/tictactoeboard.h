/**
 * @file tictactoeboard.h
 * @author augustronics@gmail.com
 * @date 06 May 2018
 * 
 * @brief Declaration for the tictactoe 3x3 board
 * 
 * Copyright (c) 2018, augustronics@gmail.com
 */

#ifndef __TICTACTOEBOARD_H
#define __TICTACTOEBOARD_H

#include "move.h"
#include "player.h"
#include "tictactoe.h"

using namespace tictactoe;

/**
 * @class TicTacToeBoard
 * @brief The tictactoe 3x3 board
 */
class TicTacToeBoard : virtual public Arena {
    private:
        int board[DEGREE][DEGREE]; /* a 3x3 board */

    public:
        TicTacToeBoard();

        PlayerSymbol getValueAt(int row, int col) const;

        virtual void Display() const;
        virtual int MakeMove(Move *move, Player *player);
        virtual void ResetMove(Move *move);

        /* evaluates the board state */
        virtual int Evaluate();

        ~TicTacToeBoard();

};
#endif // __TICTACTOEBOARD_H

/* EOF */
