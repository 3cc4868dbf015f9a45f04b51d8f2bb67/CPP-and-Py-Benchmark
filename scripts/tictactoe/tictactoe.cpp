#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    bool checkWin(char player) {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
        return false;
    }

    bool isFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '-') return false;
            }
        }
        return true;
    }

    pair<int, int> getRandomMove() {
        vector<pair<int, int>> availableMoves;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '-') availableMoves.emplace_back(i, j);
            }
        }
        return availableMoves[rand() % availableMoves.size()];
    }

    void displayBoard() {
        for (const auto& row : board) {
            for (char cell : row) {
                cout << cell << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

public:
    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, '-'));
        currentPlayer = 'X';
    }

    char playGame() {
        while (true) {
            pair<int, int> move = getRandomMove();
            board[move.first][move.second] = currentPlayer;
            displayBoard();
            if (checkWin(currentPlayer)) {
                cout << "Player " << currentPlayer << " wins L bozo!\n\n";
                return currentPlayer;
            }
            if (isFull()) {
                cout << "Damn a draw! Skill issue lol\n\n";
                return '-';
            }
            switchPlayer();
        }
    }
};

int main() {
    srand(time(0));
    int games = 100;
    int xWins = 0, oWins = 0, draws = 0;

    auto startTime = high_resolution_clock::now();

    for (int i = 0; i < games; i++) {
        cout << "Game " << i + 1 << "\n";
        TicTacToe game;
        char result = game.playGame();
        if (result == 'X') xWins++;
        else if (result == 'O') oWins++;
        else draws++;
    }

    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(endTime - startTime);

    cout << "Final Results:\n";
    cout << "X Wins: " << xWins << "\n";
    cout << "O Wins: " << oWins << "\n";
    cout << "Draws: " << draws << "\n";
    cout << "Total Time: " << duration.count() << " ms\n";

    return 0;
}