// implementation of queue
#include<stdio.h>
#include<stdlib.h>
//#include <conio.h>
int main()
{
    int n = 5,queue[n];
    int rear = -1, front = -1, a;
    int item, dequeue, i;
    //clrscr();
    do
    {
        printf("Enter your choice:\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            if (rear == n-1)
                printf("queue is full\n");
            else if (rear == 0 && front == 0)
                

            
            else
            {
                printf("item to be enqueued\n");
                scanf("%d", &item);
                Q[rear] = item;
            }
            break;
        case 2:
            if (front == 0)
                printf("queue is empty\n");
            else
                dequeue = Q[front];
            if (front == rear)
            {
                rear = 0;
                front = 0;
            }
            else
                front++;
            break;
        case 3:
            for (i = 0; i <= rear; i++)
            {
                printf("the values in queue are %d:\n", Q[i]);
            }
            break;
        case 4:
            printf("exit\n");
            return 0;
        default:
            printf("invalid\n");
        }
    } while (1);
   // getch();
    return 0;
}
