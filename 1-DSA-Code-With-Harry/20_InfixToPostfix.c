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
int isoperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int presidence(char c)
{
    if (c == '*' || c == '/')
    {
        return 3;
    }
    else if (c == '+' || c == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
char *InfixToPostfix(char infix[])
{
    struct stack obj;
    obj.size = strlen(infix);
    obj.top = -1;
    obj.arr = malloc(obj.size * sizeof(char));
    char *postfix = malloc((obj.size + 1) * sizeof(char));
    int i = 0, j = 0;
    while (infix[i] != 0)
    {
        if (!isoperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (presidence(infix[i]) > presidence(stackTop(obj)))
            {
                push(&obj, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(&obj);
                j++;
            }
        }
    }
    while (!isEmpty(obj))
    {
        postfix[j] = pop(&obj);
        j++;
    }
    postfix[j] = 0;

    return postfix;
}
int main()
{
    char infix[50];
    printf("Enter your expression: \n");
    gets(infix);
    char *postfix = InfixToPostfix(infix);
    puts(postfix);
    return 0;
}