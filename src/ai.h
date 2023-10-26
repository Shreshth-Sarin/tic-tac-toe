#pragma once

#include "board.h"

// An artificial intelligence for playing tic-tac-toe.
class TicTacToeAI {

public:

    // Initializes the AI with the given values (X or O) for itself
    // and its opponent.
    TicTacToeAI(Player aiPlayer, Player opponent);

    // Returns the best move for the AI player, given the current state
    // of the tic-tac-toe board. (Assumes the AI player has the next turn.)
    // Move is in the range [1,SPACES].
    int getBestMove(const TicTacToeBoard& board) const;

private:

    Player aiPlayer;
    Player opponent;
};

// struct Node {
//     int score;
//     int move;
// };

// Node minimax(const TicTacToeBoard& board, Player currentPlayer, Player aiPlayer){}

// // Node minimax(const TicTacToeBoard& board, bool maximize) const
// // {
// //     // TODO
// // }

// int TicTacToeAI::getBestMove(const TicTacToeBoard& board) const
// {
//     return minimax(board, true).move;
// }
