#include<iostream>
using namespace std;

char board[3][3];
int choice, row, col;
char turn;
bool draw;
void player();
void updateBoard();
bool gameOver();

void resetBoard() {
    char number = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = number++;
        }
    }
    turn = 'X';
    draw = false;
}

void displayBoard() {
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "     |     |     \n";
    cout << "----- ----- -----\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "     |     |     \n";
    cout << "----- ----- -----\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "     |     |     \n";
}

void player() {
    if (turn == 'X') {
        cout << "Player 1 turn [X]\n";
    }
    else if (turn == 'O') {
        cout << "Player 2 turn [O]\n";
    }
    cout << "Enter your choice: ";
    cin >> choice;
    system("cls");
    switch (choice) {
    case 1:
        row = 0, col = 0;
        break;
    case 2:
        row = 0, col = 1;
        break;
    case 3:
        row = 0, col = 2;
        break;
    case 4:
        row = 1, col = 0;
        break;
    case 5:
        row = 1, col = 1;
        break;
    case 6:
        row = 1, col = 2;
        break;
    case 7:
        row = 2, col = 0;
        break;
    case 8:
        row = 2, col = 1;
        break;
    case 9:
        row = 2, col = 2;
        break;
    default:
        cout << "Invalid number! Try again\n";
        player();
        return;
    }
    updateBoard();
}

void updateBoard() {
    int count = 0;
    if (turn == 'X' && board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = 'O';
        turn = 'X';
    }
    else {
        cout << "Box is already filled. Try another!\n";
        player();
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                count++;
            }
        }
    }

    if (count >= 1) {
        displayBoard();
        player();
        return;
    }
    else {
        gameOver();
    }
}

bool gameOver() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][0] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[0][i] == board[2][i])) {
            return false;
        }
    }

    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[0][2] == board[2][0])) {
        return false;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return true;
            }
        }
    }

    draw = true;
    return false;
}

int main() {
    int choice;
    do {
        resetBoard();
        cout << " ======== TIC-TAC-TOE GAME ========\n\n";
        cout << "Player 1 = 'X'\nPlayer 2 = 'O'\n\n";
        while (gameOver()) {
            displayBoard();
            player();
        }
        displayBoard();
        if (!draw) {
            if (turn == 'X') {
                cout << "\nCongratulations! Player 2 won...\n" << endl;
            }
            else {
                cout << "\nCongratulations! Player 1 won...\n" << endl;
            }
        }
        else {
            cout << "\nIt's a draw...\n";
        }

        cout << "Do you want to play again:\n1. Yes\n2. No\n";
        cout << "Enter your choice: ";
        cin >> choice;

    } while (choice == 1);

    cout << "\nThanks For Playing...\n";

    system("pause>0");
    return 0;
}