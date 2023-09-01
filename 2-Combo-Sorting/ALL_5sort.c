#include <stdio.h>
#include <stdlib.h>

void Input(int *arr, int size)
{
    printf("Enter your elements: \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void Display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
void Swap(int *x, int *y)
{
    *x = *x + *y - (*y = *x);
}
void Bubble_Sort(int *arr, int size)
{
    int flag;
    for (int i = 0; i < size - 1; i++)
    {
        flag = 1;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                Swap(&arr[j], &arr[j + 1]);
                flag = 0;
            }
        }
        if (flag)
            return;
    }
}
void Insertion_Sort(int *arr, int size)
{
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void Selection_Sort(int *arr, int size)
{
    int index;
    for (int i = 0; i < size - 1; i++)
    {
        index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[index] > arr[j])
                index = j;
        }
        Swap(&arr[i], &arr[index]);
    }
}
int QS(int *arr, int low, int high)
{
    int i = low + 1, j = high, key = arr[low];
    do
    {
        while (arr[i] < key)
            i++;
        while (arr[j] > key)
            j--;
        if (i < j)
            Swap(&arr[i], &arr[j]);
    } while (i < j);
    Swap(&arr[low], &arr[j]);
    return j;
}
void Quick_Sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int partition = QS(arr, low, high);
        Quick_Sort(arr, low, partition - 1);
        Quick_Sort(arr, partition + 1, high);
    }
}
void MS(int *arr, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int cpy[100];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            cpy[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            cpy[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        cpy[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        cpy[k] = arr[j];
        j++;
        k++;
    }
    for (i = 0; i < k; i++)
    {
        arr[i] = cpy[i];
    }
}
void Merge_Sort(int *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        Merge_Sort(arr, low, mid);
        Merge_Sort(arr, mid + 1, high);
        MS(arr, low, mid, high);
    }
}
int Big(int *arr, int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
void Count_Sort(int *arr, int size)
{
    int max = (Big(arr, size) + 1);
    int i, j;
    int *cpy = (int *)malloc(max * sizeof(int));
    for (i = 0; i < max; i++)
    {
        cpy[i] = 0;
    }
    for (i = 0; i < size; i++)
    {
        cpy[arr[i]]++;
    }
    i = j = 0;
    while (j < max)
    {
        if (cpy[j] > 0)
        {
            arr[i] = j;
            cpy[j]--;
            i++;
        }
        else
        {
            j++;
        }
    }
}
int main()
{
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    Input(arr, size);
    printf("Before Bubble sorting:\n");
    Display(arr, size);
    // Bubble_Sort(arr, size);
    // printf("After Bubble sorting:\n");
    // Insertion_Sort(arr, size);
    // printf("After Insertion sorting:\n");
    // Selection_Sort(arr, size);
    // printf("After Selection sorting:\n");
    // Quick_Sort(arr, 0, size - 1);
    // printf("After Quick sorting:\n");
    // Merge_Sort(arr, 0, size - 1);
    // printf("After Merge sorting:\n");
    Count_Sort(arr, size);
    printf("After Count sorting:\n");
    Display(arr, size);

    return 0;
}
