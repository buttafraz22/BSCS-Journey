#include <iostream>
#include <fstream>
using namespace std;
void printmaze();

const int i = 44;
const int j = 164;

char maze[i][j];

main()
{
    system("cls");
    printmaze();
}
void printmaze()
{

    char box = 219;
    char box2 = 220;
    char box1 = 221;
    char box3 = 178;
    char litbox = 176;
    char box4 = 222;
    char box5 = 223;

    maze = {
        {box4, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', box3, box3, box3, box3, box3, box3, box3, box3, box3, box3, box3, box3, box3, box3, box3, box3, litbox, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box3, litbox, '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box3, litbox, '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box3, litbox, '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box3, litbox, '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box3, litbox, '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box3, litbox, '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box3, litbox, '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box3, litbox, '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box3, litbox, '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', box3, litbox, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box3, litbox, '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', box3, litbox, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', box3, litbox, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', box3, litbox, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, '^', box4, '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', box4, '^', box4},
        {box4, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box, box}};

    for (int row = 0; row < i; row++)
    {
        for (int col = 0; col < j; col++)
        {
            cout << maze[row][col];
        }
        cout << endl;
    }
}
bool savemaze()
{
    bool condition = false;
    int savecount = 0;
    fstream savemaze;
    savemaze.open("savemaze.txt", ios::out);
    for (int row = 0; row < i; row++)
    {
        for (int col = 0; col < j; col++)
        {
            savemaze << maze[row][col];
            savecount++;
        }
        savemaze << endl;
    }
    savemaze.close();
    if (savecount == i)
    {
        condition = true;
    }
    return condition;
}