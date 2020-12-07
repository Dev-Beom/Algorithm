/*
다음과 같은 모양을 출력하는 순환적인 함수를 작성하라
-------------------X------------------
---------X-------------------X--------
----X---------X---------X---------X---
-X----X----X----X----X----X----X----X-
*/

#include <iostream>

using namespace std;
 
int mark[38]; //각 행을 저장하는 배열
 
void draw_tree(int row, int left, int right);
void display_arrow(int *arr, int left, int right);
 
int main(void)
{
        draw_tree(4, 1, 39);
        return 0;
}
 
void draw_tree(int row, int left, int right)
{
        if (row == 0)
               return;
        for (int i = 0; i < 38; i++)
               mark[i] = 0; //배열 초기화
        int X = 20;
        int next = 20; //다음 X
        for (int i = 0; i < 4 - row; i++)
               X /= 2;//초기 X 위치
        for (int i = 0; i < 3 - row; i++)
               next /= 2;
        mark[X] = 1;
        while (X + next < 38)
        {
               X += next;
               mark[X] = 1; //다음 위치도 표시
        }
        display_arrow(mark, left, right);
        draw_tree(--row, left, right);
}
 
void display_arrow(int *arr, int left, int right)
{
        for (int i = left; i < right; i++)
               if (mark[i])
                       cout << "X";
               else
                       cout << "-";
        cout << endl;
}