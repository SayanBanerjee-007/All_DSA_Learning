#include <stdio.h>
#include <stdlib.h>
int creat_array(int *arr)
{
    int element_num;
    printf("How many elements tou want to assign ? ->");
    scanf("%d", &element_num);
    for (int i = 0; i < element_num; i++)
    {
        printf("Enter No.%d element: ", i + 1);
        scanf("%d", &arr[i]);
    }
}
void display(int *arr, int element_num)
{
    printf("YOUR ARRAY: \n");
    for (int i = 0; i < element_num; i++)
    {
        printf("%d \t", arr[i]);
    }
    printf("\n");
}
int sorted_insertion(int *arr, int element_num, int element, int position, int total_size)
{
    if (element_num > total_size)
    {
        printf("sorry!! YOUR REQUESETED MEMORY ENDED.\n");
        exit(0);
    }
    for (int i = element_num - 1; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    return 1;
}
int NONsorted_insertion(int *arr, int element_num, int element, int position, int total_size)
{
    if (element_num > total_size)
    {
        printf("sorry!! YOUR REQUESETED MEMORY ENDED.");
        return 0;
    }
    arr[element_num - 1] = arr[position];
    arr[position] = element;
    return 1;
}
int main()
{
    int total_size, element_num, element, position;
    char dession_insertion_type, dession_element;
    printf("Enter the size of array: ");
    scanf("%d", &total_size);
    int *arr = calloc(total_size, sizeof(int));
    element_num = creat_array(arr);
    display(arr, element_num);
    do
    {
        printf("Do you want to insert any element ?(y or n) -> ");
        fflush(stdin);
        scanf("%c", &dession_element);
        if (dession_element != 'y' && dession_element != 'n')
        {
            printf("Try again(y or n) -> ");
            fflush(stdin);
            scanf("%c", &dession_element);
            if (dession_element == 'y')
            {
                goto jump1;
            }
            else
            {
                exit(0);
            }
        }
        else if (dession_element == 'y')
        {
        jump1:
            printf("Enter the element -> ");
            scanf("%d", &element);
            printf("Enter the element position-> ");
            scanf("%d", &position);
            printf("Do you want sorted insetrion ?(y or n) ->");
            fflush(stdin);
            scanf("%c", &dession_insertion_type);
            if (element_num > position)
            {
                element_num++;
            }
            else
            {
                element_num = position + 1;
            }
            if (dession_insertion_type != 'y' && dession_insertion_type != 'n')
            {
                printf("Try again(y or n) -> ");
                fflush(stdin);
                scanf("%c", &dession_insertion_type);
                if (dession_insertion_type == 'y')
                {
                    goto jump2;
                }
                else
                {
                    goto jump3;
                }
            }
            else if (dession_insertion_type == 'y')
            {
            jump2:
                sorted_insertion(arr, element_num, element, position, total_size);
                display(arr, element_num);
            }
            else
            {
            jump3:
                NONsorted_insertion(arr, element_num, element, position, total_size);
                display(arr, element_num);
            }
        }
        else
        {
            exit(0);
        }
    } while (dession_element == 'y');
    display(arr, element_num);
    return 0;
}