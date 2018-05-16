/**
 * @file arena.h
 * @author augustronics@gmail.com
 * @date 06 May 2018
 * 
 * @brief Header file for Arena
 * 
 * Arena is the space where the game is played. For example, for TicTacToe it
 * is a 3x3 board.
 * 
 * Copyright (c) 2018, augustronics@gmail.com
 */

#ifndef __ARENA_H
#define __ARENA_H

#include <list>

using namespace std;

class Move;
class Player;

/**
 * @brief Arena abstract class
 */
class Arena {
    public:
        /**
         * @func Display
         * @brief Displays the arena
         * 
         * This needs to be implemented as per the type of UI required. By
         * default all derived boards show a text-based UI.
         */
        virtual void Display() const = 0;

        /**
         * @func listmoves
         * @brief Generates a list of the possible moves on the board
         * @return list of moves
         */
        virtual list<Move> ListMoves() const = 0;

        /**
         * @func MakeMove
         * @brief Makes a move on the game
         */
        virtual int MakeMove(Move *move, Player *player) = 0;

        /**
         * @func ResetMove
         * @brief Clears a previously made move
         */
        virtual void ResetMove(Move *move) = 0;

        /**
         * @func ResetMove
         * @brief Clears a previously made move
         * @param row the position row
         * @param col the postition col
         */
        virtual void ResetMove(int row, int col) = 0;

        virtual ~Arena() = 0;
};

inline Arena::~Arena() {}

#endif // __ARENA_H
/* EOF */