// implementation of Queue using array
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n=5,Queue[n];
    int rear = -1, front = -1;
    int item, dequeue, i,a;

    do
    {
        printf("Enter your choice:\n");
        scanf("%d", &a);
        switch (a)
        {
            case 1:
                if (rear == n - 1)
                    printf("Queue is full\n");
                else
                {
                    printf("Item to be enqueued: ");
                    scanf("%d", &item);
                    if (front == -1)
                        front = 0;
                    rear++;
                    Queue[rear] = item;
                }
                break;
            case 2:
                if (front == -1 || front > rear)
                    printf("Queue is empty\n");
                else
                {
                    dequeue = Queue[front];
                    printf("Dequeued item: %d\n", dequeue);
                    front++;
                    if (front > rear)
                    {
                        front = rear = -1;
                    }
                }
                break;
            case 3:
            if (front == -1)
            printf("Queue is empty\n");
        else
        {
            printf("The values in the queue are:\n");
            for (i = front; i <= rear; i++)
            {
                printf("%d ", Queue[i]);
            }
            printf("\n");
        }
        break;
    case 4:
        printf("Exit\n");
        return 0;
    default:
        printf("Invalid choice\n");
    }
} while (1);

return 0;
}