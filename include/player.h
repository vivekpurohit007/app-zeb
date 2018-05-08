/**
 * @file player.h
 * @author augustronics@gmail.com
 * @date 06 May 2018
 * 
 * @brief Game player
 * 
 * Copyright (c) 2018, augustronics@gmail.com
 */

#ifndef __PLAYER_H
#define __PLAYER_H

#include "move.h"
#include "arena.h"
#include "tictactoe.h"

using namespace tictactoe;

/**
 * \class Player
 * @brief Game player
 */
class Player {
    private:
        enum PlayerType type;
        enum PlayerSymbol symbol;
        Arena *arena;

        void makemove(int row, int col); /* worker function */

    public:
        Player();

        /* Getter/Setter functions */
        PlayerType getType();
        void setType(PlayerType type);

        PlayerSymbol getSymbol();
        void setSymbol(PlayerSymbol symbol);

        Arena *getArena();
        void setArena(Arena *arena);

        void MakeMove(int row, int col);
        void MakeMove(Arena *arena, int row, int col);

        ~Player();
};

#endif // __PLAYER_H

/* EOF */