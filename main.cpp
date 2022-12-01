#include <iostream>
#include <stdlib.h>

using namespace std;

const int MAP_SIZE = 3;
string map[MAP_SIZE][MAP_SIZE];
bool turn = true;
int actions = 0;

void clearMap();
void printMap();
void getPos();
bool setValueFromPos(int pos, string value);
bool checkWinner();

int main()
{
    clearMap();
    getPos();

    return 0;
}

void clearMap()
{
    for (int row = 0; row < MAP_SIZE; row++)
    {
        for (int column = 0; column < MAP_SIZE; column++)
            map[row][column] = to_string(row * 3 + column + 1);
    }
}

void printMap()
{
    system("clear");
    cout << endl;

    for (int row = 0; row < MAP_SIZE; row++)
    {
        for (int column = 0; column < MAP_SIZE; column++)
            cout << map[row][column] << ((column < 2) ? " | " : "");

        cout << endl
             << ((row < 2) ? "---------" : "")
             << endl;
    }
}

void getPos()
{
    int pos;
    printMap();

    cout << "[P"
         << ((turn) ? "1" : "2")
         << "] "
         << "Scegli una posizione : ";
    cin >> pos;

    if (!setValueFromPos(pos, (turn) ? "X" : "O"))
    {
        cout << endl
             << "POSIZIONE NON VALIDA!!!"
             << endl;
        getPos();
        return;
    }

    if (checkWinner())
    {
        printMap();
        cout << endl
             << "Bravo P" << (turn ? "1" : "2")
             << " hai vinto!!!"
             << endl;
        return;
    }

    if (++actions == 9)
    {
        cout << endl
             << "PAREGGIO!!!"
             << endl;
        return;
    }

    turn = !turn;
    getPos();
}

bool setValueFromPos(int pos, string value)
{
    for (int row = 0; row < MAP_SIZE; row++)
    {
        for (int column = 0; column < MAP_SIZE; column++)
        {
            if (map[row][column] != to_string(pos))
                continue;

            map[row][column] = value;
            return true;
        }
    }

    return false;
}

bool checkWinner()
{
    string midValue = map[1][1];

    if (midValue == map[0][0] && midValue == map[2][2])
        return true;

    if (midValue == map[2][0] && midValue == map[0][2])
        return true;

    for (int i = 0; i < MAP_SIZE; i++)
    {
        string rowValue = map[i][1];

        if (rowValue == map[i][0] && rowValue == map[i][2])
            return true;

        string colValue = map[1][i];

        if (colValue == map[0][i] && colValue == map[2][i])
            return true;
    }

    return false;
}