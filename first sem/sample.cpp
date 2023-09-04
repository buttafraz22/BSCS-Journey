#include <iostream>
using namespace std;

char maze[24][71] =
    {
        {"#####################################################################"},
        {"||.. .....................................................  ......  ||"},
        {"||.. %%%%%%%%%%%%%%%%        ...     %%%%%%%%%%%%%%  |%|..   %%%%   ||"},
        {"||..        |%|   |%|     |%|...     |%|        |%|  |%|..    |%|   ||"},
        {"||..        |%|   |%|     |%|...     |%|        |%|  |%|..    |%|   ||"},
        {"||..        %%%%%%%%  . . |%|...     %%%%%%%%%%%%%%     ..   %%%%.  ||"},
        {"||..        |%|       . . |%|...    ............... |%| ..       .  ||"},
        {"||..        %%%%%%%%%%. . |%|...    %%%%%%%%%%%%    |%| ..   %%%%.  ||"},
        {"||..               |%|.             |%|......       |%| ..    |%|.  ||"},
        {"||..     ......... |%|.        P    |%|......|%|        ..    |%|.  ||"},
        {"||..|%|  |%|%%%|%|.|%|. |%|            ......|%|        ..|%| |%|.  ||"},
        {"||..|%|  |%|   |%|..    %%%%%%%%%%%%%  ......|%|         .|%|.      ||"},
        {"||..|%|  |%|   |%|..           ...|%|     %%%%%%        . |%|.      ||"},
        {"||..|%|            .           ...|%|               |%| ..|%|.      ||"},
        {"||..|%|  %%%%%%%%%%%%%%        ...|%|%%%%%%%%%%     |%| ..|%|%%%%%  ||"},
        {"||...............................................   |%| ..........  ||"},
        {"||   ............................................          .......  ||"},
        {"||..|%|  |%|   |%|..    %%%%%%%%%%%%%  ......|%|    |%| ..|%|.      ||"},
        {"||..|%|  |%|   |%|..           ...|%|     %%%%%%    |%| ..|%|.      ||"},
        {"||..|%|            .     G     ...|%|               |%| ..|%|.      ||"},
        {"||..|%|  %%%%%%%%%%%%%%        ...|%|%%%%%%%%%%     |%| ..|%|%%%%%  ||"},
        {"||...............................................   |%| ..........  ||"},
        {"||  .............................................          .......  ||"},
        {"#####################################################################"}};

void printMaze()
{
    for (int row = 0; row < 24; row = row + 1)
    {
        for (int col = 0; col < 71; col = col + 1)
        {
            cout << maze[row][col];
        }
        cout << endl;
    }
}
int main(){
    printMaze();
    return 0;
}