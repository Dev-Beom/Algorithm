#include <iostream>

int main(int argc, char const *argv[])
{
    int length;
    std::cin >> length;
    int arr[length];
    int tmp = 0;


    for (int i = 0; i < length; i++)
    {
        std::cin >> arr[i];
    }
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] > arr[j]){
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
    for(int i = 0; i < length; i++){
        std::cout << arr[i] << std::endl;
    }
    return 0;
}
