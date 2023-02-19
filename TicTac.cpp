#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

// Jaden

typedef struct win
{
    bool isWon;
    char whoWon; // More like who are we on
} win;


win* check(char board[9], char& whoWon) // takes in the board and checks if it matches any of the winning patterns
{
    win* retval = (win*) malloc(sizeof(win)); // Allocating memory for the structure thats being returned
    char winningPatterns[8][4] = {
        "147", "258", "369",
        "123", "456", "789",
        "159", "357"
    };
    retval->isWon = false;

    for (int i = 0; i < 8; i++)
    {
        int matches = 0;

        for (int c = 0; c < 3; c++)
        {
            char curPoint = winningPatterns[i][c];
            string s(1, curPoint);
            int intCurPoint = stoi(s);

            if (board[intCurPoint - 1] == whoWon) // Switch to x or o
                matches += 1;
            
            if (matches == 3)
                break;
        }

        if (matches >= 3) // find if there is 3 trues inside the temp
        {
            cout << whoWon << "won" << endl;
            retval->isWon = true;
            break;
        }
    }

    if (retval->isWon == false)
    {
        if (whoWon == 'X')
            whoWon = 'O';
        else
            whoWon = 'X';
    }

    return retval;
}


int main()
{
    char res = ' ';
    char board[9] = {
        ' ', ' ', ' ', // 1 2 3
        ' ', ' ', ' ', // 4 5 6
        ' ', ' ', ' ' // 7 8 9
    }; // Creates Tic Tac Toe board

    cout << "Would you like to play tic tac toe? (y/n): ";
    cin >> res;

    if (res == 'y')
    {
        char who = 'X';
        char& turn = who;
        win* init = check(board, turn); // Runs a check just so we can get the isWon so we can start the while loop

        while (init->isWon == false) // While the game has not won
        {
            int boardPlacement;
            win* verdict;
            cout << "Select a spot: " << endl;
            cin >> boardPlacement;
            cout << "You chose spot:" << boardPlacement << endl;

            board[boardPlacement - 1] = turn;
            verdict = check(board, turn);

            for (int i = 0; i < 9; i++)
            {
                if ((i + 1) % 3 == 0)
                    cout << board[i] << endl;

                else
                    cout << board[i];
            }

            if (verdict->isWon == true)
                init->isWon = true;

            free(verdict);
        }

        free(init);
    }

    return 0;
}
