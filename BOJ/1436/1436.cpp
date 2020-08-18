#include <iostream>

int main(int argc, char const *argv[])
{
    int lengthIndex[9];
    int resultIndex[10000];
    int input;
    int accessCount = 0;
    bool forStateBreak = false;

    // lengthIndex[1] = 0;

    // std::cout << lengthIndex[1] << sizeof(lengthIndex) / 4 << std::endl;

    for (int index = 0;; index++)
    {
        lengthIndex[0] = index / 100000000;              //억의 자리수
        lengthIndex[1] = (index % 100000000) / 10000000; //천만의 자리수
        lengthIndex[2] = (index % 10000000) / 1000000;   //백만의 자리수
        lengthIndex[3] = (index % 1000000) / 100000;     //십만의 자리수
        lengthIndex[4] = (index % 100000) / 10000;       //만의 자리수
        lengthIndex[5] = (index % 10000) / 1000;         //천의 자리수
        lengthIndex[6] = (index % 1000) / 100;           //백의 자리수
        lengthIndex[7] = (index % 100) / 10;             //십의 자리수
        lengthIndex[8] = (index % 10);                   //일의 자리수
        for (int i = (sizeof(lengthIndex) / 4) - 3; i > 0; i--)
        {
            if (lengthIndex[i] == 6 && lengthIndex[i + 1] == 6 && lengthIndex[i + 2] == 6)
            {
                forStateBreak = true;
            }
        }
        if (forStateBreak == true)
        {
            resultIndex[accessCount] = index;
            accessCount++;
            forStateBreak = false;
            if (accessCount > 9999)
            {
                break;
            }
        }
    }
    for (;;)
    {
        std::cin >> input;
        std::cout << resultIndex[input - 1] << std::endl;
    }
    return 0;
}