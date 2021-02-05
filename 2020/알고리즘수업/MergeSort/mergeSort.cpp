#include <stdio.h>

void merge(int h, int m, int U[], int V[], int S[])
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < h && j < m)
    {
        if (U[i] < V[j])
        {
            S[k] = U[i];
            i++;
        }
        else
        {
            S[k] = V[j];
            j++;
        }
        k++;
    }

    if (i >= h)
    {
        for (int index = j; index < m; index++, k++)
        {
            S[k] = V[index];
        }
    }
    else
    {
        for (int index = i; index < m; index++, k++)
        {
            S[k] = U[index];
        }
    }
}

void mergeSort(int n, int S[])
{
    const int h = n / 2, m = n - h;
    int U[h], V[m];
    printf("h = %d, m = %d\n", h, m);
    if (n > 1)
    {
        // for (int i = 0; i < h; i++)
        // {
        //     U[i] = S[i];
        // }
        // for (int i = h; i < n; i++)
        // {
        //     V[i - h] = S[i];
        // }

        for (int i = 0; i < h; i++)
        {
            U[i] = S[i];
            V[i] = S[i + h];
        }
        for (int i = 0; i < h; i++)
        {
            printf("U[%d] = %d\n", i, U[i]);
        }
        for (int i = 0; i < m; i++)
        {
            printf("V[%d] = %d\n", i, V[i]);
        }

        mergeSort(h, U);
        mergeSort(m, V);
        merge(h, m, U, V, S);
    }
}

int main(int argc, char const *argv[])
{
    int arrSize = 8;
    int arr[] = {1, 5, 4, 2, 123, 6, 3, 7};
    mergeSort(arrSize, arr);

    for (int i = 0; i < arrSize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
