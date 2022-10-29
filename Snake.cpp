// Required libraries:

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

// Declaring global variables.
bool life;
const int width = 80;
const int height = 20;
int x, y, fx, fy, score;
int tx[100], ty[100];
int tail;
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir;

// Function to declare the values of variables:
void Establish()
{

    life = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fx = rand() % width;
    fy = rand() % height;
    score = 0;
}

// Function to draw the grid of the game and to place snake and fruit randomly.
void Design()
{

    system("cls");
    cout << "\t\t\t::::::Welcome to Aasteen ka Saanp::::::" << endl;
    for (int i = 0; i <= width + 1; i++)
    {
        cout << "|";
    }
    cout << endl;
    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                cout << "|";
            }
            if (i == y && j == x)
            {
                cout << "O";
            }
            else if (i == fy && j == fx)
            {
                cout << "*";
            }
            else
            {
                bool sketch = false;
                for (int k = 0; k < tail; k++)
                {
                    if (tx[k] == j && ty[k] == i)
                    {
                        cout << "o";
                        sketch = true;
                    }
                }
                if (!sketch)
                {
                    cout << " ";
                }
            }

            if (j == width - 1)
            {
                cout << "|";
            }
        }
        cout << endl;
    }

    for (int i = 0; i <= width + 1; i++)
    {
        cout << "|";
    }
    cout << endl;

    cout << "\t\t\t\tPlayer Score >>>>> " << score << endl;
}

// Function to take the input from the keyboard
void Input()
{

    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            life = true;
            break;
        }
    }
}

// Function to write the main driving logic
void Logic()
{

    int pre_x = tx[0];
    int pre_y = ty[0];
    int pre_x2, pre_y2;
    tx[0] = x;
    ty[0] = y;

    for (int i = 1; i < tail; i++)
    {
        pre_x2 = tx[i];
        pre_y2 = ty[i];
        tx[i] = pre_x;
        ty[i] = pre_y;
        pre_x = pre_x2;
        pre_y = pre_y2;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        if (x < 0)
        {
            cout << "\n!!!!!Game Over!!!!!" << endl;
        }
        break;
    case RIGHT:
        x++;
        if (x > width)
        {
            cout << "\n!!!!!Game Over!!!!!" << endl;
        }
        break;
    case UP:
        y--;
        if (y < 0)
        {
            cout << "\n!!!!!Game Over!!!!!" << endl;
        }
        break;
    case DOWN:
        y++;
        if (y > height)
        {
            cout << "\n!!!!!Game Over!!!!!" << endl;
        }
        break;
    default:
        break;
    }

    // Restricted Boundary
    if (x > width || x < 0 || y > height || y < 0)
    {
        life = true;
    }
    /*
    Infinite boundary
    if (x >= width+2)
        x = 0;
    else if (x < 0)
        x = width-1;
    if (y >= height)
        y = 0;
    else if (x < 0)
        y = height - 1;
    */

    for (int i = 0; i < tail; i++)
    {
        if (tx[i] == x && ty[i] == y)
        {
            life = true;
        }
    }
    if (x == fx && y == fy)
    {

        score = score + 10;
        fx = rand() % width;
        fy = rand() % height;
        tail++;
    }
}

// Driver Code
int main()
{
    Establish();
    while (!life)
    {
        Design();
        Input();
        Logic();
        Sleep(50);
    }
    return 0;
}