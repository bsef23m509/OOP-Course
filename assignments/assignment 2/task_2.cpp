#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include <cwchar>
#include "utility.h"
using namespace std;

#define GRID_START_X 20
#define GRID_END_X 44
#define GRID_START_Y 6
#define GRID_END_Y 30
#define GRID_SIZE 25

#define MINIONS_AMOUNT 100

class Minion
{

    int id;

    // designs
    char face = 2;
    ConsoleColor color = black;
    ConsoleColor bgColor = yellow;
    // personal attributes
    int speed;
    int power;
    bool life;
    // positional attributes
    int colX;
    int colY;
    int gridX;
    int gridY;

public:
    // Getters
    int getGridX()
    {
        return this->gridX;
    }
    int getGridY()
    {
        return this->gridY;
    }
    int getcolX()
    {
        return this->colX;
    }
    int getcolY()
    {
        return this->colY;
    }
    int getId()
    {
        return this->id;
    }
    bool isAlive()
    {
        return this->life;
    }

    // Setters
    void setId(int id)
    {
        this->id = id;
    }
    // Constructor
    Minion()
    {

        this->colX = rand() % (GRID_END_X - GRID_START_X) + GRID_START_X;
        this->colY = rand() % (GRID_END_Y - GRID_START_Y) + GRID_START_Y;

        this->gridX = this->colY - GRID_START_Y;
        this->gridY = this->colX - GRID_START_X;

        this->power = rand() % 5 + 1;
        this->speed = 1;
        this->life = true;
    }

    void printMinion()
    {
        if (this->life == false)
            return;

        SetColor(this->color, this->bgColor);
        setCursorAt(colX, colY);
        cout << face;
        setCursorAt(0, 0);
        SetColor(white, black);
    }

    void death(Minion *gameGrid[GRID_SIZE][GRID_SIZE])
    {
        this->life = false;
        gameGrid[this->gridX][this->gridY] = NULL;
    }

    void move(Minion *gameGrid[GRID_SIZE][GRID_SIZE])
    {
        int direction = rand() % 4 + 1;

        // move right
        gameGrid[this->gridX][this->gridY] = NULL;

        if (direction == 1)
        {
            this->colX += speed;
            this->gridY += speed;
        }
        // move left
        else if (direction == 3)
        {
            this->colX -= speed;
            this->gridY -= speed;
        }
        // move down
        else if (direction == 2)
        {
            this->colY += speed;
            this->gridX += speed;
        }
        // move up
        else
        {
            this->colY -= speed;
            this->gridX -= speed;
        }

        // Checks for wall collision
        if (this->colX > GRID_END_X)
        {

            this->colX = (this->colX % GRID_END_X) + GRID_START_X - 1;
            this->gridY = (this->gridY % GRID_SIZE);
        }
        else if (this->colY > GRID_END_Y)
        {

            this->colY = (this->colY % GRID_END_Y) + GRID_START_Y - 1;
            this->gridX = (this->gridX % GRID_SIZE);
        }

        else if (this->colX < GRID_START_X)
        {

            this->colX += GRID_SIZE;
            this->gridY += GRID_SIZE;
        }
        else if (this->colY < GRID_START_Y)
        {

            this->colY += GRID_SIZE;
            this->gridX += GRID_SIZE;
        }

        if (gameGrid[this->gridX][this->gridY] == NULL)
        {
            gameGrid[this->gridX][this->gridY] = this;
        }
        // battle
        else
        {

            Minion enemy = *(gameGrid[this->gridX][this->gridY]);
            if (enemy.power == 1 && this->power == 5)
            {
                this->death(gameGrid);
                enemy.incSpeed();
            }
            else if (enemy.power == 5 && this->power == 1)
            {
                enemy.death(gameGrid);
                gameGrid[this->gridX][this->gridY] = this;
                this->incSpeed();
            }
            else if (enemy.power < this->power)
            {
                enemy.death(gameGrid);
                gameGrid[this->gridX][this->gridY] = this;
                this->incSpeed();
            }
            else if (enemy.power > this->power)
            {
                this->death(gameGrid);
                enemy.incSpeed();
            }
            else
            {
                enemy.death(gameGrid);
                this->death(gameGrid);
            }
        }
    }

    void incSpeed()
    {
        this->speed++;
    }
};

class Game
{
    // minions array
    Minion minions[MINIONS_AMOUNT];
    // Game grid
    Minion *gameGrid[GRID_SIZE][GRID_SIZE];

    void printBoundaries()
    {
        for (int i = GRID_START_Y - 2; i <= GRID_END_Y + 2; i++)
        {
            for (int j = GRID_START_X - 2; j <= GRID_END_X + 2; j++)
            {
                if ((j == GRID_START_X - 2 || j == GRID_END_X + 2) ||
                    (i == GRID_START_Y - 2 || i == GRID_END_Y + 2))
                {
                    SetColor(black, dark_white);
                    setCursorAt(j, i);
                    cout << " ";
                }
                else if ((j == GRID_START_X - 1 || j == GRID_END_X + 1) ||
                         (i == GRID_START_Y - 1 || i == GRID_END_Y + 1))
                {
                    SetColor(black, gray);
                    setCursorAt(j, i);
                    cout << " ";
                }
            }
        }
    }

    bool continueGame(Minion minions[])
    {
        int count = 0;
        for (int i = 0; i < MINIONS_AMOUNT; i++)
        {
            if (minions[i].isAlive())
                count++;
        }
        if (count > 2)
            return true;
        return false;
    }

    int winner(Minion minions[])
    {
        int winner = 0;
        for (int i = 0; i < MINIONS_AMOUNT; i++)
        {
            if (minions[i].isAlive())
            {
                winner = minions[i].getId();
            }
        }

        return winner;
    }

    void setConsoleFontSize(int fontWidth, int fontHeight)
    {
        CONSOLE_FONT_INFOEX cfi;
        cfi.cbSize = sizeof(cfi);
        cfi.nFont = 0;
        cfi.dwFontSize.X = fontWidth; // Width of each character in the font
        cfi.dwFontSize.Y = fontHeight;
        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    }

public:
    Game()
    {
        // initializing game grid pointers to null
        for (int i = 0; i < GRID_SIZE; i++)
            for (int j = 0; j < GRID_SIZE; j++)
                gameGrid[i][j] = NULL;

        // initializing minions
        for (int i = 0; i < MINIONS_AMOUNT; i++)
        {
            minions[i] = Minion();
            minions[i].setId(i + 1);
        }

        // Initializing positions of minions on gameGrid
        for (int i = 0; i < MINIONS_AMOUNT; i++)
        {
            gameGrid[minions[i].getGridX()][minions[i].getGridY()] = &minions[i];
        }
    }

    void printStartScreen()
    {

        system("cls");
        setCursorAt(20, 5);
        SetColor(yellow, black);
        this->setConsoleFontSize(0, 36);

        cout << "Minion Rush!" << endl;
        // this->setConsoleFontSize(0, 16);
        setCursorAt(20, 7);
        cout << "Press Enter to start...";

        getchar();
    }

    void printEndScreen(int winner)
    {

        system("cls");
        setCursorAt(20, 5);
        SetColor(yellow, black);
        this->setConsoleFontSize(0, 24);

        if (winner == 0)
            cout << "No one won :( ";
        else
            cout << "Minion#" << winner << " won!" << endl;
    }

    int start()
    {

        this->setConsoleFontSize(0, 20);

        // Game
        while (continueGame(minions))
        {
            system("cls");
            printBoundaries();

            SetColor(white, black);

            // printing minions
            for (int i = 0; i < MINIONS_AMOUNT; i++)
            {
                minions[i].printMinion();
            }

            //  moving minions
            for (int i = 0; i < MINIONS_AMOUNT; i++)
            {
                minions[i].move(gameGrid);
            }

            // delay
            Sleep(200);
            SetColor(white, black);
        }

        SetColor(white, black);
        system("cls");
        setCursorAt(0, 0);

        int win = winner(minions);
        return win;
    }
};

// Function to check for unexpected quitting by pressing CTRL+C
BOOL WINAPI consoleHandler(DWORD signal)
{

    if (signal == CTRL_C_EVENT)
    {

        SetColor(white, black);
        system("cls");

        return false;
    }

    return true;
}

int main()
{
    // Check for unexpected quitting by pressing CTRL+C
    if (!SetConsoleCtrlHandler(consoleHandler, true))
    {
        return 1;
    }

    system("mode 800");
    srand(time(0));

    Game game = Game();

    // game.setConsoleFontSize(0, 16);

    game.printStartScreen();

    int winner = game.start();

    game.printEndScreen(winner);

    SetColor(white, black);

    return 0;
}
