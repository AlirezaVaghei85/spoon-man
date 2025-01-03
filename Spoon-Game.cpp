#include <iostream>
#include <conio.h>
#include "Console.h"
using namespace std;

void map(Console c, char Difficulty)
{
    system("cls");

    int x = 0;
    int y = 0;

    for (int i = 0; i < 21; i++)
    {
        x = 0;
        c.gotoxy(x, y);
        if (y == 0 || y == 20)
        {
            cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
        }
        else if (y % 2 == 0)
        {
            cout << "* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- *";
        }
        else
        {
            // cout << "*\t\t\t\t\t\t\t\t       *";
            c.gotoxy(x, y);
            cout << "*";
            for (int j = 0; j < 69; j++)
            {
                x++;
                c.gotoxy(x, y);
                if (x % 4 == 0)
                    cout << "|";
            }
            x--;
            c.gotoxy(x, y);
            cout << "*";
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

void placeCharacter(Console c, int *x, int *y, string character)
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
            c.gotoxy(*x, *y);
            cout << "  ";
            *y -= 2;
            c.gotoxy(*x, *y);
            cout << character;
            break;

        case 's':
            c.gotoxy(*x, *y);
            cout << "  ";
            *y += 2;
            c.gotoxy(*x, *y);
            cout << character;
            break;

        case 'd':
            c.gotoxy(*x, *y);
            cout << "  ";
            *x += 4;
            c.gotoxy(*x, *y);
            cout << character;
            break;

        case 'a':
            c.gotoxy(*x, *y);
            cout << "  ";
            *x -= 4;
            c.gotoxy(*x, *y);
            cout << character;
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

    c.changeColor(2);
    c.setFullScreen();
    if (menu(c, &x, &y) == 1)
    {
        map(c, 'L');
        x = 2, y = 1;
        placeCharacter(c, &x, &y, "SS");
    }
    else
    {
        return 0;
    }
}