#include <iostream>

#include "tictactoegame.h"

using namespace std;

int main(int argc, char *argv[])
{
    TicTacToeGame *ttt;
    ttt = new TicTacToeGame();
    
    /* game play */
    ttt->Play();

    delete ttt;

    return 0;
}