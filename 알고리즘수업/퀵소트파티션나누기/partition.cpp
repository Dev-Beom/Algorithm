#include <iostream>

using namespace std;

// void partition(index low, index high, index &pivotpoint)
// {
//     index i, j;
//     keytype pivotitem;
//     pivotitem = S[low];
//     j = low;
//     for (i = low + 1; i <= high; i++)
//     {
//         if (S[i] < pivotitem)
//         {
//             j++;
//             exchange S[i] and S[j];
//         }
//     }
//     pivotpoint = j;
//     exchange S[low] and S[pivotpoint];
// }
/*
1. A, B 배열 선언하고 채워주고 S에 A랑 피봇이랑 B를 넣고 끝
2. 이영범 C선언하고 c루프로 만들어주고 c에 s 앞엔 피봇보다 작은거 뒤엔 피봇보다 큰거
*/

void display(int length, int *arr)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

//1. A, B배열을 선언하고 피봇을 기준으로 S들을 나눠 저장.
void partition1(int low, int high, int &pivotPoint, int *arr)
{
    int A[high];
    int B[high];
    int index_a = low;
    int index_b = low;
    int thisPivotPointItem = arr[pivotPoint];

    //  A <- (pivotItem <= thisPivotPointItem)
    //  B <- (pivotItem > thisPivotPointItem)
    for (int i = 0; i < high; i++)
    {
        if (i != pivotPoint)
        {
            if (arr[i] <= thisPivotPointItem)
            {
                cout << arr[i] << "를 A에 넣습니다. \n";
                A[index_a] = arr[i];
                index_a++;
            }
            else if (arr[i] > thisPivotPointItem)
            {
                cout << arr[i] << "를 B에 넣습니다. \n";
                B[index_b] = arr[i];
                index_b++;
            }
        }
    }

    //  S = A + pivotItem + B
    for (int i = 0; i < index_a; i++)
    {
        arr[i] = A[i];
    }
    arr[index_a] = thisPivotPointItem;
    for (int i = 0; i < index_b; i++)
    {
        arr[i + index_a + 1] = B[i];
    }
}

//2. C배열을 선언하고 피봇을 기준으로 Front , Back으로 나눠 저장.
void partition2(int low, int high, int &pivotPoint, int *arr)
{
    int C[high];
    int index_low = 0;
    int index_high = high - 1;

    int thisPivotPointItem = arr[pivotPoint];

    for (int i = 0; i < high; i++)
    {
        if (i != pivotPoint)
        {
            if (arr[i] <= thisPivotPointItem)
            {
                cout << arr[i] << "를 C[" << index_low << "]에 넣습니다. \n";
                C[index_low] = arr[i];
                index_low++;
            }
            else if (arr[i] > thisPivotPointItem)
            {
                cout << arr[i] << "를 C[" << index_high << "]에 넣습니다. \n";
                C[index_high] = arr[i];
                index_high--;
            }
        }
    }
    C[index_low] = thisPivotPointItem;
    for (int i = 0; i < high; i++)
    {
        arr[i] = C[i];
    }    
}

int main(int argc, char const *argv[])
{
    int length = 0;
    int low = 0;
    int high;
    int pivotPoint = 0;

    cout << "length: ";
    cin >> length;
    high = length;

    int S[length];
    pivotPoint = length / 2;
    for (int i = 0; i < length; i++)
    {
        cout << "S[" << i << "]: ";
        cin >> S[i];
    }
    cout << "pivotPoint: S[" << pivotPoint << "] = " << S[pivotPoint] << endl;
    display(length, S);

    partition2(low, high, pivotPoint, S);
    display(length, S);
    return 0;
}
