#include "board.h"

#include <iostream>

using namespace std;

char playerToChar(Player p) {
    switch (p) {
        case NONE: return ' ';
        case X: return 'X';
        case O: return 'O';
    }
}

TicTacToeBoard::TicTacToeBoard()
{
    // TODO
    for (int i = 0; i < SPACES; i++)
    {
        board[i] = NONE;
    }
}

void TicTacToeBoard::print() const
{
    // TODO
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << playerToChar(board[i * 3 + j]);
            if (j != 2)
            {
                cout << "|";
            }
        }

        cout << endl;

        if (i != 2)
        {
            cout << "-----" << endl;
        }
    }
}

bool TicTacToeBoard::isValidMove(int move) const
{
    if (move >= 1 && move <= SPACES && board[move-1] == NONE)
    {
        return true;
    }
    // TODO
    else{
        return false;
    }
}

void TicTacToeBoard::move(Player player, int move)
{
    // TODO
    if (player == NONE || !isValidMove(move))
    {
        throw InvalidMove();
    }

    board[move - 1] = player;
}

bool TicTacToeBoard::isGameOver() const
{
    // TODO
    // return false;
    return hasPlayerWon(X) || hasPlayerWon(O) || isTie();
}

bool TicTacToeBoard::isTie() const
{
    // TODO
    for (int i = 0; i < SPACES; ++i)
    {
        if (board[i] == NONE)
        {
            return false;
        }
    }
    return true;
}

bool TicTacToeBoard::hasPlayerWon(Player player) const
{
    // TODO

    if (player == NONE)
    {
        throw InvalidPlayer();
    }

    int winCombinations[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };

    for (int i = 0; i < 8; ++i)
    {
        if (board[winCombinations[i][0]] == player &&
            board[winCombinations[i][1]] == player &&
            board[winCombinations[i][2]] == player
        )
        {
            return true;
        }
    }

    return false;
}
