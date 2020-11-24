#include <cstdio>

using namespace std;
int binsearch(int n, int S[], int x, int &location)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    location = 0;

    while (low <= high && location == 0)
    {
        mid = (low + high) / 2;
        printf("before = %d %d %d %d \n", low, high, mid, location);
        if (x == S[mid])
            location = mid;
        else if (x < S[mid])
            high = mid - 1;
        else
            low = mid + 1;
        printf("after = %d %d %d %d \n", low, high, mid, location);
    }
    return location;
}

int main(int argc, char const *argv[])
{
    int arr[] = {17, 28, 43, 67, 88, 92, 100};
    int n = 7;
    int x = 100;
    int location = 0;
    printf("x의 위치는 arr의 %d인덱스에 있습니다.", binsearch(n, arr, x, location));
    return 0;
}

