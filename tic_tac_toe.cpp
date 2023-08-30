#include <iostream>

using namespace std;

void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << endl;
        if (i < 2)
            cout << "---------" << endl;
    }
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char players[] = {'X', 'O'};
    int currentPlayer = 0;

    while (true) {
        printBoard(board);
        char playerSymbol = players[currentPlayer];
        cout << "Player " << playerSymbol << "'s turn" << endl;

        int row, col;
        cout << "Enter row (0, 1, or 2): ";
        cin >> row;
        cout << "Enter column (0, 1, or 2): ";
        cin >> col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = playerSymbol;
        } else {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        if (checkWin(board, playerSymbol)) {
            printBoard(board);
            cout << "Player " << playerSymbol << " wins!" << endl;
            break;
        } else if (checkDraw(board)) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        currentPlayer = 1 - currentPlayer; // Switch players
    }

    string playAgain;
    cout << "Do you want to play again? (yes/no): ";
    cin >> playAgain;
    if (playAgain == "yes") {
        main();
    }

    return 0;
}

