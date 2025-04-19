// program to implement stack using array dynamically
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
    int n = 10;
    int *stack;
    int *popstack;
    int top = -1;
    int pop = -1;
    int i, a, *popvalue;
    int item;
    stack = (int *)malloc(n * sizeof(int));
    popstack = (int *)malloc(n * sizeof(int));
    clrscr();
    do
    {
        printf("Enter your choice:\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            if (top > 10)
                printf("Stack is full\n");
            else
            {
                top = top + 1;
                printf("Item to be pushed in the stack:\n");
                scanf("%d", &item);
                stack[top] = item;
            }
            break;
        case 2:
            if (top < 1)
                printf("Stack is empty\n");
            else
            {
                *popvalue = stack[top];
                top--;
                pop++;
                popstack[pop] = *popvalue;
            }
            break;
        case 3:
            if (top < 0)
                printf("Stack is empty\n");
            else if (top >= 10)
                printf("Stack is full\n");
            else
            {
                for (i = 0; i <= pop; i++)
                {
                    printf("Popped values are %d\n", popstack[i]);
                }
                printf("The element at top is %d\n", stack[top]);
            }
            break;
        case 4:
            printf("Exit\n");
            return 0;
        default:
            printf("invalid\n");
        }
    } while (1);
}
