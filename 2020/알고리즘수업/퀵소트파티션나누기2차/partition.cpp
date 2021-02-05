#include <iostream>

using namespace std;

int *S; //  Arr S

void display(int length)
{
    cout << "Display :::: ";
    for (int i = 0; i <= length; i++)
    {
        cout << S[i] << " ";
    }
    cout << "\n";
}

void partition1(int low, int high, int &pivotPoint)
{
    cout << "파티션 진입 low = " << low << " high = " << high << "\n";
    cout << "파티션 시작 피벗포인트 -> S[" << low << "]:" << S[low] << endl;

    int A[high];
    int B[high];

    int index_a = 0;
    int index_b = 0;

    int pivotItem = S[low];
    for (int i = low + 1; i <= high; i++)
    {
        if (S[i] <= pivotItem)
        {
            cout << S[i] << "를 A에 넣습니다. \n";
            A[index_a] = S[i];
            index_a++;
        }
        else
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
    pivotPoint = index_a;
    display(index_a + index_b);
    cout << "파티션 종료 피벗포인트 -> S[" << pivotPoint << "]:" << S[pivotPoint] << endl;
    return;
}

void partition2(int low, int high, int &pivotPoint)
{
    int C[high];
    int index_low = 0;
    int index_high = high - 1;

    int thisPivotPointItem = S[pivotPoint];

    for (int i = 0; i < high; i++)
    {
        if (i != pivotPoint)
        {
            if (S[i] <= thisPivotPointItem)
            {
                cout << S[i] << "를 C[" << index_low << "]에 넣습니다. \n";
                C[index_low] = S[i];
                index_low++;
            }
            else if (S[i] > thisPivotPointItem)
            {
                cout << S[i] << "를 C[" << index_high << "]에 넣습니다. \n";
                C[index_high] = S[i];
                index_high--;
            }
        }
    }
    C[index_low] = thisPivotPointItem;
    for (int i = 0; i < high; i++)
    {
        S[i] = C[i];
    }
}

void partition3(int low, int high, int &pivotPoint)
{
    int i, j;
    int pivotItem;
    int tmp;

    pivotItem = S[low];
    j = low;
    for (int i = low + 1; i <= high; i++)
    {
        if (S[i] < pivotItem)
        {
            j++;
            tmp = S[i];
            S[i] = S[j];
            S[j] = tmp;
        }
    }
    pivotPoint = j;
    cout << "Pivot Point = " << j << endl;
    tmp = S[low];
    S[low] = S[pivotPoint];
    S[pivotPoint] = tmp;
}

void quickSort(int low, int high)
{
    int pivotPoint;
    if (high > low)
    {
        partition2(low, high, pivotPoint);
        quickSort(low, pivotPoint - 1);
        quickSort(pivotPoint + 1, high);
    }
}

int main(int argc, char const *argv[])
{
    int low = 0;
    int high;
    int length = 0;

    cout << "S length: ";
    cin >> length;

    S = new int[length];
    high = length - 1;

    for (int i = 0; i < length; i++)
    {
        cout << "S[" << i << "]: ";
        cin >> S[i];
    }

    display(high);
    quickSort(low, high);
    display(high);

    return 0;
}
