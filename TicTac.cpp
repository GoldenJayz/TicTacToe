#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;


typedef struct win
{
    bool isWon;
    char whoWon[1];
} win;

/*
    Have a list of patterns that depict if the game has won or not

    Check if each board cell is filled with a character that is o or x
    then check if it matches the pattern

    Or I can make it with singular digits like slot
    1, 2, 3,
    4, 5, 6,
    7, 8, 9
    this makes it so I can use a singular array

    winning patterns singular notation:
    1 4 7
    2 5 8
    3 6 9
    1 2 3
    4 5 6
    7 8 9
    1 5 9
    3 5 7
    then for loop through an array with all the winning patterns
    and check if each one corresponds

    arr = { '147', '258' }

    tempArr = { false, false, false,
                false, false, false,
                false, false, false } // If one matches the pattern then set to true if not break out of the 2nd loop

    for i in arr:
        for c in i:  // for character in each element
            if (board[c] != ' '):
                tempArr[c] = true
            else:
                break

*/

win* check(char board[9]) // takes in the board and checks if it matches any of the winning patterns
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

            if (board[intCurPoint - 1] != ' ') // Switch to x or o
            {
                matches += 1;
            }

            if (matches == 3)
            {
                break;
            }
        }

        if (matches >= 3) // find if there is 3 trues inside the temp
        {
            cout << "won" << endl;
            retval->isWon = true;
            break;
        }
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
        win* init = check(board); // Runs a check just so we can get the isWon so we can start the while loop

        while (init->isWon == false) // While the game has not won
        {
            int boardPlacement;
            win* verdict;
            cout << "Select a spot: " << endl;
            cin >> boardPlacement;
            cout << "You chose spot:" << boardPlacement << endl;

            board[boardPlacement - 1] = 'X';
            verdict = check(board);

            for (int i = 0; i < 9; i++)
            {
                if ((i + 1) % 3 == 0)
                {
                    cout << board[i] << endl;
                }
                else
                {
                    cout << board[i];
                }
            }

            if (verdict->isWon == true)
                init->isWon = true;

            free(verdict);
        }

        free(init);
    }

    return 0;
}
