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
         * @param start the starting move
         * @return true if a result could be found, else false
         */
        bool issolvable(Arena *board, int depth, int turn, Move start);

    public:
        TicTacToeGame();

        void Play();

        /**
         * @func 
         */
        void Display() const;

        int Evaluate();

        ~TicTacToeGame();
};

#endif // TICTACTOEGAME_H
/* EOF */
