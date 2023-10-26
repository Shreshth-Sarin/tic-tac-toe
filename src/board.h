#pragma once

#include <array>

// An enum for representing a tic-tac-toe player or a space
// on the tic-tac-toe board.
enum Player { NONE, X, O };

// Converts a Player enum to its char representation.
char playerToChar(Player p);

// Simulates a tic-tac-toe board game.
class TicTacToeBoard {

public:

    // Total number of spaces on the board
    static const int SPACES = 9;

    // Initializes the board.
    TicTacToeBoard();

    // Prints a visualization of the board to cout.
    void print() const;

    // Returns whether the given move is allowed. Move must be in the range [1,SPACES].
    bool isValidMove(int move) const;

    // Places the given player's piece (X or O) at the given position.
    // Throws InvalidPlayer if the player is invalid or InvalidMove if
    // the move is invalid.
    void move(Player player, int move);

    // Returns whether the game has ended (a player won or there's a tie).
    bool isGameOver() const;

    // Returns whether the board is full and nobody won.
    bool isTie() const;

    // Returns whether the given player has won. Throws InvalidPlayer if
    // the player is invalid.
    bool hasPlayerWon(Player player) const;

    class InvalidMove {};
    class InvalidPlayer {};

private:
    std::array<Player, SPACES> board;
};
