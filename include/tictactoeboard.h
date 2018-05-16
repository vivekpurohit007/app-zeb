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

        int MakeMove(Move *move, Player *player);
        void ResetMove(Move *move);
        void ResetMove(int row, int col);

        void Display() const;

        ~TicTacToeBoard();

};
#endif // __TICTACTOEBOARD_H

/* EOF */
