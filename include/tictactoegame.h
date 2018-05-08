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

    public:
        TicTacToeGame();

        void Play();

        /**
         * @func 
         */
        void Display() const;

        ~TicTacToeGame();
};

#endif // TICTACTOEGAME_H
/* EOF */
