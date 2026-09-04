#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "utility.h" // Include the utility header file

using namespace std;

const int GRID_SIZE = 20;
const int NUM_MINIONS = 50;

class Minion
{
private:
    int speed;
    bool life;
    int power;
    // int color;
    int x;
    int y;
    // designs
    char face = 2;
    ConsoleColor color = black;
    ConsoleColor bgColor = yellow;

public:
    Minion()
    {
        speed = 1;
        life = true;
        power = rand() % 5 + 1;

        x = rand() % GRID_SIZE;
        y = rand() % GRID_SIZE;
    }

    // Getters and setters
    void setCol(int col) { x = col; }
    void setRow(int row) { y = row; }
    int getCol() { return x; }
    int getRow() { return y; }
    int getSpeed() { return speed; }
    void setSpeed(int newSpeed) { speed = newSpeed; }
    bool getLife() { return life; }
    void setLife(bool newLife) { life = newLife; }
    int getPower() { return power; }
    void setPower(int newPower) { power = newPower; }
    int getColor() { return color; }
    // void setColor(int newColor) { color = newColor; }

    // Display minion
    void display()
    {
        if (this->life == false)
            return;

        SetColor(color, bgColor);
        setCursorAt(x, y);
        cout << face;
        setCursorAt(0, 0);
        SetColor(white, black);
    }
    // Move minion
    void move(int direction)
    {
        switch (direction)
        {
        case 0: // Up
            y = (y - speed + GRID_SIZE) % GRID_SIZE;
            if (y < 0)
                y += GRID_SIZE;
            break;
        case 1: // Down
            y = (y + speed) % GRID_SIZE;
            break;
        case 2: // Left
            x = (x - speed + GRID_SIZE) % GRID_SIZE;
            if (x < 0)
                x += GRID_SIZE;
            break;
        case 3: // Right
            x = (x + speed) % GRID_SIZE;
            break;
        }
    }
};

// Display track grid
void displayTrackGrid(Minion *trackGrid[GRID_SIZE][GRID_SIZE])
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if (trackGrid[i][j] != nullptr)
            {
                trackGrid[i][j]->display();
            }
        }
    }
}

// Update track grid with minion positions
void updateTrackGrid(Minion minionArr[], Minion *trackGrid[GRID_SIZE][GRID_SIZE])
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            trackGrid[i][j] = nullptr; // Reset track grid
        }
    }

    for (int i = 0; i < NUM_MINIONS; i++)
    {
        if (minionArr[i].getLife())
        {
            int col = minionArr[i].getCol();
            int row = minionArr[i].getRow();

            // Ensure the minion's coordinates are within the grid boundaries
            if (col >= 0 && col < GRID_SIZE && row >= 0 && row < GRID_SIZE)
            {
                trackGrid[col][row] = &minionArr[i];
            }
        }
    }
}

// Move all minions
void moveMinions(Minion minionArr[], Minion *trackGrid[GRID_SIZE][GRID_SIZE])
{
    // Clear previous positions of minions in the track grid
    for (int i = 0; i < NUM_MINIONS; i++)
    {
        if (minionArr[i].getLife())
        {
            int col = minionArr[i].getCol();
            int row = minionArr[i].getRow();

            // Ensure the minion's coordinates are within the grid boundaries
            if (col >= 0 && col < GRID_SIZE && row >= 0 && row < GRID_SIZE)
            {
                trackGrid[col][row] = nullptr; // Set the previous position to nullptr
            }
        }
    }

    // Move minions to new positions and update track grid
    for (int i = 0; i < NUM_MINIONS; i++)
    {
        if (minionArr[i].getLife())
        {
            int direction = rand() % 4; //  0 for up, 1 for down, 2 for left, 3 for right
            minionArr[i].move(direction);

            int col = minionArr[i].getCol();
            int row = minionArr[i].getRow();

            // Ensure the new position is within the grid boundaries
            if (col >= 0 && col < GRID_SIZE && row >= 0 && row < GRID_SIZE)
            {
                trackGrid[col][row] = &minionArr[i]; // Update track grid with new position
            }
        }
    }

    // Check for collisions and handle them
    for (int i = 0; i < NUM_MINIONS; i++)
    {
        for (int j = i + 1; j < NUM_MINIONS; j++)
        {
            if (minionArr[i].getLife() && minionArr[j].getLife() && minionArr[i].getCol() == minionArr[j].getCol() && minionArr[i].getRow() == minionArr[j].getRow())
            {
                // Handle collision
                if (minionArr[i].getPower() > minionArr[j].getPower())
                {
                    minionArr[j].setLife(false);                        // Minion j dies
                    minionArr[i].setSpeed(minionArr[i].getSpeed() + 1); // Increase speed of minion i
                }
                else if (minionArr[i].getPower() < minionArr[j].getPower())
                {
                    minionArr[i].setLife(false);                        // Minion i dies
                    minionArr[j].setSpeed(minionArr[j].getSpeed() + 1); // Increase speed of minion j
                }
                else if (minionArr[i].getPower() == 1 && minionArr[j].getPower() == 5)
                {
                    minionArr[j].setLife(false);                        // Minion j dies
                    minionArr[i].setSpeed(minionArr[i].getSpeed() + 1); // Increase speed of minion i
                }
                else
                {
                    minionArr[i].setLife(false); // Minion i dies
                    minionArr[j].setLife(false); // Minion j dies
                }
            }
        }
    }
} // Check if the game should continue
bool continueGame(Minion minionArr[])
{
    int aliveCount = 0;
    for (int i = 0; i < NUM_MINIONS; i++)
    {
        if (minionArr[i].getLife())
        {
            aliveCount++;
        }
    }
    if (aliveCount > 1)
    {
        return true;
    }
    return false;
}

int main()
{
    srand(time(0));
    Minion minionArr[NUM_MINIONS];
    Minion *trackGrid[GRID_SIZE][GRID_SIZE];

    while (continueGame(minionArr))
    {
        system("cls"); // Clear the console
        updateTrackGrid(minionArr, trackGrid);
        displayTrackGrid(trackGrid);
        moveMinions(minionArr, trackGrid);

        Sleep(100); // pause
    }

    return 0;
}
