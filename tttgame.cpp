#include <iostream>

#include "tictactoegame.h"

using namespace std;

int main(int argc, char *argv[])
{
    TicTacToeGame *ttt;
    ttt = new TicTacToeGame();
    
    /* game play */
    //ttt->Play();
    // test
    if (ttt->IsSolvable()) {
        cout << "Game produces a result." << endl;
    } else {
        cout << "Will produce a draw" << endl;
    }

    delete ttt;

    return 0;
}