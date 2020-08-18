#include <iostream>

int main(int argc, char const *argv[])
{
    int row = 0;
    int column = 0;
    int minim = 9999;

    int cNum = 0;

    int bNum = 0;
    int wNum = 0;

    int bMinim = 9999;
    int wMinim = 9999;

    char bMap[8][8] = {
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}};

    char wMap[8][8] = {
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}};

    // std::cout << "start2" << std::endl;

    std::cin >> row;
    std::cin >> column;

    char **ary = new char *[row];
    for (int i = 0; i < row; i++)
    {
        ary[i] = new char[column];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            std::cin >> ary[i][j];
        }
    }
    // for (int i = 0; i < row; i++)
    // { //확인위해 값 출력
    //     for (int j = 0; j < column; j++)
    //     {
    //         std::cout << ary[i][j] << " ";
    //     }
    //     std::cout << '\n';
    // }

    for (int n = 0; n <= row - 8; n++)
    {
        for (int m = 0; m <= column - 8; m++)
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (ary[i + n][j + m] != bMap[i][j])
                    {
                        bNum++;
                    }
                    if (ary[i + n][j + m] != wMap[i][j])
                    {
                        wNum++;
                    }
                }
            }
            if (bNum <= bMinim)
            {
                bMinim = bNum;
            }
            if (wNum <= wMinim)
            {
                wMinim = wNum;
            }
            bNum = 0;
            wNum = 0;
        }
    }
    if (bMinim <= wMinim)
    {
        minim = bMinim;
    }
    else
    {
        minim = wMinim;
    }

    // std::cout << "count : ";
    std::cout << minim << std::endl;
    for (int i = 0; i < row; i++)
    { //메모리 해제 , 행마다 해제해주고
        delete[] ary[i];
    }
    delete[] ary; //마지막으로 행도 해제

    return 0;
}
