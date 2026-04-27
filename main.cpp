#include <iostream>
using namespace std;

// Game board
char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

// Scores
int scoreX = 0;
int scoreO = 0;

// Display board
void displayBoard() {
    cout << "\n";
    cout << "+-----------+\n";

    for (int i = 0; i < 3; i++) {
        cout << "|";
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "|\n";

        if (i < 2) cout << "---+---+---\n";
    }

    cout << "+-----------+\n\n";
}

// Check winner
char checkWinner() {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }

    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return ' '; // no winner
}

// Reset board
void resetBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
}

int main() {
    char currentPlayer = 'X';
    int choice;
    char winner;

    while (true) {
        displayBoard();

        cout << "Score -> X: " << scoreX << " | O: " << scoreO << "\n";

        cout << "Player " << currentPlayer << ", enter a number (1-9): ";
        cin >> choice;

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        // Check if move is valid
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = currentPlayer;
        } else {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        winner = checkWinner();

        // Handle winner
        if (winner == 'X') {
            displayBoard();
            cout << "Player X wins!\n";
            scoreX++;
        }
        else if (winner == 'O') {
            displayBoard();
            cout << "Player O wins!\n";
            scoreO++;
        }

        // Restart logic
        if (winner == 'X' || winner == 'O') {
            char again;
            cout << "Play again? (y/n): ";
            cin >> again;

            if (again == 'y') {
                resetBoard();
                currentPlayer = 'X';
                continue;
            } else {
                break;
            }
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}