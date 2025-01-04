#include <iostream>
#include <conio.h>
//gdghhxgjvcvbv
#include "Console.h"
using namespace std;

void map(Console c, char Difficulty, int MaxX, int MaxY)
{
    system("cls");

    int x = 0;
    int y = 0;

    for (int i = 0; i < MaxY + 1; i++)
    {
        x = 0;
        c.gotoxy(x, y);
        if (y == 0 || y == MaxY)
        {
            for (int j = 0; j < MaxX / 2; j++)
            {
                cout << "*-";
            }
            cout << "*";
        }
        else if (y % 2 == 0)
        {
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
                    c.gotoxy(x, y);
                    cout << "XX";
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

void placeCharacter(Console c, int *x, int *y, string character, int MaxX, int MaxY)
{
    c.gotoxy(*x, *y);
    cout << character;
    char key;
    while (true)
    {
        key = getch();
        switch (key)
        {
        case 'w':
            if (*y > 1)
            {
                c.gotoxy(*x, *y);
                cout << "  ";
                *y -= 2;
                c.gotoxy(*x, *y);
                cout << character;
            }
            break;

        case 's':
            if (*y < MaxY - 1)
            {
                c.gotoxy(*x, *y);
                cout << "  ";
                *y += 2;
                c.gotoxy(*x, *y);
                cout << character;
            }
            break;

        case 'd':
            if (*x < MaxX - 3)
            {
                c.gotoxy(*x, *y);
                cout << "  ";
                *x += 4;
                c.gotoxy(*x, *y);
                cout << character;
            }
            break;

        case 'a':
            if (*x > 2)
            {
                c.gotoxy(*x, *y);
                cout << "  ";
                *x -= 4;
                c.gotoxy(*x, *y);
                cout << character;
            }
            break;
        default:
            break;
        }
    }
}

int main()
{
    Console c;
    char key;
    int x = 0;
    int y = 0;
    int MaxX = 65;
    int MaxY = 4;

    c.changeColor(2);
    c.setFullScreen();
    if (menu(c, &x, &y) == 1)
    {
        map(c, 'L', MaxX, MaxY);
        x = 2, y = 1;
        placeCharacter(c, &x, &y, "SS", MaxX, MaxY);
    }
    else
    {
        return 0;
    }
}
