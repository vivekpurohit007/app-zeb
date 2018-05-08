/**
 * @file tictactoe.h
 * @author augustronics@gmail.com
 * @date 06 May 2018
 * 
 * @brief Header file for TicTacToe
 * 
 * Copyright (c) 2018, augustronics@gmail.com
 */

#ifndef __TICTACTOE_H
#define __TICTACTOE_H

namespace tictactoe {
    const int INVALID = 0;
    const int DEGREE = 3;

    /**
     * Only two players can play TicTacToe at one time
     */
    const int MAX_PLAYERS = 2;

    /**
     * \enum PlayerType
     * 
     * @brief Type of the player
    */
    enum PlayerType {
        PLAYER_HUMAN,       /* human player */
        PLAYER_COMPUTER     /* computer player */
    };

    /**
     * \enum PlayerSymbol
     * @brief Symbol of Player
     */
    enum PlayerSymbol {
        PLAYER_CROSS = 'X',
        PLAYER_CIRCLE = 'O'
    };

    enum State {
        DRAW,   /* game is a draw */
        END     /* a player won */
    };

    enum Direction {
        S,      /* move southwards */
        SE,     /* move south-eastwards */
        E,      /* move eastwards */
        SW      /* move south-westwards */
    };
};

#endif // TICTACTOE_H
/* EOF */
