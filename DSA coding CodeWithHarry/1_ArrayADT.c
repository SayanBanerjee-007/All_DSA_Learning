#include <stdio.h>
#include <stdlib.h>

typedef struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
} myArray;
void CreateArray(myArray *a, int Tsize, int Usize)
{
    a->total_size = Tsize;
    a->used_size = Usize;
    a->ptr = malloc(Usize * sizeof(int));
}
void set_value(myArray* a)
{
    for(int i=0;i<(a->used_size);i++)
    {
        printf("Enter element No.%d ->",i+1);
        scanf("%d",&(*a).ptr[i]);
    }
}
void display_value(myArray* a)
{
    for(int i=0;i<(a->used_size);i++)
    {
        printf("Element No.%d is: %d\n",i+1,(a->ptr)[i]);
    }
    free(a->ptr);
}
int main()
{
    myArray marks;
    CreateArray(&marks, 10, 2);
    set_value(&marks);
    display_value(&marks);

    return 0;
}