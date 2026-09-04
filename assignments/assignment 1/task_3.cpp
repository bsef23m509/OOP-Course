#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void printMatrix(char game[6][7], const int rows, const int cols)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << game[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void turn(char game[6][7], int r, int c, char ch)
{
    game[r][c] = ch;
}

int sameValuesinArrayCheck(int arr[], const int size)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i] != arr[0])
        {
            return 0;
        }
    }
    return 1;
}

char winCheck(char game[6][7], const int rows, const int cols)
{

    int winChecks[4];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // horizental check
            if (!(j + 3 >= cols) && game[i][j] != '-')
            {
                for (int k = 0; k < 4; k++)
                {
                    if (game[i][j + k] == game[i][j])
                        winChecks[k] = 1;
                    else
                        winChecks[k] = 0;
                }
                if (sameValuesinArrayCheck(winChecks, 4))
                    return game[i][j];
            }

            // vertical check
            if (!(i + 3 >= rows) && game[i][j] != '-')
            {
                for (int k = 0; k < 4; k++)
                {
                    if (game[i + k][j] == game[i][j])
                        winChecks[k] = 1;
                    else
                        winChecks[k] = 0;
                }
                if (sameValuesinArrayCheck(winChecks, 4))
                    return game[i][j];
            }

            // right diagonal check
            if (!(i + 3 >= rows) && !(j + 3 >= cols) && game[i][j] != '-')
            {
                for (int k = 0; k < 4; k++)
                {
                    if (game[i + k][j + k] == game[i][j])
                        winChecks[k] = 1;
                    else
                        winChecks[k] = 0;
                }
                if (sameValuesinArrayCheck(winChecks, 4))
                    return game[i][j];
            }

            // left diagonal check
            if (!(i + 3 >= rows) && !(j + 3 >= cols) && game[i][j] != '-')
            {
                for (int k = 0; k < 4; k++)
                {
                    if (game[i + k][j - k] == game[i][j])
                        winChecks[k] = 1;
                    else
                        winChecks[k] = 0;
                }

                if (sameValuesinArrayCheck(winChecks, 4))
                    return game[i][j];
            }
        }
    }

    return '0';
}

int main()
{

    system("cls");

    int rows = 6, cols = 7;
    int gameCount = rows * cols, turnCount;
    char winner;
    char game[6][7];
    char playerOne = '1', playerTwo = '2';

    int rowCount[rows], turnCol;

    for (int i = 0; i < cols; i++)
        rowCount[i] = 5;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            game[i][j] = '-';

    cout << endl;
    cout << "Welcome to Connect Four!" << endl;
    cout << "Enter Coloumn on your turn" << endl;

    printMatrix(game, rows, cols);

    for (turnCount = 1; turnCount <= gameCount; turnCount++)
    {
        if (turnCount % 2 == 0)
            cout << "Player 2's Turn" << endl;
        else
            cout << "Player 1's Turn" << endl;

        do
        {
            cout << "Enter coloumn: ";
            cin >> turnCol;
            turnCol = turnCol - 1;

            if (rowCount[turnCol] == -1)
                cout << "All rows are occupied. Enter another coloumn!" << endl;
            else if (turnCol < 0 || turnCol > 6)
                cout << "Invalid coloumn!" << endl;

        } while (turnCol < 0 || turnCol > 6 || rowCount[turnCol] == -1);

        if (turnCount % 2 == 0)
            turn(game, rowCount[turnCol]--, turnCol, '2');
        else
            turn(game, rowCount[turnCol]--, turnCol, '1');

        printMatrix(game, rows, cols);

        winner = winCheck(game, rows, cols);

        if (winner != '0')
        {
            cout << "Congratulations Player " << winner << "! You won the game." << endl;
            turnCount--;
            break;
        }
    }

    if (turnCount > gameCount)
    {
        cout << endl;
        cout << "it's a draw!!!" << endl;
    }

    return 0;
}