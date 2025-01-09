#include <iostream>
#include <conio.h>
#include "Console.h"
#include <stdlib.h>
#include <ctime>
using namespace std;

struct Coordinate_System
{
    char COORD[300][300];

    void ini()
    {
        for (int i = 0; i < 300; i++)
        {
            for (int j = 0; j < 300; j++)
            {
                COORD[i][j] = 'f';
            }
        }
    }

    void display()
    {
        for (int i = 0; i < 300; i++)
        {
            for (int j = 0; j < 300; j++)
            {
                cout << COORD[i][j] << ", ";
            }
            cout << endl;
        }
    }
};

void bomb(Console c, Coordinate_System *f, int x, int y)
{
    static char key;
    f->COORD[x][y] = 'b';
    while (f->COORD[x][y] == 'b')
    {
        if (f->COORD[x][y] == 'f')
        {
            c.gotoxy(x, y);
            cout << "BOM";
        }
        switch (key)
        {
        case 'q':
            c.gotoxy(x, y);
            break;

        default:
            break;
        }
    }
}

void map(Console c, char Difficulty, int MaxX, int MaxY, Coordinate_System *f)
{

    int x = 0;
    int y = 0;

    for (int i = 0; i < MaxY + 1; i++)
    {
        x = 0;
        c.gotoxy(x, y);
        if (y == 0 || y == MaxY)
        {
            c.changeColor(12);
            for (int j = 0; j < MaxX / 2; j++)
            {
                cout << "*-";
            }
            cout << "*";
        }
        else if (y % 2 == 0)
        {
            c.changeColor(11);
            x = 0;
            for (int j = 0; j < MaxX; j++)
            {
                if (j == 0)
                {
                    cout << "*";
                }
                else if (j % 3 == 0 || j % 3 == 2)
                {
                    cout << "-";
                }
                x++;
                c.gotoxy(x, y);
            }
            x--;
            c.gotoxy(x, y);
            cout << "*";
        }
        else
        {
            c.changeColor(11);
            c.gotoxy(x, y);
            cout << "*";
            for (int j = 0; j < MaxX; j++)
            {
                x++;
                c.gotoxy(x, y);
                if (x % 4 == 0)
                {
                    cout << "|";
                }
            }
            x--;
            c.gotoxy(x, y);
            cout << "*";
            for (int y = 3; y < MaxY; y += 4)
                for (int x = 5; x < MaxX; x += 8)
                {
                    c.changeColor(8);
                    c.gotoxy(x, y);
                    cout << "XXX";
                    f->COORD[x][y] = 'c';
                }
        }
        y += 1;
    }
}

int menu(Console c, int *x, int *y)
{
    system("cls"); // clearing the screen

    *x = (c.getMaxX() / 2) - 8;
    *y = 13;
    for (int i = 0; i < 15; i++)
    {
        c.gotoxy(*x, *y);
        if (*y == 13 || *y == 27)
            cout << "-----------------------------";
        else
            cout << "*\t\t\t\t  *";
        *y += 1;
    }

    *x = c.getMaxX() / 2;
    *y = 15;
    c.gotoxy(*x, *y);
    cout << "Start a new game";
    *y += 2;
    c.gotoxy(*x, *y);
    cout << "Load";
    *y += 2;
    c.gotoxy(*x, *y);
    cout << "Difficulty";
    *y += 2;
    c.gotoxy(*x, *y);
    cout << "Manual";
    *y += 2;
    c.gotoxy(*x, *y);
    cout << "Scores";
    *y += 2;
    c.gotoxy(*x, *y);
    cout << "Exit";
    *y = 15;
    *x -= 5;
    c.gotoxy(*x, *y);
    cout << "-->";

    char key;
    while (true)
    {
        key = getch();
        switch (key)
        {
        case 's':
            if (*y < 25)
            {
                c.gotoxy(*x, *y);
                cout << "   ";
                *y += 2;
                c.gotoxy(*x, *y);
                cout << "-->";
            }
            break;
        case 'w':
            if (*y > 15)
            {
                c.gotoxy(*x, *y);
                cout << "   ";
                *y -= 2;
                c.gotoxy(*x, *y);
                cout << "-->";
            }
            break;
        case 13:
            if (*y == 15)
            {
                return 1;
            }
            else if (*y == 25)
            {
                system("cls");
                cout << "Thanks For Playing ";
                return 6;
            }
            break;
        default:
            break;
        }
    }
}

void placeCharacter(Console c, int *x, int *y, string character, int MaxX, int MaxY, Coordinate_System *f)
{
    c.gotoxy(*x, *y);
    c.changeColor(14);
    cout << character;
    char key;
    int Bomb_X;
    int Bomb_Y;
    while (true)
    {
        key = getch();
        c.changeColor(14);
        switch (key)
        {
        case 'w':
            if (*y > 1)
            {
                if (f->COORD[*x][*y - 2] == 'f')
                {
                    if (f->COORD[*x][*y] == 'f' || f->COORD[*x][*y] == 'p')
                    {
                        c.gotoxy(*x, *y);
                        cout << "   ";
                    }
                    if (f->COORD[*x][*y] == 'p')
                    {
                        f->COORD[*x][*y] = 'f';
                    }
                    *y -= 2;
                    f->COORD[*x][*y] = 'p';
                    c.gotoxy(*x, *y);
                    cout << character;
                }
            }
            break;

        case 's':
            if (*y < MaxY - 1)
            {
                if (f->COORD[*x][*y + 2] == 'f')
                {
                    if (f->COORD[*x][*y] == 'f' || f->COORD[*x][*y] == 'p')
                    {
                        c.gotoxy(*x, *y);
                        cout << "   ";
                    }
                    if (f->COORD[*x][*y] == 'p')
                    {
                        f->COORD[*x][*y] = 'f';
                    }
                    *y += 2;
                    f->COORD[*x][*y] = 'p';
                    c.gotoxy(*x, *y);
                    cout << character;
                }
            }
            break;

        case 'd':
            if (*x < MaxX - 4)
            {
                if (f->COORD[*x + 4][*y] == 'f')
                {
                    if (f->COORD[*x][*y] == 'f' || f->COORD[*x][*y] == 'p')
                    {
                        c.gotoxy(*x, *y);
                        cout << "   ";
                    }
                    if (f->COORD[*x][*y] == 'p')
                    {
                        f->COORD[*x][*y] = 'f';
                    }
                    *x += 4;
                    f->COORD[*x][*y] = 'p';
                    c.gotoxy(*x, *y);
                    cout << character;
                }
            }
            break;

        case 'a':
            if (*x > 2)
            {
                if (f->COORD[*x - 4][*y] == 'f')
                {
                    if (f->COORD[*x][*y] == 'f' || f->COORD[*x][*y] == 'p')
                    {
                        c.gotoxy(*x, *y);
                        cout << "   ";
                    }
                    if (f->COORD[*x][*y] == 'p')
                    {
                        f->COORD[*x][*y] = 'f';
                    }
                    *x -= 4;
                    f->COORD[*x][*y] = 'p';
                    c.gotoxy(*x, *y);
                    cout << character;
                }
            }
            break;
        case 'e':
            Bomb_X = *x;
            Bomb_Y = *y;
            c.gotoxy(Bomb_X, Bomb_Y);
            f->COORD[Bomb_X][Bomb_Y] = 'b';
            cout << "BOM";
            break;
        case 'q':
            f->COORD[Bomb_X][Bomb_Y] = 'f';
            c.gotoxy(Bomb_X, Bomb_Y);
            cout << "   ";
            if (Bomb_X + 4 < MaxX - 4)
            {
                if (f->COORD[Bomb_X + 4][Bomb_Y] != 'c')
                {
                    c.gotoxy(Bomb_X + 4, Bomb_Y);
                    cout << "   ";
                    f->COORD[Bomb_X + 4][Bomb_Y] = 'f';
                }
            }
            if (Bomb_X - 4 > 2)
            {
                if (f->COORD[Bomb_X - 4][Bomb_Y] != 'c')
                {
                    c.gotoxy(Bomb_X - 4, Bomb_Y);
                    cout << "   ";
                    f->COORD[Bomb_X - 4][Bomb_Y] = 'f';
                }
            }
            if (Bomb_Y - 2 > 1)
            {
                if (f->COORD[Bomb_X][Bomb_Y - 2] != 'c')
                {
                    c.gotoxy(Bomb_X, Bomb_Y - 2);
                    cout << "   ";
                    f->COORD[Bomb_X][Bomb_Y - 2] = 'f';
                }
            }
            if (Bomb_Y + 2 < MaxY - 1)
            {
                if (f->COORD[Bomb_X][Bomb_Y + 2] != 'c')
                {
                    c.gotoxy(Bomb_X, Bomb_Y + 2);
                    cout << "   ";
                    f->COORD[Bomb_X][Bomb_Y + 2] = 'f';
                }
            }
            break;
        default:
            break;
        }
    }
}

void Block(Console c, int MaxY, int n, int X_Blocks, Coordinate_System *f)
{
    srand(time(0));
    int randomNum;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < MaxY; j += 2)
        {
            randomNum = ((rand() % X_Blocks) * 4) + 1;
            if (!((randomNum == 1 && j == 1) || (randomNum == 5 && j == 1) || (randomNum == 1 && j == 3)))
            {
                c.changeColor(13);
                c.gotoxy(randomNum, j);
                cout << "_-_";
                f->COORD[randomNum][j] = 'b';
            }
        }
    }
}

int main()
{
    Console c;
    char key;
    int x = 0;
    int y = 0;
    int MaxX = 69;
    int MaxY = 20;
    int X_Blocks = (MaxX - 1) / 4;

    Coordinate_System f;
    f.ini();

    c.changeColor(10);
    c.setFullScreen();
    if (menu(c, &x, &y) == 1)
    {
        system("cls");
        Block(c, MaxY, 5, X_Blocks, &f);
        map(c, 'L', MaxX, MaxY, &f);
        c.changeColor(8);
        x = 1, y = 1;
        placeCharacter(c, &x, &y, "SS", MaxX, MaxY, &f);
    }
    else
    {
        return 0;
    }
}