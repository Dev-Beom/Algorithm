#include <iostream>

using namespace std;

int *S; //  Arr S

void display(int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << S[i] << " ";
    }
    cout << "\n";
}

void partition1(int low, int high, int &pivotPoint)
{
    cout << "파티션 진입 low = " << low << " high = " << high
         << "\n";
    cout << "파티션 시작 피벗포인트 -> S[" << low << "]:" << S[low] << endl;

    int A[high - low + 1];
    int B[high - low + 1];

    int index_a = 0;
    int index_b = 0;

    int pivotItem = S[high / 2];
    for (int i = low + 1; i < high; i++)
    {
        if (S[i] <= pivotItem)
        {
            cout << S[i] << "를 A에 넣습니다. \n";
            A[index_a] = S[i];
            index_a++;
        }
        else if (S[i] > pivotItem)
        {
            cout << S[i] << "를 B에 넣습니다. \n";
            B[index_b] = S[i];
            index_b++;
        }
    }
    for (int i = 0; i < index_a; i++)
    {
        S[i] = A[i];
    }
    S[index_a] = pivotItem;
    for (int i = 0; i < index_b; i++)
    {
        S[i + index_a + 1] = B[i];
    }
    pivotPoint = high / 2;
    cout << "파티션 종료 피벗포인트 -> S[" << low << "]:" << S[low] << endl;
    return;
    // display(high - low);
}

void partition2(int low, int high, int &pivotPoint)
{
}

void partition3(int low, int high, int &pivotPoint)
{
}

void quickSort(int low, int high)
{
    int pivotPoint;
    cout << "퀵소트 시작! 피벗포인트 -> S[" << pivotPoint << "]" << endl;
    if (high > low)
    {
        partition1(low, high, pivotPoint);
        quickSort(low, pivotPoint - 1);
        quickSort(pivotPoint + 1, high);
    }
    else
    {
        return;
    }
}

int main(int argc, char const *argv[])
{
    int low = 0;
    int high;
    int pivotPoint = 0;
    int length = 0;

    cout << "S length: ";
    cin >> length;

    S = new int[length];
    high = length;
    for (int i = 0; i < length; i++)
    {
        cout << "S[" << i << "]: ";
        cin >> S[i];
    }
    display(length);
    // partition1(0, length, pivotPoint);
    quickSort(0, length);
    display(length);
    return 0;
}
