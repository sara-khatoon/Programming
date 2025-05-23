#include <stdio.h>

int main()
{
    int arr[5]; // = {12, 31, 96, 61, 55};
    int i, j, temp;
    int size = 5; // Added a variable for array size

    printf("*Bubble Sort*\n");
    printf("Before sorting:\n");
    for (i = 0; i < size; i++)
    {   scanf("%d", &arr[i]); // Input array elementss
    } 

    // Bubble Sort Logic
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nAfter sorting:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}