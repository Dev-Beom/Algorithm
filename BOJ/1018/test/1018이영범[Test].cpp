#include <iostream>

int main(int argc, char const *argv[])
{
    int row = 0;
    int column = 0;
    int minim = 0;
    int cNum = 0;

    std::cout << "start2" << std::endl;

    std::cin >> row;
    std::cin >> column;

    int sizeN = row - 8;
    int sizeM = column - 8;

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
    for (int i = 0; i < row; i++)
    { //확인위해 값 출력
        for (int j = 0; j < column; j++)
        {
            std::cout << ary[i][j] << " ";
        }
        std::cout << '\n';
    }
    for (int n = 0; n <= sizeN; n++)
    {
        std::cout << "Start SizeN Loop" << std::endl;
        for (int m = 0; m <= sizeM; m++)
        {
            std::cout << "Start SizeM Loop" << std::endl;
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    
                }
            }
            if (cNum <= minim)
            {
                minim = cNum;
                cNum = 0;
            }
            else
            {
                cNum = 0;
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (ary[i][j] == ary[i][j + 1])
            {
                // if(ary[i][j] == ary[i + 1][j]){
                // count ++;

                // }
            }
        }
    }
    std::cout << "count : ";
    std::cout << cNum << std::endl;
    for (int i = 0; i < row; i++)
    { //메모리 해제 , 행마다 해제해주고
        delete[] ary[i];
    }
    delete[] ary; //마지막으로 행도 해제

    return 0;
}
