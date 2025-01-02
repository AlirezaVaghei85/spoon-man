#include <iostream>
#include <conio.h>
#include "Console.h"
using namespace std;

void menu(Console c, int *x, int *y)
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

    char key;
    while (true)
    {
        key = getch();
        switch (key)
        {
        case 's':
            c.gotoxy(*x, *y);
            cout << "   ";
            *y += 2;
            c.gotoxy(*x, *y);
            cout << "-->";
            break;
        case 'w':
            c.gotoxy(*x, *y);
            cout << "   ";
            *y -= 2;
            c.gotoxy(*x, *y);
            cout << "-->";
            break;
        case 13:
            if (*y == 25)
            {
                system("cls");
                cout << "Thanks For Playing ";
                //system("PAUSE"); // End the program
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
    int x;
    int y;

    c.changeColor(2);
    c.setFullScreen();
    menu(c, &x, &y);

    c.gotoxy(10, 10);
    cout << GetCursorPos;
    return 0;
}