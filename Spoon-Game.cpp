#include <iostream>
#include <conio.h>
#include "Console.h"
#include <stdlib.h>
#include <ctime>
#include <fstream>
using namespace std;
#define Esc_key 27
#define Enter_key 13

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

    void Save_to_file()
    {
        ofstream last_state("Last_State.txt");
    }
};

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

char Difficulty_menu(Console c)
{
    system("cls"); // clearing the screen

    int x = (c.getMaxX() / 2) - 8;
    int y = 13;
    for (int i = 0; i < 15; i++)
    {
        c.gotoxy(x, y);
        if (y == 13 || y == 27)
            cout << "-----------------------------";
        else
            cout << "*\t\t\t\t  *";
        y += 1;
    }
    x = c.getMaxX() / 2;
    y = 15;
    c.gotoxy(x, y);
    cout << "Easy";
    y = 17;
    c.gotoxy(x, y);
    cout << "Medium";
    y = 19;
    c.gotoxy(x, y);
    cout << "Hard";
    y = 15;
    x -= 5;
    c.gotoxy(x, y);
    cout << "-->";
    char key;
    while (true)
    {
        key = getch();
        switch (key)
        {

            char key;
            while (true)
            {
            case 's':
                if (y < 19)
                {
                    c.gotoxy(x, y);
                    cout << "   ";
                    y += 2;
                    c.gotoxy(x, y);
                    cout << "-->";
                }
                break;
            case 'w':
                if (y > 15)
                {
                    c.gotoxy(x, y);
                    cout << "   ";
                    y -= 2;
                    c.gotoxy(x, y);
                    cout << "-->";
                }
                break;
            case Enter_key:
                if (y == 15)
                {
                    return 'E';
                }
                else if (y == 17)
                {
                    return 'M';
                }
                else if (y == 19)
                {
                    return 'H';
                }
                break;

            default:
                break;
            }
        }
    }
}

void Help_menu(Console c)
{
    c.gotoxy(0, 0);
    cout << "Deep beneath the surface lies a hidden realm, home to tiny creatures known as the Bombarians."
         << " For years, they lived peacefully, powered by an ancient crystal that held the energy of life itself."
         << " But one day, a dark force invaded their land, stole the crystal, and plunged their world into chaos.\n\n"
         << "This is where the hero of the story, Spoon Man, steps in."
         << " He is a brave and ingenious Bombarian whose only weapon is his collection of powerful, handcrafted bombs."
         << " Spoon Man must navigate through perilous mazes, disable deadly traps, and face off against enemy guards to retrieve the lost crystal.\n\n"
         << "But the journey is far more dangerous than it seems. Spoon Man soon discovers that the dark force plans to use the crystal’s power to activate an ancient,"
         << " devastating weapon—one capable of destroying the entire Bombarian realm.\n\n"
         << "Can Spoon Man defeat his enemies, recover the crystal, and save his home in this race against time? It’s all up to his courage and explosive skills.";

    getch();
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
    *y = 17;
    c.gotoxy(*x, *y);
    cout << "Load";
    *y = 19;
    c.gotoxy(*x, *y);
    cout << "Difficulty";
    *y = 21;
    c.gotoxy(*x, *y);
    cout << "Help";
    *y = 23;
    c.gotoxy(*x, *y);
    cout << "Scores";
    *y = 25;
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
        case Enter_key:
            if (*y == 15)
            {
                return 1;
            }
            else if (*y == 19)
            {
                return 3;
            }
            else if (*y == 21)
            {
                return 4;
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

void Block(Console c, int MaxX, int MaxY, int n, int X_Blocks, Coordinate_System *f, int *randomGateX, int *randomGateY)
{
    srand(time(0));
    int randomNum;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < MaxY; j += 2)
        {
            randomNum = ((rand() % X_Blocks) * 4) + 1;
            if (!((randomNum == 1 && j == 1) || (randomNum == 5 && j == 1) || (randomNum == 1 && j == 3)))
            {
                if (f->COORD[randomNum][j] == 'f')
                {
                    c.changeColor(13);
                    c.gotoxy(randomNum, j);
                    cout << "-_-";
                    f->COORD[randomNum][j] = 'a';
                    if (rand() % (n * 2) == 0 && k == 0)
                    {
                        *randomGateX = randomNum;
                        *randomGateY = j;
                        k++;
                    }
                }
            }
        }
    }
    if (k == 0)
    {
        f->COORD[MaxX - 4][MaxY - 1] = 'a';
        c.gotoxy(MaxX - 4, MaxY - 1);
        cout << "_-_";
        *randomGateX = MaxX - 4;
        *randomGateY = MaxY - 1;
    }
}

void Enemy(Console c, int MaxY, int n, int X_Blocks, int *enemy_number, Coordinate_System *f)
{
    srand(time(0));
    int randomNum;
    *enemy_number = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < MaxY; j += 2)
        {
            randomNum = ((rand() % X_Blocks) * 4) + 1;
            if (!((randomNum == 1 && j == 1) || (randomNum == 5 && j == 1) || (randomNum == 1 && j == 3)))
            {
                if (f->COORD[randomNum][j] == 'f')
                {
                    c.changeColor(12);
                    c.gotoxy(randomNum, j);
                    cout << "O-O";
                    f->COORD[randomNum][j] = 'e';
                    *enemy_number += 1;
                }
            }
        }
    }
}

void Game_Over(Console c)
{
    system("cls");

    int x = (c.getMaxX() / 2) - 8;
    int y = 17;
    for (int i = 0; i < 7; i++)
    {
        c.gotoxy(x, y);
        if (y == 17 || y == 23)
            cout << "-----------------------------";
        else
            cout << "*\t\t\t\t  *";
        y += 1;
    }

    x = c.getMaxX() / 2;
    y = 19;
    c.gotoxy(x, y);
    cout << "Game Over!";
    y = 21;
    c.gotoxy(x, y);
    cout << "Return to menu";
    y = 21;
    x -= 5;
    c.gotoxy(x, y);
    cout << "-->";
    getch();
}

void Win_Game(Console c, int x, int y, int P_move, int B_number)
{
    int W = 1;
    system("cls");
    int score = 100000 / (1 + W * P_move + W * B_number);
    x = (c.getMaxX() / 2) - 8;
    y = 13;
    for (int i = 0; i < 15; i++)
    {
        c.gotoxy(x, y);
        if (y == 13 || y == 27)
            cout << "-----------------------------";
        else
            cout << "*\t\t\t\t  *";
        y += 1;
    }
    x = c.getMaxX() / 2;
    y = 15;
    c.gotoxy(x, y);
    cout << "YOU WIN!";
    y = 17;
    c.gotoxy(x, y);
    cout << "Your Score: ";
    y = 19;
    c.gotoxy(x, y);
    cout << score;
    y = 21;
    c.gotoxy(x, y);
    cout << "Return to menu";
    y = 21;
    x -= 5;
    c.gotoxy(x, y);
    cout << "-->";
    getch();
}

void placeCharacter(Console c, int *x, int *y, string character, int MaxX, int MaxY, int enemy_number, Coordinate_System *f, int GateX, int GateY)
{
    c.gotoxy(*x, *y);
    c.changeColor(14);
    cout << character;
    f->COORD[*x][*y] = 'p';
    char key;
    int Bomb_X;
    int Bomb_Y;
    int Player_Movment = 0;
    int Bomb_Number = 0;
    bool Bomb_Placed;

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
                    if (f->COORD[*x][*y] == 'p')
                    {
                        c.gotoxy(*x, *y);
                        cout << "   ";
                        f->COORD[*x][*y] = 'f';
                    }
                    else if (f->COORD[*x][*y] == 'g')
                    {
                        c.gotoxy(*x, *y);
                        cout << "[ ]";
                        f->COORD[*x][*y] = 'g';
                    }
                    *y -= 2;
                    f->COORD[*x][*y] = 'p';
                    c.gotoxy(*x, *y);
                    cout << character;
                    Player_Movment++;
                }
                else if (f->COORD[*x][*y - 2] == 'g')
                {
                    c.gotoxy(*x, *y);
                    cout << "   ";
                    f->COORD[*x][*y] = 'f';
                    *y -= 2;
                    f->COORD[*x][*y] = 'g';
                    c.gotoxy(*x, *y);
                    cout << "[S]";
                    Player_Movment++;
                }
                else if (f->COORD[*x][*y - 2] == 'e')
                {
                    Game_Over(c);
                    return;
                }
            }
            break;

        case 's':
            if (*y < MaxY - 1)
            {
                if (f->COORD[*x][*y + 2] == 'f')
                {
                    if (f->COORD[*x][*y] == 'p')
                    {
                        c.gotoxy(*x, *y);
                        cout << "   ";
                        f->COORD[*x][*y] = 'f';
                    }
                    else if (f->COORD[*x][*y] == 'g')
                    {
                        c.gotoxy(*x, *y);
                        cout << "[ ]";
                        f->COORD[*x][*y] = 'g';
                    }
                    *y += 2;
                    f->COORD[*x][*y] = 'p';
                    c.gotoxy(*x, *y);
                    cout << character;
                    Player_Movment++;
                }
                else if (f->COORD[*x][*y + 2] == 'g')
                {
                    c.gotoxy(*x, *y);
                    cout << "   ";
                    f->COORD[*x][*y] = 'f';
                    *y += 2;
                    f->COORD[*x][*y] = 'g';
                    c.gotoxy(*x, *y);
                    cout << "[S]";
                    Player_Movment++;
                }
                else if (f->COORD[*x][*y + 2] == 'e')
                {
                    Game_Over(c);
                    return;
                }
            }
            break;

        case 'd':
            if (*x < MaxX - 4)
            {
                if (f->COORD[*x + 4][*y] == 'f')
                {
                    if (f->COORD[*x][*y] == 'p')
                    {
                        c.gotoxy(*x, *y);
                        cout << "   ";
                        f->COORD[*x][*y] = 'f';
                    }
                    else if (f->COORD[*x][*y] == 'g')
                    {
                        c.gotoxy(*x, *y);
                        cout << "[ ]";
                        f->COORD[*x][*y] = 'g';
                    }
                    *x += 4;
                    f->COORD[*x][*y] = 'p';
                    c.gotoxy(*x, *y);
                    cout << character;
                    Player_Movment++;
                }
                else if (f->COORD[*x + 4][*y] == 'g')
                {
                    c.gotoxy(*x, *y);
                    cout << "   ";
                    f->COORD[*x][*y] = 'f';
                    *x += 4;
                    f->COORD[*x][*y] = 'g';
                    c.gotoxy(*x, *y);
                    cout << "[S]";
                    Player_Movment++;
                }
                else if (f->COORD[*x + 4][*y] == 'e')
                {
                    Game_Over(c);
                    return;
                }
            }
            break;

        case 'a':
            if (*x > 2)
            {
                if (f->COORD[*x - 4][*y] == 'f')
                {
                    if (f->COORD[*x][*y] == 'p')
                    {
                        c.gotoxy(*x, *y);
                        cout << "   ";
                        f->COORD[*x][*y] = 'f';
                    }
                    else if (f->COORD[*x][*y] == 'g')
                    {
                        c.gotoxy(*x, *y);
                        cout << "[ ]";
                        f->COORD[*x][*y] = 'g';
                    }
                    *x -= 4;
                    f->COORD[*x][*y] = 'p';
                    c.gotoxy(*x, *y);
                    cout << character;
                    Player_Movment++;
                }
                else if (f->COORD[*x - 4][*y] == 'g')
                {
                    c.gotoxy(*x, *y);
                    cout << "   ";
                    f->COORD[*x][*y] = 'f';
                    *x -= 4;
                    f->COORD[*x][*y] = 'g';
                    c.gotoxy(*x, *y);
                    cout << "[S]";
                    Player_Movment++;
                }
                else if (f->COORD[*x - 4][*y] == 'e')
                {
                    Game_Over(c);
                    return;
                }
            }
            break;
        case 'e':
            if (!Bomb_Placed)
            {
                if (f->COORD[*x][*y] != 'g')
                {
                    Bomb_Placed = true;
                    Bomb_X = *x;
                    Bomb_Y = *y;
                    c.gotoxy(Bomb_X, Bomb_Y);
                    f->COORD[Bomb_X][Bomb_Y] = 'b';
                    c.changeColor(15);
                    cout << "BOM";
                    Bomb_Number++;
                }
            }
            break;
        case 'q':
            if (Bomb_Placed)
            {
                Bomb_Placed = false;
                f->COORD[Bomb_X][Bomb_Y] = 'f';
                c.gotoxy(Bomb_X, Bomb_Y);
                cout << "   ";
                if (Bomb_X + 4 <= MaxX - 4)
                {
                    if (f->COORD[Bomb_X + 4][Bomb_Y] != 'c')
                    {
                        c.gotoxy(Bomb_X + 4, Bomb_Y);
                        cout << "   ";
                        if (f->COORD[Bomb_X + 4][Bomb_Y] == 'e')
                        {
                            enemy_number--;
                        }
                        if (f->COORD[Bomb_X + 4][Bomb_Y] == 'p')
                        {
                            Game_Over(c);
                            return;
                        }
                        else
                            f->COORD[Bomb_X + 4][Bomb_Y] = 'f';
                        if (Bomb_X + 4 == GateX && Bomb_Y == GateY)
                        {
                            c.gotoxy(GateX, GateY);
                            cout << "[ ]";
                            f->COORD[GateX][GateY] = 'g';
                        }
                    }
                }
                if (Bomb_X - 4 >= 1)
                {
                    if (f->COORD[Bomb_X - 4][Bomb_Y] != 'c')
                    {
                        c.gotoxy(Bomb_X - 4, Bomb_Y);
                        cout << "   ";
                        if (f->COORD[Bomb_X - 4][Bomb_Y] == 'e')
                        {
                            enemy_number--;
                        }
                        if (f->COORD[Bomb_X - 4][Bomb_Y] == 'p')
                        {
                            Game_Over(c);
                            return;
                        }
                        else
                            f->COORD[Bomb_X - 4][Bomb_Y] = 'f';
                        if (Bomb_X - 4 == GateX && Bomb_Y == GateY)
                        {
                            c.gotoxy(GateX, GateY);
                            cout << "[ ]";
                            f->COORD[GateX][GateY] = 'g';
                        }
                    }
                }
                if (Bomb_Y - 2 >= 1)
                {
                    if (f->COORD[Bomb_X][Bomb_Y - 2] != 'c')
                    {
                        c.gotoxy(Bomb_X, Bomb_Y - 2);
                        cout << "   ";
                        if (f->COORD[Bomb_X][Bomb_Y - 2] == 'e')
                        {
                            enemy_number--;
                        }
                        if (f->COORD[Bomb_X][Bomb_Y - 2] == 'p')
                        {
                            Game_Over(c);
                            return;
                        }
                        else
                            f->COORD[Bomb_X][Bomb_Y - 2] = 'f';
                        if (Bomb_X == GateX && Bomb_Y - 2 == GateY)
                        {
                            c.gotoxy(GateX, GateY);
                            cout << "[ ]";
                            f->COORD[GateX][GateY] = 'g';
                        }
                    }
                }
                if (Bomb_Y + 2 <= MaxY - 1)
                {
                    if (f->COORD[Bomb_X][Bomb_Y + 2] != 'c')
                    {
                        c.gotoxy(Bomb_X, Bomb_Y + 2);
                        cout << "   ";
                        if (f->COORD[Bomb_X][Bomb_Y + 2] == 'e')
                        {
                            enemy_number--;
                        }
                        if (f->COORD[Bomb_X][Bomb_Y + 2] == 'p')
                        {
                            Game_Over(c);
                            return;
                        }
                        else
                            f->COORD[Bomb_X][Bomb_Y + 2] = 'f';
                        if (Bomb_X == GateX && Bomb_Y + 2 == GateY)
                        {
                            c.gotoxy(GateX, GateY);
                            cout << "[ ]";
                            f->COORD[GateX][GateY] = 'g';
                        }
                    }
                }
            }
            break;
        case Enter_key:
            if (f->COORD[*x][*y] == 'g')
            {
                if (enemy_number == 0)
                {
                    Win_Game(c, *x, *y, Player_Movment, Bomb_Number);
                    return;
                }
            }

            break;
        case Esc_key:
            return;
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
    int MaxX = 69;
    int MaxY = 6; // 20
    int X_Blocks = (MaxX - 1) / 4;
    int randomGateX;
    int randomGateY;
    int enemy_number;
    char Difficulty = 'E';
    int menu_option;

    c.changeColor(10);
    c.setFullScreen();
    while (true)
    {
        switch (Difficulty)
        {
        case 'E':
            MaxY = 6;
            break;
        case 'M':
            MaxY = 12;
            break;
        case 'H':
            MaxY = 18;
            break;
        default:
            break;
        }
        Coordinate_System f;
        f.ini();
        menu_option = menu(c, &x, &y);
        switch (menu_option)
        {
        case 1:
            system("cls");
            map(c, 'L', MaxX, MaxY, &f);
            Block(c, MaxX, MaxY, 5, X_Blocks, &f, &randomGateX, &randomGateY);
            Enemy(c, MaxY, 2, X_Blocks, &enemy_number, &f);
            c.changeColor(8);
            x = 1, y = 1;
            placeCharacter(c, &x, &y, "-S-", MaxX, MaxY, enemy_number, &f, randomGateX, randomGateY);
            break;
        case 3:
            system("cls");
            Difficulty = Difficulty_menu(c);
            break;
        case 4:
            system("cls");
            Help_menu(c);
            break;
        case 6:
            exit(0);
            break;
        default:
            break;
        }
    }

    return 0;
}