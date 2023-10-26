#include "ai.h"
#include <limits>

using namespace std;

struct Node {
    int score;
    int move;
};

int evaluateBoard(const TicTacToeBoard& board, Player aiPlayer) 
{
    if (board.hasPlayerWon(aiPlayer)) return +1;
    if (board.hasPlayerWon(aiPlayer == X ? O : X)) return -1;
    return 0; // tie or unfinished game
}

Node minimax(const TicTacToeBoard& board, Player currentPlayer, Player aiPlayer) {
    if (board.isGameOver()) {
        return { evaluateBoard(board, aiPlayer), -1 };
    }

    Node bestNode;
    if (currentPlayer == aiPlayer) {
        bestNode.score = numeric_limits<int>::min();
    } else {
        bestNode.score = numeric_limits<int>::max();
    }

    for (int move = 1; move <= TicTacToeBoard::SPACES; ++move) {
        if (board.isValidMove(move)) {
            TicTacToeBoard newBoard = board;
            newBoard.move(currentPlayer, move);
            Node childNode = minimax(newBoard, currentPlayer == X ? O : X, aiPlayer);
            
            if (currentPlayer == aiPlayer) {
                if (childNode.score > bestNode.score) {
                    bestNode.score = childNode.score;
                    bestNode.move = move;
                }
            } else {
                if (childNode.score < bestNode.score) {
                    bestNode.score = childNode.score;
                    bestNode.move = move;
                }
            }
        }
    }
    return bestNode;
}

TicTacToeAI::TicTacToeAI(Player aiPlayer, Player opponent) {
    if (aiPlayer == NONE || opponent == NONE) {
        throw TicTacToeBoard::InvalidPlayer();
    }

    this->aiPlayer = aiPlayer;
    this->opponent = opponent;
}

int TicTacToeAI::getBestMove(const TicTacToeBoard& board) const {
    return minimax(board, aiPlayer, aiPlayer).move;
}
