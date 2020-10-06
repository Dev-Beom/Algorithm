#include "Location2D.h"
#include <stack>
#include <queue>
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
    if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) //  현재 위치 즉 r, c가 MAZE_SIZE에 벗어나지 않았는지 검사하는 것
        return false;
    else
        return map[r][c] == '0' || map[r][c] == 'x'; //   현재 위치의 상태가 0이거나 x면 true 를 반환 아니면 false를 반환
}

class MazeRunner
{
private:
    int MAZE_SIZE;
    char map[10][10];

public:
    MazeRunner(const int MAZE_SIZE, char map[10][10]);
};

MazeRunner::MazeRunner(const int MAZE_SIZE, char map[10][10])
{
    this->MAZE_SIZE = MAZE_SIZE;
    this->map[10][10] = map[10][10];
}



int main(int argc, char const *argv[])
{
    // stack<Location2D> locStack;
    queue<Location2D> locQueue;
    Location2D entry(1, 0);
    // locStack.push(entry);

    int counter = 0;

    locQueue.push(entry);

    while (locQueue.empty() == false) //  locStack 이 비어있지 않으면
    {
        counter++;
        Location2D here = locQueue.front(); //  초기엔 entry(1,0)
        locQueue.pop();                     //  locStack을 뺌

        int r = here.row, c = here.col;
        printf("(%d,%d) ", r, c); //  현재 위치
        if (map[r][c] == 'x')
        {
            printf(" 미로 탐색 성공\n");
            for (int i = 0; i < MAZE_SIZE; i++)
            {
                for (int j = 0; j < MAZE_SIZE; j++)
                {
                    // printf("%c", map[i][j]);
                    if (map[i][j] == '1')
                    {
                        printf(" ■ ");
                    }
                    else if (map[i][j] == '0')
                    {
                        printf("   ");
                    }
                    else if (map[i][j] == 'e')
                    {
                        printf(" ○ ");
                    }
                    else if (map[i][j] == 'x')
                    {
                        printf(" ◎ ");
                    }
                    else if (map[i][j] == '*')
                    {
                        printf(" □ ");
                    }
                }
                printf("\n");
            }

            return 0;
        }
        else
        {
            map[r][c] = '*';
            if (isValidLoc(r - 1, c)) //좌
                locQueue.push(Location2D(r - 1, c));
            if (isValidLoc(r + 1, c)) //우
                locQueue.push(Location2D(r + 1, c));
            if (isValidLoc(r, c - 1)) //하
                locQueue.push(Location2D(r, c - 1));
            if (isValidLoc(r, c + 1)) //상
                locQueue.push(Location2D(r, c + 1));
        }
    }
    printf("미로 탐색 실패\n");
    return 0;
}
