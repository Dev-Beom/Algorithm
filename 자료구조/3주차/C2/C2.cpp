#include "Location2D.h"
#include <stack>
#include "stdio.h"
#include <iostream>

using namespace std;

const int MAZE_SIZE = 6;
char map[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1'},
    {'e', '0', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '1', '1'},
    {'1', '0', '1', '0', '0', 'x'},
    {'1', '1', '1', '1', '1', '1'},
};

bool isValidLoc(int r, int c)
{
    if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE)
        return false;
    else
        return map[r][c] == '0' || map[r][c] == 'x';
}

int main(int argc, char const *argv[])
{
    stack<Location2D> locStack;
    Location2D entry(1, 0);
    locStack.push(entry);

    while (locStack.empty() == false)
    {
        Location2D here = locStack.top();
        locStack.pop();

        int r = here.row, c = here.col;
        printf("(%d,%d) ", r, c);
        if (map[r][c] == 'x')
        {
            printf(" 미로 탐색 성공\n");
            for (int i = 0; i < MAZE_SIZE; i++)
            {
                for (int j = 0; j < MAZE_SIZE; j++)
                {
                    printf(" %c ", map[i][j]);
                }
                printf("\n");
            }

            return 0;
        }
        else
        {
            map[r][c] = '*';
            if (isValidLoc(r - 1, c))
                locStack.push(Location2D(r - 1, c));
            if (isValidLoc(r + 1, c))
                locStack.push(Location2D(r + 1, c));
            if (isValidLoc(r, c - 1))
                locStack.push(Location2D(r, c - 1));
            if (isValidLoc(r, c + 1))
                locStack.push(Location2D(r, c + 1));
        }
    }
    printf("미로 탐색 실패\n");
    return 0;
}
