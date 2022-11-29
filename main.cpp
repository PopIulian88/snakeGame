#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
using namespace std;
int lineSnake = 5, coloSnake = 3, direction = 'R', score = 0;
char table[12][22];
struct snakeTail
{
    int line, col;
}tail[201];
void createBoard()
{
    int i, j;
    for (i = 0; i <= 11; i++)
    {
        table[i][0] = '#';
        table[i][21] = '#';
    }
    for (j = 0; j <= 21; j++)
    {
        table[0][j] = '#';
        table[11][j] = '#';
    }
    for (i = 1; i < 11; i++)
        for (j = 1; j < 21; j++)
            table[i][j] = ' ';
}
void snake()
{
    int i;
    for (i = 1; i <= score; i++)
        table[tail[i].line][tail[i].col] = 'o';
    table[lineSnake][coloSnake] = '0';
}
void afisBoard()
{
    snake();
    system("CLS");
    int i, j;
    cout << "      Score: " << score << '\n';
    for (i = 0; i <= 11; i++)
    {
        for (j = 0; j <= 21; j++)
            cout << table[i][j];
        cout << '\n';
    }
}
void food()
{
    int line, colomn;
    line = rand() % 10 + 1;
    colomn = rand() % 20 + 1;
    table[line][colomn] = '$';
    srand(time(NULL));
}
void commands()
{
    if (_kbhit())
    {
        switch (_getch())
        {
            case 'w':
            {
                if(direction != 'D')
                    direction = 'U';
                break;
            }
            case 's':
            {
                if(direction != 'U')
                    direction = 'D';
                break;
            }
            case 'a':
            {
                if(direction != 'R')
                    direction = 'L';
                break;
            }
            case 'd':
            {
                if(direction != 'L')
                    direction = 'R';
                break;
            }
        }
    }
}
void moves()
{
    switch(direction)
    {
        case 'U':
        {
            Sleep(80);
            table[lineSnake][coloSnake] = ' ';
            lineSnake--;
            break;
        }
        case 'D':
        {
            Sleep(80);
            table[lineSnake][coloSnake] = ' ';
            lineSnake++;
            break;
        }
        case 'L':
        {
            Sleep(40);
            table[lineSnake][coloSnake] = ' ';
            coloSnake--;
            break;
        }
        case 'R':
        {
            Sleep(40);
            table[lineSnake][coloSnake] = ' ';
            coloSnake++;
            break;
        }
    }
}
bool gameOver(int line, int colo)
{
    if (table[line][colo] == 'o')
        return 1;
    if (table[line][colo] == '#')
        return 1;
    return 0;
}
bool eat()
{
    if (table[lineSnake][coloSnake] == '$')
    {
        score++;
        table[lineSnake][coloSnake] = ' ';
        food();
        return 1;
    }
    return 0;
}
void game()
{
    while (!gameOver(lineSnake, coloSnake))
    {
        int j;
        afisBoard();
        commands();
        moves();
        if (eat())
        {
            for (j = score; j > 1; j--)
            {
                tail[j].line = tail[j - 1].line;
                tail[j].col = tail[j - 1].col;
            }
            tail[1].line = lineSnake;
            tail[1].col = coloSnake;
        }
        else
        {
            table[tail[score].line][tail[score].col] = ' ';
            for (j = score; j > 1; j--)
            {
                tail[j].line = tail[j - 1].line;
                tail[j].col = tail[j - 1].col;
            }
            tail[1].line = lineSnake;
            tail[1].col = coloSnake;
        }
    }
}
int main()
{
    char somethinc[100];
    createBoard();
    srand(3);
    food();
    snake();
    afisBoard();
    cout << "\n  Move: W A S D \n  Eat the first $ to game really start\n  But be careful is fast\n";
    cout << '\n' << "Are you reddy?" << "\n\n" << "Type somethinc to start" << "\n\n";
    cin.getline(somethinc, 100);
    game();
    Sleep(0);
    cout << "\n\n";
    cout << "#################";
    cout << "\n#               #\n#   Game Over   #\n#               #\n#";
    cout << "   Score: " << score << "    #\n#               #\n";
    cout << "#################\n";
    cout << "    NICE ONE\n\n";
    cout << " Type somethinc to close the game: ";
    cin.getline(somethinc, 100);
    cout << "\n Are you sure?\n\n ";
    cin.getline(somethinc, 100);
}
