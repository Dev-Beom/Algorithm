#include <cstdio>
int arr[] = {17, 28, 43, 67, 88, 92, 100};
const int arrSize = 7; // 배열의 크기
const int x = 17;      // 찾으려는 값

//반복문으로 구현한 이진 탐색
void binSearch(int n, int S[], int x, int &location)
{
    int low, high, mid;
    low = 0;
    high = n - 1;

    location = -1;

    while (low <= high && location == -1)
    {
        mid = (low + high) / 2;
        if (x == S[mid])
        {
            location = mid;
            printf("%d의 위치는 배열의 %d번째 인덱스에 있습니다.\n", x, location);
        }
        else if (x < S[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
}

//재귀함수로 구현한 이진 탐색
void binSearchRecur(int x, int S[], int low, int high)
{
    int mid;
    if (low > high)
        printf("%d는 배열에 없습니다.\n", x);
    else
    {
        mid = (low + high) / 2;
        if (x == S[mid])
        {
            printf("%d의 위치는 배열의 %d번째 인덱스에 있습니다.\n", x, mid);
        }
        else if (x < S[mid])
            return binSearchRecur(x, arr, low, mid - 1);
        else
            return binSearchRecur(x, arr, mid + 1, high);
    }
}
int main()
{
    int location;
    binSearch(arrSize, arr, x, location);
    binSearchRecur(x, arr, 0, arrSize);
}