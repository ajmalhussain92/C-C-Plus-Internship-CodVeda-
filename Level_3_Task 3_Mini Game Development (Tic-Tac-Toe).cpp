#include <iostream>
using namespace std;

const int SIZE = 3;

char board[SIZE][SIZE];

int main () {
    // Initialize the board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    } 

    // Game loop
    while (true) {
        // Print the current state of the board
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

        // Get the player input
        char player;
        cout << "Player 1 (X) to move: ";
        cin >> player;

        // Handle player move
        int x, y;
        bool valid = false;
        while (!valid) {
            cout << "Enter row (1-3): ";
            cin >> x;
            cout << "Enter column (1-3): ";
            cin >> y;
            if (x >= 1 && x <= SIZE && y >= 1 && y <= SIZE) {
                if (board[x-1][y-1] == '-') {
                    board[x-1][y-1] = player;
                    valid = true;
                } else {
                    cout << "Position already occupied. Try again." << endl;
                }
            } else {
                cout << "Invalid position. Try again." << endl;
            }
        }

        // Check if the game is over
        bool winner = false;
        for (int i = 0; i < SIZE; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0]!= '-') {
                cout << "Player " << board[i][0] << " wins!" << endl;
                winner = true;
                break;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i]!= '-') {
                cout << "Player " << board[0][i] << " wins!" << endl;
                winner = true;
                break;
            }
        }
        if (!winner) {
            if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0]!= '-') {
                cout << "Player " << board[0][0] << " wins!" << endl;
                winner = true;
            } else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2]!= '-') {
                cout << "Player " << board[0][2] << " wins!" << endl;
                winner = true;
            }
        }
        if (!winner) {
            // Check for draw
            bool draw = true;
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    if (board[i][j] == '-') {
                        draw = false;
                        break;
                    }
                }
                if (!draw) break;
            }
            if (draw) {
                cout << "It's a draw!" << endl;
            }
        }
		
        // Switch players
        char nextPlayer = (player == 'X')? 'O' : 'X';
        player = nextPlayer;
    }

    return 0;
}