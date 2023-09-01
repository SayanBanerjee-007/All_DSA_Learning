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
int deletion(int *arr, int element_num, int element, int position)
{
    
    if (element_num < position)
    {
        printf("sorry!! YOUR REQUEST CANNOT BE ACCOMPLISHED.\n");
        exit(0);
    }
    for (int i = position; i <= element_num - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    return 1;
}

int main()
{
    int total_size, element_num, element, position;
    char dession_element;
    printf("Enter the size of array: ");
    scanf("%d", &total_size);
    int *arr = calloc(total_size, sizeof(int));
    element_num = creat_array(arr);
    display(arr, element_num);
    do
    {
        printf("Do you want to delete any element ?(y or n) -> ");
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
            printf("Enter the element position-> ");
            scanf("%d", &position);
            deletion(arr, element_num, element, position);
            element_num--;
            display(arr, element_num);
        }
        else
        {
            exit(0);
        }
    } while (dession_element == 'y');
    display(arr, element_num);
    return 0;
}