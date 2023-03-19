#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct stack obj)
{
    if (obj.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack obj)
{
    if (obj.size - 1 == obj.top)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *obj, char val)
{
    if (isFull((*obj)))
    {
        printf("Stack overflow.\n");
    }
    else
    {
        obj->top++;
        obj->arr[obj->top] = val;
    }
}
char pop(struct stack *obj)
{
    char val;
    if (isEmpty(*obj))
    {
        printf("Stack underflow.\n");
        return 0;
    }
    else
    {
        val = obj->arr[obj->top];
        obj->top--;
        return val;
    }
}
char stackTop(struct stack obj)
{
    return obj.arr[obj.top];
}
int match(char pushchar, char popchar)
{
    if (pushchar == popchar)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int MultipleParenthisisMatching(struct stack *obj, char arr[], int len)
{
    int i = 0;
    while (i < len)
    {
        if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[')
        {
            push(&(*obj), arr[i]);
        }
        else if (arr[i] == ')' || arr[i] == '}' || arr[i] == ']')
        {
            if (isEmpty(*obj))
            {
                return 0;
            }
            char popchar = pop(&(*obj));
            if (!match(stackTop(*obj), popchar))
            {
                return 0;
            }
            pop(&(*obj));
        }

        i++;
    }
    return isEmpty(*obj);
}
int main()
{
    int len;
    char arr[50];
    printf("Enter your expression:\n");
    gets(arr);
    len = strlen(arr);
    struct stack obj;
    obj.size = len;
    obj.top = -1;
    obj.arr = malloc(obj.size * sizeof(char));

    if (MultipleParenthisisMatching(&obj, arr, len))
    {
        printf("Equal number of Parenthisis.\n");
    }
    else
    {
        printf("Not equal number of Parenthisis.\n");
    }

    return 0;
}