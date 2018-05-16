/**
 * @file game.h
 * @author augustronics@gmail.com
 * @date 06 May 2018
 * 
 * @brief Header file for Game
 * 
 * Copyright (c) 2018, augustronics@gmail.com
 */

#ifndef __GAME_H
#define __GAME_H

#include "arena.h"
#include "player.h"

using namespace std;

class Game {
    protected:
        Arena *arena;
        Player *players;
        int playerCount;
    
    public:
        Game() {}

        void setPlayerCount(int count) {
            this->playerCount = count;
        }
        int getPlayerCount() {
            return this->playerCount;
        }

        void Play() {}

        /**
         * @func Evaluate
         * @brief Evaluates the state of the arena
         *
         * Evaluates whether the game ended in a RESULT/DRAW or still some moves could be made.
         */
        virtual int Evaluate() {
            return 1;
        }

        void Display() const {};
        
        ~Game(){}
};

#endif // __GAME_H
/* EOF */