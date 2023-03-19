#include <stdio.h>
#include <stdlib.h>
void creat_array(int *arr, int total_size)
{
    printf("Please enter sorted element!!!\n\n");
    for (int i = 0; i < total_size; i++)
    {
        printf("Enter No.%d element: ", i + 1);
        scanf("%d", &arr[i]);
    }
}
int linier_search(int *ptr, int element, int total_size)
{
    int low = 0, mid, high = total_size - 1;
int count=0;
    if (ptr[low] == element)
    {
        return low;
    }
    else if (ptr[high] == element)
    {
        return high;
    }
    else
    {
        while ((low+1)!=high)
        {
            printf("Low-> %d and High -> %d and Mid -> %d \n",low,high,mid);
            count++;
            if(count==10){break;}
            mid = (low + high) / 2;
            if (ptr[mid] == element)
            {
                return mid;
            }
            else if (ptr[mid] < element)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
            
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
    creat_array(num, total_size);
    printf("Which element position you want to know ? -> ");
    scanf("%d", &element);
    index = linier_search(num, element, total_size);
    free(num);
    if (index != -1)
    {
        printf("The position of the element is -> %d\n", index);
    }
    else
    {
        printf("The element -> %d is not present in the array.\n", element);
    }
    return 0;
}