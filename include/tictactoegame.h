/**
 * @file tictactoegame.h
 * @author augustronics@gmail.com
 * @date 06 May 2018
 * 
 * @brief Header file for TicTacToe Game
 * 
 * Copyright (c) 2018, augustronics@gmail.com
 */

#ifndef __TICTACTOEGAME_H
#define __TICTACTOEGAME_H

#include "game.h"

class TicTacToeBoard;

/**
 * @brief The TicTacToe class
 */
class TicTacToeGame : virtual public Game {
    private:

        /**
         * @func issolvable
         * @brief worker function that finds whether the board is solvable or not
         * @param depth the depth to check for
         * @praram turn current player
         * @return true if a result could be found, else false
         */
        bool issolvable(TicTacToeBoard *board, int depth, int turn);

    public:
        TicTacToeGame();

        void Play();

        /**
         * @func 
         */
        void Display() const;

        int Evaluate();

        bool IsSolvable();

        ~TicTacToeGame();
};

#endif // TICTACTOEGAME_H
/* EOF */
