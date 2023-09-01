#include <stdio.h>
#include <stdlib.h>
void creat_array(int *arr, int total_size)
{

    for (int i = 0; i < total_size; i++)
    {
        printf("Enter No.%d element: ", i + 1);
        scanf("%d", &arr[i]);
    }
}
int linier_search(int *ptr, int element, int total_size)
{
    for (int i = 0; i < total_size; i++)
    {
        if (ptr[i] == element)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int total_size, element, index;
    printf("Enter how many number you want to input ? -> ");
    scanf("%d", &total_size);
    int *num = calloc(total_size, sizeof(int));
    creat_array(num,total_size);
    printf("Which element position you want to know ? -> ");
    scanf("%d", &element);
    index = linier_search(num, element, total_size);
    if (index != -1)
    {
        printf("The position of the element is -> %d ", index);
    }
    else
    {
        printf("The element -> %d is not present in the array.", element);
    }
    return 0;
}