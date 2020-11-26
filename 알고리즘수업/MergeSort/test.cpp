#include <cstdio>
int S[10] = {10, 3, 6, 1, 4, 7, 9, 2, 8, 5};
void swap(int &x, int &y)
{
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}
void partition(int low, int high, int &pivotpoint)
{
    int i, j;
    int pivotitem;
    pivotitem = S[low];
    j = low;
    for (i = low + 1; i <= high; i++)
    {
        if (S[i] < pivotitem)
        {
            j++;
            swap(S[i], S[j]);
        }
    }
    pivotpoint = j;
    swap(S[low], S[pivotpoint]);
}
void quicksort(int low, int high)
{
    int pivotpoint;
    if (high > low)
    {
        partition(low, high, pivotpoint);
        quicksort(low, pivotpoint - 1);
        quicksort(pivotpoint + 1, high);
    }
}

int main()
{
    quicksort(0, 9);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", S[i]);
    }
}