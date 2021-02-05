#include <stdio.h>

int arr[] = {3, 10, 6, 1, 4, 7, 9, 2, 8, 5};
int arrSize = 10;

void display()
{
    printf("\n");
    for (int i = 0; i < arrSize; i++)
    {
        printf("[%d]\t", i);
    }
    printf("\n");
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void swap(int &a, int &b)
{
    if (a != b)
        printf("%d <-> %d\n", a, b);

    int tmp;
    tmp = a;
    a = b;
    b = tmp;

    display();
}

void partition(int low, int high, int &pivotPoint)
{

    int i, j, tmp;
    int pivotItem;
    pivotItem = arr[low];
    printf("now PivotItem = %d\n", pivotItem);

    j = low;
    printf("j[%d] = [%d]\n", j, arr[j]);

    for (int i = low + 1; i <= high; i++)
    {
        printf("i[%d] = [%d]\n", i, arr[i]);
        if (arr[i] < pivotItem)
        {
            j++;
            printf("j[%d] = [%d]\n", j, arr[j]);
            printf("now J = %d\n", j);
            swap(arr[i], arr[j]);
        }
    }
    printf("\n");
    pivotPoint = j;
    swap(arr[low], arr[pivotPoint]);
}

void quickSort(int low, int high)
{
    int pivotPoint;
    if (high > low)
    {
        partition(low, high, pivotPoint);
        quickSort(low, pivotPoint - 1);
        quickSort(pivotPoint + 1, high);
    }
}

int main(int argc, char const *argv[])
{
    int low;
    int high;

    low = 0;
    high = 9;

    display();
    quickSort(low, high);

    display();
    printf("\n");
    return 0;
}
