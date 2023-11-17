#include<iostream>
using namespace std;

class tictactoe {
public:
    char square[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int checkwin();
    void board();
    void resetBoard();
};

int tictactoe::checkwin() {
    if (square[0] == square[1] && square[1] == square[2]) {
        return 1;
    }
    else if (square[3] == square[4] && square[4] == square[5]) {
        return 1;
    }
    else if (square[6] == square[7] && square[7] == square[8]) {
        return 1;
    }
    else if (square[0] == square[3] && square[3] == square[6]) {
        return 1;
    }
    else if (square[1] == square[4] && square[4] == square[7]) {
        return 1;
    }
    else if (square[2] == square[5] && square[5] == square[8]) {
        return 1;
    }
    else if (square[0] == square[4] && square[4] == square[8]) {
        return 1;
    }
    else if (square[2] == square[4] && square[4] == square[6]) {
        return 1;
    }
    else if (square[0] != '1' && square[1] != '2' && square[2] != '3' && square[3] != '4' && square[4] != '5' && square[5] != '6' && square[6] != '7' && square[7] != '8' && square[8] != '9') {
        return 0;
    }
    else {
        return -1;
    }
}

void tictactoe::board() {
    cout << "\n\nTIC TAC TOE \n\n";
    cout << "Player 1(X) - Player 2(O)" << endl;
    cout << endl;

    cout << "  |     |  " << endl;
    cout << " " << square[0] << " | " << square[1] << " | " << square[2] << " " << endl;
    cout << "__|_____|__" << endl;
    cout << "  |     |  " << endl;
    cout << " " << square[3] << " | " << square[4] << " | " << square[5] << " " << endl;
    cout << "__|_____|__" << endl;
    cout << "  |     |  " << endl;
    cout << " " << square[6] << " | " << square[7] << " | " << square[8] << " " << endl;
    cout << "  |     |  " << endl;
}

void tictactoe::resetBoard() {
    for (int i = 0; i < 9; ++i) {
        square[i] = '1' + i;  
    }
}

int main() {
    char playAgain;

    do {
        int player = 1, i, choice;
        char mark;
        tictactoe game;

        do {
            game.board();
            player = (player % 2) ? 1 : 2;

            cout << "Player " << player << ", enter the number: " << endl;
            cin >> choice;

            mark = (player == 1) ? 'X' : 'O';

            if (choice >= 1 && choice <= 9 && game.square[choice - 1] == '1' + choice - 1) {
                game.square[choice - 1] = mark;
            }
            else {
                cout << "INVALID MOVE!" << endl;
                player--;
                cin.ignore();
                cin.get();
            }

            i = game.checkwin();
            player++;

        } while (i == -1);

        game.board();

        if (i == 1) {
            cout << "CONGRATULATIONS! PLAYER " << --player << " WINS!" << endl;
        }
        else {
            cout << "GAME DRAWN!" << endl;
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

        if (playAgain == 'Y' || playAgain == 'y') {
            game.resetBoard(); // Reset the game board for a new game
        }

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thanks for playing Tic Tac Toe!" << endl;

    cin.ignore();
    cin.get();
    return 0;
}
